#include "waveform.h"
#include "mcc_generated_files/mcc.h"
#include "sine1k.h"
#include <xc.h>

static volatile uint16_t rampRatePos;
static volatile uint16_t rampRateNeg;

static volatile uint16_t startValue;
static volatile uint16_t endValue;

static volatile _WaveformISR waveFunc;

void initWaveformControl(WAVEFORM_OUTPUT funcSel)
{
    //Rate of change for rising edge of sawtooth and triangle
    rampRatePos = INIT_RATE_OF_CHANGE_POS;
    
    //Rate of change for falling edge of triangle
    rampRateNeg = INIT_RATE_OF_CHANGE_NEG;
    
    //Init to MIN output
    startValue = INIT_MINIMUM_OUTPUT;
    
    //Init to MAX output
    endValue = INIT_MAXIMUM_OUTPUT;
    
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

uint16_t __updateWaveformTriangleRising(uint16_t value)
{
    //Update the DAC value
    value += rampRatePos;
    
    if (value >= endValue)
    {
        //Value will overflow, reset to "start"
        value = endValue;
        
        //Swap to the other function
        waveFunc = &__updateWaveformTriangleFalling;
    }
    
    return value;
}

uint16_t __updateWaveformTriangleFalling(uint16_t value)
{    
    //Update the DAC value
    value -= rampRateNeg;
    
    if (value <= startValue)
    {
        //Value will overflow, reset to "start"        
        value = startValue; //startValue;
        
        //Swap to the other function
        waveFunc = &__updateWaveformTriangleRising;
    }
    
    return value;
}

uint16_t __updateWaveformSawtooth(uint16_t value)
{
    //Update the DAC value
    value += rampRatePos;
    
    if (value > endValue)
    {
        //Value will overflow, reset to "start"
        value = startValue;
    }
    
    return value;
}

uint16_t __updateWaveformSine1k(uint16_t DACvalue)
{
    static volatile uint16_t index = 0;
    
    if (index == sineLength)
    {
        index = 0;
    }
    uint16_t value = sine1kTable[index];
    index++;
    
    return value;
}