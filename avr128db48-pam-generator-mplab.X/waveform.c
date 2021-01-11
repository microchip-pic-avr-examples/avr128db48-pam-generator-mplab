#include "waveform.h"
#include "mcc_generated_files/mcc.h"
#include "sine1k.h"
#include <xc.h>

static volatile uint16_t rampRatePos;
static volatile uint16_t rampRateNeg;

static volatile uint16_t minValue;
static volatile uint16_t maxValue;

static volatile _WaveformISR waveFunc;
static volatile uint8_t index;


void initWaveformControl(WAVEFORM_OUTPUT funcSel)
{
    //Rate of change for rising edge of sawtooth and triangle
    rampRatePos = INIT_RATE_OF_CHANGE_POS;
    
    //Rate of change for falling edge of triangle
    rampRateNeg = INIT_RATE_OF_CHANGE_NEG;
    
    //Init to MIN output
    minValue = INIT_MINIMUM_OUTPUT;
    
    //Init to MAX output
    maxValue = INIT_MAXIMUM_OUTPUT;
    
    //Init Index to 0
    index = 0;
    
    //Lookup Table for Initialization
    switch (funcSel)
    {
        case TRIANGLE_RISING:
            waveFunc = &__updateWaveformTriangleRising;
            break;
        case TRIANGLE_FALLING:
            waveFunc = &__updateWaveformTriangleFalling;
            break;
        case SAWTOOTH:
            waveFunc = &__updateWaveformSawtooth;
            break;
        case SINE_1K:
            waveFunc = &__updateWaveformSine1k;
            break;
        case DC:
        case EXT_FUNC:  //External Function must be assigned later
        default:
            waveFunc = NULL;
    }
        
    //Init the Starting DAC Output
    DAC0_SetOutput(INIT_DAC_OUTPUT);
}

void setWaveformFunction(_WaveformISR func)
{
    waveFunc = func;
}

void __ISR__UpdateDAC(void)
{
    //If no function assigned, then return
    if (waveFunc == NULL)
        return;
    
    //Call the waveform function and pass the current DAC value
    
    uint16_t data = waveFunc((DAC0.DATA >> DAC_DATA_gp));
    
    
    //Change the Value
    DAC0_SetOutput(data);
}

void setMinimumOutputLevel(uint16_t level)
{
    minValue = level;
}

void setMaximumOutputLevel(uint16_t level)
{
    maxValue = level;
}

uint16_t getMinimumOutputLevel(void)
{
    return minValue;
}

uint16_t getMaximumOutputLevel(void)
{
    return maxValue;
}

void setRisingROC(uint16_t rate)
{
    rampRatePos = rate;
}

void setFallingROC(uint16_t rate)
{
    rampRateNeg = rate;
}

uint16_t __updateWaveformTriangleRising(uint16_t DACvalue)
{
    //Update the DAC value
    DACvalue += rampRatePos;
    
    if (DACvalue >= maxValue)
    {
        //Value will overflow, reset to "start"
        DACvalue = maxValue;
        
        //Swap to the other function
        waveFunc = &__updateWaveformTriangleFalling;
    }
    
    return DACvalue;
}

uint16_t __updateWaveformTriangleFalling(uint16_t DACvalue)
{    
    //Update the DAC value
    DACvalue -= rampRateNeg;
    
    if (DACvalue <= minValue)
    {
        //Value will overflow, reset to "start"        
        DACvalue = minValue; //startValue;
        
        //Swap to the other function
        waveFunc = &__updateWaveformTriangleRising;
    }
    
    return DACvalue;
}

uint16_t __updateWaveformSawtooth(uint16_t DACvalue)
{
    //Update the DAC value
    DACvalue += rampRatePos;
    
    if (DACvalue > maxValue)
    {
        //Value will overflow, reset to "start"
        DACvalue = minValue;
    }
    
    return DACvalue;
}

uint16_t __updateWaveformSine1k(uint16_t DACvalue)
{
    //If at the end of the sine table, reset to the start
    if (index == sineLength)
    {
        index = 0;
    }
    
    //Get the value at the sine table
    uint16_t value = sine1kTable[index];
    
    //Move to the next value
    index++;
    
    return value;
}