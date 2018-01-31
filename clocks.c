#include  "msp430.h"
#include  "functions.h"
#include "macros.h"

//MACROS========================================================================
#define FLLN_BITS          (0x03ffu)
#define FLLN_255           (0x00ffu)
#define CSLOCK                  (0x01) // Any incorrect password locks registers

// Port J Pins


#define XINR                 (0x10) // XINR
#define XOUTR                (0x20) // XOUTR
#define CLEAR_REGISTER     (0X0000)
#define CHIPSELECTREG        (0x00) // Chip select register

void Init_Clocks(void);

void Init_Clocks(void){
//------------------------------------------------------------------------------
// Clock Configurtaions
// This is the clock initialization for the program.
//
// Initial clock configuration, runs immediately after boot.
// Disables 1ms watchdog timer,
//      configure MCLK to 8MHz
//      configure SMCLK to 8MHz.
// Since the X1 oscillator is not currently connected,
// X1CLK is an unknown speed (probably ~10kHz).
//------------------------------------------------------------------------------
  WDTCTL = WDTPW | WDTHOLD;  // Disable watchdog
//  PJSEL0 |= XINR;
//  PJSEL0 |= XOUTR;

// Clocks:
// Clock System Control 0 Register
  CSCTL0 = CSKEY;            // Unlock register

// Clock System Control 1 Register
  CSCTL1 = CLEAR_REGISTER;   // Clear register
  CSCTL1 = DCOFSEL_6;        // Set DCO setting for 8MHz
//  CSCTL1 &= ~DCORSEL;        // DCO range select. For high-speed devices,
                             // this bit can be written by the user.
                             // For low-speed devices, it is always reset.

// Clock System Control 2 Register
  CSCTL2 = CLEAR_REGISTER;   // Clear register
  CSCTL2 |= SELA__LFXTCLK;
  CSCTL2 |= SELS__DCOCLK;
  CSCTL2 |= SELM__DCOCLK;

// Clock System Control 3 Register
  CSCTL3 = CLEAR_REGISTER;   // Clear register
  CSCTL3 |= DIVA__1;         // set ACLK clock divider /1
  CSCTL3 |= DIVS__1;         // set SMCLK clock divider /1
  CSCTL3 |= DIVM__1;         // set MCLK clock divider /1

// Clock System Control 4 Register
//  CSCTL4 = CLEAR_REGISTER;   // Clear register
  CSCTL4 &= ~LFXTOFF;        // Enable LFXT1

  do
  {
    CSCTL5 &= ~LFXTOFFG;     // Clear XT1 fault flag
    SFRIFG1 &= ~OFIFG;
  } while (SFRIFG1 & OFIFG); // Test oscillator fault flag

//  CSCTL0 = CSLOCK;           // Lock registers
  CSCTL0_H = CHIPSELECTREG;    // Lock CS registers


//  CSCTL4 &= ~XT1OFF;         // XT1 is on if XT1 is selected by the port selection and XT1 is not in bypass
//  CSCTL4 &= ~SMCLKOFF;       // SMCLK is not Off
//  CSCTL4 &= ~XT1BYPASS;      // XT1 sourced from external crystal
//  CSCTL4 &= ~XTS;            // Low-frequency mode
//  CSCTL4 |= XT1DRIVE_0;      // Lowest current consumption for XT1 LF mode.
                             // XT1 oscillator operating range in HF mode is 4 MHz to 8 MHz.
//  CSCTL4 |= XT2OFF;          // High Frequency Oscillator 2 (XT2) disable

//------------------------------------------------------------------------------
}


