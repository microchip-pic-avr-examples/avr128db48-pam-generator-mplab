#ifndef WAVEFORM_H
#define	WAVEFORM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <ctype.h>
#include <xc.h>
    
//Lowest Output Code allowed for the DAC (before right shifting).
//Approx 1.8V with 5V VDD
#define INIT_MINIMUM_OUTPUT 369  
    
//Maximum Output Code allowed for the DAC (before right shifting)
#define INIT_MAXIMUM_OUTPUT 0x3FF

//Rate of change for the rising edge of the triangle / sawtooth waveforms
#define INIT_RATE_OF_CHANGE_POS 10
    
//Rate of change for the falling edge of the triangle waveforms.
//(Note: Unsigned value)
#define INIT_RATE_OF_CHANGE_NEG 10
    
//Set the Initial Level of the DAC
//This can be used to create a phase-shift in the waveforms
#define INIT_DAC_OUTPUT 0 
    
    typedef enum {
        DC = 0, EXT_FUNC, TRIANGLE_RISING, TRIANGLE_FALLING, SAWTOOTH, SINE_10K, EEPROM
    } WAVEFORM_OUTPUT;
    
    //Waveform Function Pointer
    typedef uint16_t(*_WaveformISR)(uint16_t);
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> initWaveformControl(<FONT COLOR=BLUE>void</FONT>)</B>
     * @param funcSel (WAVEFORM_OUTPUT) - Selects the waveform to generate
     * 
     * This function initializes the constants required to use the DAC to 
     * synthesize the output.
     *  */
    void initWaveformControl(WAVEFORM_OUTPUT funcSel);
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> setWaveformFunction(<FONT COLOR=BLUE>void</FONT>)</B>
     * @param func (_WaveformISR) - Selects the waveform to generate
     * 
     * This function lets developers change the waveform function - 
     * you can pass the pre-defined functions in this header, or you can reference
     * a custom function somewhere else.
     *  */
    void setWaveformFunction(_WaveformISR func);
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> __ISR__UpdateDAC(<FONT COLOR=BLUE>void</FONT>)</B>
     * 
     * This function is called by the rollover of TCB to update the DAC Output.
     *  */
    void __ISR__UpdateDAC(void);

    /** 
     * <B><FONT COLOR=BLUE>uint16_t</FONT> __updateWaveformTriangleRising(<FONT COLOR=BLUE>void</FONT>)</B>
     * @param DACvalue (uint16_t) - Current value in the DAC
     * 
     * This function is internally called by the ISR to update the DAC to generate
     * the rising edge of the triangle waveform.
     *  */
    uint16_t __updateWaveformTriangleRising(uint16_t DACvalue);
    
    /** 
     * <B><FONT COLOR=BLUE>uint16_t</FONT> __updateWaveformTriangleFalling(<FONT COLOR=BLUE>void</FONT>)</B>
     * @param DACvalue (uint16_t) - Current value in the DAC
     * 
     * This function is internally called by the ISR to update the DAC to generate
     * the falling edge of the triangle waveform.
     *  */
    uint16_t __updateWaveformTriangleFalling(uint16_t DACvalue);
    
    /** 
     * <B><FONT COLOR=BLUE>uint16_t</FONT> __updateWaveformSawtooth(<FONT COLOR=BLUE>void</FONT>)</B>
     * @param DACvalue (uint16_t) - Current value in the DAC
     * 
     * This function is internally called by the ISR to update the DAC to generate
     * a sawtooth waveform.
     *  */
    uint16_t __updateWaveformSawtooth(uint16_t DACvalue);

#ifdef	__cplusplus
}
#endif

#endif	/* WAVEFORM_H */

