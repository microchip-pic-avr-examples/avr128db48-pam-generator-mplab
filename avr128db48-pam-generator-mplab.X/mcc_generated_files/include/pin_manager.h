/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "port.h"

//get/set PA2 aliases
#define PA2_SetHigh() do { PORTA_OUTSET = 0x4; } while(0)
#define PA2_SetLow() do { PORTA_OUTCLR = 0x4; } while(0)
#define PA2_Toggle() do { PORTA_OUTTGL = 0x4; } while(0)
#define PA2_GetValue() (VPORTA.IN & (0x1 << 2))
#define PA2_SetDigitalInput() do { PORTA_DIRCLR = 0x4; } while(0)
#define PA2_SetDigitalOutput() do { PORTA_DIRSET = 0x4; } while(0)
#define PA2_SetPullUp() do { PORTA_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA2_ResetPullUp() do { PORTA_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA2_SetInverted() do { PORTA_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define PA2_ResetInverted() do { PORTA_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA2_DisableInterruptOnChange() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA2_EnableInterruptForBothEdges() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA2_EnableInterruptForRisingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA2_EnableInterruptForFallingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA2_DisableDigitalInputBuffer() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA2_EnableInterruptForLowLevelSensing() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PB3 aliases
#define PB3_SetHigh() do { PORTB_OUTSET = 0x8; } while(0)
#define PB3_SetLow() do { PORTB_OUTCLR = 0x8; } while(0)
#define PB3_Toggle() do { PORTB_OUTTGL = 0x8; } while(0)
#define PB3_GetValue() (VPORTB.IN & (0x1 << 3))
#define PB3_SetDigitalInput() do { PORTB_DIRCLR = 0x8; } while(0)
#define PB3_SetDigitalOutput() do { PORTB_DIRSET = 0x8; } while(0)
#define PB3_SetPullUp() do { PORTB_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PB3_ResetPullUp() do { PORTB_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PB3_SetInverted() do { PORTB_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define PB3_ResetInverted() do { PORTB_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PB3_DisableInterruptOnChange() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PB3_EnableInterruptForBothEdges() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PB3_EnableInterruptForRisingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PB3_EnableInterruptForFallingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PB3_DisableDigitalInputBuffer() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PB3_EnableInterruptForLowLevelSensing() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PC3 aliases
#define PC3_SetHigh() do { PORTC_OUTSET = 0x8; } while(0)
#define PC3_SetLow() do { PORTC_OUTCLR = 0x8; } while(0)
#define PC3_Toggle() do { PORTC_OUTTGL = 0x8; } while(0)
#define PC3_GetValue() (VPORTC.IN & (0x1 << 3))
#define PC3_SetDigitalInput() do { PORTC_DIRCLR = 0x8; } while(0)
#define PC3_SetDigitalOutput() do { PORTC_DIRSET = 0x8; } while(0)
#define PC3_SetPullUp() do { PORTC_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PC3_ResetPullUp() do { PORTC_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PC3_SetInverted() do { PORTC_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define PC3_ResetInverted() do { PORTC_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PC3_DisableInterruptOnChange() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PC3_EnableInterruptForBothEdges() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PC3_EnableInterruptForRisingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PC3_EnableInterruptForFallingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PC3_DisableDigitalInputBuffer() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PC3_EnableInterruptForLowLevelSensing() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set ISR_PULSE aliases
#define ISR_PULSE_SetHigh() do { PORTB_OUTSET = 0x20; } while(0)
#define ISR_PULSE_SetLow() do { PORTB_OUTCLR = 0x20; } while(0)
#define ISR_PULSE_Toggle() do { PORTB_OUTTGL = 0x20; } while(0)
#define ISR_PULSE_GetValue() (VPORTB.IN & (0x1 << 5))
#define ISR_PULSE_SetDigitalInput() do { PORTB_DIRCLR = 0x20; } while(0)
#define ISR_PULSE_SetDigitalOutput() do { PORTB_DIRSET = 0x20; } while(0)
#define ISR_PULSE_SetPullUp() do { PORTB_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define ISR_PULSE_ResetPullUp() do { PORTB_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define ISR_PULSE_SetInverted() do { PORTB_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define ISR_PULSE_ResetInverted() do { PORTB_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define ISR_PULSE_DisableInterruptOnChange() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define ISR_PULSE_EnableInterruptForBothEdges() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define ISR_PULSE_EnableInterruptForRisingEdge() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define ISR_PULSE_EnableInterruptForFallingEdge() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define ISR_PULSE_DisableDigitalInputBuffer() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define ISR_PULSE_EnableInterruptForLowLevelSensing() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA4 aliases
#define PA4_SetHigh() do { PORTA_OUTSET = 0x10; } while(0)
#define PA4_SetLow() do { PORTA_OUTCLR = 0x10; } while(0)
#define PA4_Toggle() do { PORTA_OUTTGL = 0x10; } while(0)
#define PA4_GetValue() (VPORTA.IN & (0x1 << 4))
#define PA4_SetDigitalInput() do { PORTA_DIRCLR = 0x10; } while(0)
#define PA4_SetDigitalOutput() do { PORTA_DIRSET = 0x10; } while(0)
#define PA4_SetPullUp() do { PORTA_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA4_ResetPullUp() do { PORTA_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA4_SetInverted() do { PORTA_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define PA4_ResetInverted() do { PORTA_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA4_DisableInterruptOnChange() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA4_EnableInterruptForBothEdges() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA4_EnableInterruptForRisingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA4_EnableInterruptForFallingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA4_DisableDigitalInputBuffer() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA4_EnableInterruptForLowLevelSensing() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA3 aliases
#define PA3_SetHigh() do { PORTA_OUTSET = 0x8; } while(0)
#define PA3_SetLow() do { PORTA_OUTCLR = 0x8; } while(0)
#define PA3_Toggle() do { PORTA_OUTTGL = 0x8; } while(0)
#define PA3_GetValue() (VPORTA.IN & (0x1 << 3))
#define PA3_SetDigitalInput() do { PORTA_DIRCLR = 0x8; } while(0)
#define PA3_SetDigitalOutput() do { PORTA_DIRSET = 0x8; } while(0)
#define PA3_SetPullUp() do { PORTA_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA3_ResetPullUp() do { PORTA_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA3_SetInverted() do { PORTA_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define PA3_ResetInverted() do { PORTA_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA3_DisableInterruptOnChange() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA3_EnableInterruptForBothEdges() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA3_EnableInterruptForRisingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA3_EnableInterruptForFallingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA3_DisableDigitalInputBuffer() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA3_EnableInterruptForLowLevelSensing() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PD6 aliases
#define PD6_SetHigh() do { PORTD_OUTSET = 0x40; } while(0)
#define PD6_SetLow() do { PORTD_OUTCLR = 0x40; } while(0)
#define PD6_Toggle() do { PORTD_OUTTGL = 0x40; } while(0)
#define PD6_GetValue() (VPORTD.IN & (0x1 << 6))
#define PD6_SetDigitalInput() do { PORTD_DIRCLR = 0x40; } while(0)
#define PD6_SetDigitalOutput() do { PORTD_DIRSET = 0x40; } while(0)
#define PD6_SetPullUp() do { PORTD_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PD6_ResetPullUp() do { PORTD_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PD6_SetInverted() do { PORTD_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define PD6_ResetInverted() do { PORTD_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PD6_DisableInterruptOnChange() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PD6_EnableInterruptForBothEdges() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PD6_EnableInterruptForRisingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PD6_EnableInterruptForFallingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PD6_DisableDigitalInputBuffer() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PD6_EnableInterruptForLowLevelSensing() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA6 aliases
#define PA6_SetHigh() do { PORTA_OUTSET = 0x40; } while(0)
#define PA6_SetLow() do { PORTA_OUTCLR = 0x40; } while(0)
#define PA6_Toggle() do { PORTA_OUTTGL = 0x40; } while(0)
#define PA6_GetValue() (VPORTA.IN & (0x1 << 6))
#define PA6_SetDigitalInput() do { PORTA_DIRCLR = 0x40; } while(0)
#define PA6_SetDigitalOutput() do { PORTA_DIRSET = 0x40; } while(0)
#define PA6_SetPullUp() do { PORTA_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA6_ResetPullUp() do { PORTA_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA6_SetInverted() do { PORTA_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define PA6_ResetInverted() do { PORTA_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA6_DisableInterruptOnChange() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA6_EnableInterruptForBothEdges() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA6_EnableInterruptForRisingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA6_EnableInterruptForFallingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA6_DisableDigitalInputBuffer() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA6_EnableInterruptForLowLevelSensing() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA5 aliases
#define PA5_SetHigh() do { PORTA_OUTSET = 0x20; } while(0)
#define PA5_SetLow() do { PORTA_OUTCLR = 0x20; } while(0)
#define PA5_Toggle() do { PORTA_OUTTGL = 0x20; } while(0)
#define PA5_GetValue() (VPORTA.IN & (0x1 << 5))
#define PA5_SetDigitalInput() do { PORTA_DIRCLR = 0x20; } while(0)
#define PA5_SetDigitalOutput() do { PORTA_DIRSET = 0x20; } while(0)
#define PA5_SetPullUp() do { PORTA_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA5_ResetPullUp() do { PORTA_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA5_SetInverted() do { PORTA_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define PA5_ResetInverted() do { PORTA_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA5_DisableInterruptOnChange() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA5_EnableInterruptForBothEdges() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA5_EnableInterruptForRisingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA5_EnableInterruptForFallingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA5_DisableDigitalInputBuffer() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA5_EnableInterruptForLowLevelSensing() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA7 aliases
#define PA7_SetHigh() do { PORTA_OUTSET = 0x80; } while(0)
#define PA7_SetLow() do { PORTA_OUTCLR = 0x80; } while(0)
#define PA7_Toggle() do { PORTA_OUTTGL = 0x80; } while(0)
#define PA7_GetValue() (VPORTA.IN & (0x1 << 7))
#define PA7_SetDigitalInput() do { PORTA_DIRCLR = 0x80; } while(0)
#define PA7_SetDigitalOutput() do { PORTA_DIRSET = 0x80; } while(0)
#define PA7_SetPullUp() do { PORTA_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA7_ResetPullUp() do { PORTA_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA7_SetInverted() do { PORTA_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define PA7_ResetInverted() do { PORTA_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA7_DisableInterruptOnChange() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA7_EnableInterruptForBothEdges() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA7_EnableInterruptForRisingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA7_EnableInterruptForFallingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA7_DisableDigitalInputBuffer() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA7_EnableInterruptForLowLevelSensing() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PD3 aliases
#define PD3_SetHigh() do { PORTD_OUTSET = 0x8; } while(0)
#define PD3_SetLow() do { PORTD_OUTCLR = 0x8; } while(0)
#define PD3_Toggle() do { PORTD_OUTTGL = 0x8; } while(0)
#define PD3_GetValue() (VPORTD.IN & (0x1 << 3))
#define PD3_SetDigitalInput() do { PORTD_DIRCLR = 0x8; } while(0)
#define PD3_SetDigitalOutput() do { PORTD_DIRSET = 0x8; } while(0)
#define PD3_SetPullUp() do { PORTD_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PD3_ResetPullUp() do { PORTD_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PD3_SetInverted() do { PORTD_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define PD3_ResetInverted() do { PORTD_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PD3_DisableInterruptOnChange() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PD3_EnableInterruptForBothEdges() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PD3_EnableInterruptForRisingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PD3_EnableInterruptForFallingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PD3_DisableDigitalInputBuffer() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PD3_EnableInterruptForLowLevelSensing() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PD2 aliases
#define PD2_SetHigh() do { PORTD_OUTSET = 0x4; } while(0)
#define PD2_SetLow() do { PORTD_OUTCLR = 0x4; } while(0)
#define PD2_Toggle() do { PORTD_OUTTGL = 0x4; } while(0)
#define PD2_GetValue() (VPORTD.IN & (0x1 << 2))
#define PD2_SetDigitalInput() do { PORTD_DIRCLR = 0x4; } while(0)
#define PD2_SetDigitalOutput() do { PORTD_DIRSET = 0x4; } while(0)
#define PD2_SetPullUp() do { PORTD_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PD2_ResetPullUp() do { PORTD_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PD2_SetInverted() do { PORTD_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define PD2_ResetInverted() do { PORTD_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PD2_DisableInterruptOnChange() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PD2_EnableInterruptForBothEdges() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PD2_EnableInterruptForRisingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PD2_EnableInterruptForFallingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PD2_DisableDigitalInputBuffer() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PD2_EnableInterruptForLowLevelSensing() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

void PIN_MANAGER_Initialize();
void PORTA_PA2_DefaultInterruptHandler(void);
void PORTA_PA2_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_PB3_DefaultInterruptHandler(void);
void PORTB_PB3_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_PC3_DefaultInterruptHandler(void);
void PORTC_PC3_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_ISR_PULSE_DefaultInterruptHandler(void);
void PORTB_ISR_PULSE_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA4_DefaultInterruptHandler(void);
void PORTA_PA4_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA3_DefaultInterruptHandler(void);
void PORTA_PA3_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_PD6_DefaultInterruptHandler(void);
void PORTD_PD6_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA6_DefaultInterruptHandler(void);
void PORTA_PA6_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA5_DefaultInterruptHandler(void);
void PORTA_PA5_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA7_DefaultInterruptHandler(void);
void PORTA_PA7_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_PD3_DefaultInterruptHandler(void);
void PORTD_PD3_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_PD2_DefaultInterruptHandler(void);
void PORTD_PD2_SetInterruptHandler(void (* interruptHandler)(void)) ;
#endif /* PINS_H_INCLUDED */
