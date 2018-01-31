#include  "msp430.h"
#include  "functions.h"
#include "macros.h"

void Init_Ports(void){
  Init_Port_1();
  Init_Port_2();
  Init_Port_3(USE_L_REVERSE);
  Init_Port_4();
  Init_Port_5();
  Init_Port_6();
  Init_Port_7();
  Init_Port_8();
  Init_Port_J();
}

//Initialize port 1
/*
Port 1:
  Pin 0: Red LED
  Pin 1: Green LED
  Pin 2: Unused
  Pin 3: Unused
  Pin 4: Unused
  Pin 5: Unused
  Pin 6: MOSI for USB0
  Pin 7: MISO for USB0
*/
void Init_Port_1(void){
  //P1_0
  P1SEL0 &= ~RED_LED;           //RED_LED as GP I/O
  P1SEL1 &= ~RED_LED;           //RED_LED as GP I/O
  P1OUT &= ~RED_LED;            //Set Red LED off
  P1DIR |= RED_LED;             //Set Red LED direction to output
  //P1_1
  P1SEL0 &= ~GRN_LED;           //GRN_LED as GP I/O
  P1SEL1 &= ~GRN_LED;           //GRN_LED as GP I/O
  P1OUT &= ~GRN_LED;             //Set Green LED off
  P1DIR |= GRN_LED;             //Set Green LED direction to output
  //P1_2
  P1SEL0 |= V_THUMB;            //ADC input for ThumbWheel
  P1SEL1 |= V_THUMB;            //ADC input for ThumbWheel
  //P1_3
  P1SEL0 &= ~TEST_PROBE;        //TEST_PROBE as GP I/O
  P1SEL1 &= ~TEST_PROBE;        //TEST_PROBE as GP I/O
  P1OUT &= ~TEST_PROBE;         //Set TEST_PROBE Off
  P1DIR |= TEST_PROBE;          //Set TEST_PROBE direction to output
  //P1_4
  P1SEL0 |= V_DETECT_R;         //ADC input for Right Detector
  P1SEL1 |= V_DETECT_R;         //ACD input for Right Detector
  //P1_5
  P1SEL0 |= V_DETECT_L;         //ADC input for Left Detector
  P1SEL1 |= V_DETECT_L;         //ACD input for Left Detector
  //P1_6
  P1SEL0 &= ~SD_UCB0SIMO;       //UCB0 MOSI pin
  P1SEL1 |= SD_UCB0SIMO;        //UCB0 MOSI pin
  //P1_7
  P1SEL0 &= ~SD_UCB0SOMI;       //USCI_B1 MISO pin
  P1SEL1 |= SD_UCB0SOMI;        //USCI_B1 MISO pin
}

//Initialize port 2
/*
Port 2:
  Pin 0: TX for UCA0
  Pin 1: RX for UCA0
  Pin 2: CLK for UCB0
  Pin 3: Not used
  Pin 4: Not used
  Pin 5: TX for UCA1
  Pin 6: RX for UCA1
  Pin 7: Not used
*/
void Init_Port_2(void){
  //P2_0
  P2SEL0 |= UCA0TXD;            //P2_0 as UCA0 transmitting
  P2SEL1 &= ~UCA0TXD;           //P2_0 as UCA0 transmitting
  //P2_1
  P2SEL0 |= UCA0RXD;            //P2_1 as UCA0 receiving
  P2SEL1 &= ~UCA0RXD;           //P2_1 as UCA0 receiving
  //P2_2
  P2SEL0 |= UCB0CLK;            //P2_2 as USB0 clock
  P2SEL1 &= ~UCB0CLK;           //P2_2 as USB0 clock
  //P2_3
  P2SEL0 &= ~P2_3;              //Unused
  P2SEL1 &= ~P2_3;              //Unused
  P2DIR &= ~P2_3;               //Unused
  //P2_4
  P2SEL0 &= ~P2_4;              //Unused
  P2SEL1 &= ~P2_4;              //Unused
  P2DIR &= ~P2_4;               //Unused
  //P2_5
  P2SEL0 |= UCA1TXD;            //P2_5 as UCA1 transmitting
  P2SEL0 &= ~UCA1TXD;           //P2_5 as UCA1 transmitting
  //P2_6
  P2SEL0 |= UCA1RXD;            //P2_5 as UCA1 receiving
  P2SEL0 &= ~UCA1RXD;           //P2_5 as UCA1 receiving
  //P2_7
  P2SEL0 &= ~P2_7;              //Unused
  P2SEL1 &= ~P2_7;              //Unused
  P2DIR &= ~P2_7;               //Unused
}

//Initialize port 3
/*
Port 3:
  Pin 0: IOT reset
  Pin 1: IOT STA miniap
  Pin 2: IOT wakeup
  Pin 3: IOT factory
  Pin 4: Left motor reverse
  Pin 5: Left motor forward
  Pin 6: Right motor reverse
  Pin 7: Right motor forward
*/
void Init_Port_3(int choice){
  //P3_0
  P3SEL0 &= ~IOT_RESET;         //IOT reset
  P3SEL1 &= ~IOT_RESET;         //IOT reset
  P3OUT &= ~IOT_RESET;          //Set value to zero
  P3DIR |= IOT_RESET;           //Set to output
  //P3_1
  P3SEL0 &= ~IOT_STA_MINIAP;    //IOT sta miniap
  P3SEL1 &= ~IOT_STA_MINIAP;    //IOT sta miniap
  P3OUT &= ~IOT_STA_MINIAP;     //Set value to zero
  P3DIR |= IOT_STA_MINIAP;      //Set to output
  //P3_2
  P3SEL0 &= ~IOT_WAKEUP;        //IOT wakeup
  P3SEL1 &= ~IOT_WAKEUP;        //IOT wakeup
  P3OUT &= ~IOT_WAKEUP;         //Set value to zero
  P3DIR |= IOT_WAKEUP;          //Set to output
  //P3_3
  P3SEL0 &= ~IOT_FACTORY;       //IOT factory
  P3SEL1 &= ~IOT_FACTORY;       //IOT factory
  P3OUT &= ~IOT_FACTORY;        //Set value to zero
  P3DIR |= IOT_FACTORY;         //Set to output
  //P3_4
  switch(choice){
    case USE_SMCLK:
      P3SEL0 |= SMCLK;         //SM clock
      P3SEL1 |= SMCLK;          //SM clock
      P3DIR |= SMCLK;           //Set to output
      break;
    case USE_L_REVERSE:
      P3SEL0 &= ~L_REVERSE;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
      P3SEL1 &= ~L_REVERSE;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
      P3OUT &= ~L_REVERSE;   // Set the initial value Low so N-FET is off
      P3DIR |= L_REVERSE;    // Set direction to output
      break;
  }
  //P3_5
  P3SEL0 &= ~L_FORWARD;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
  P3SEL1 &= ~L_FORWARD;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
  P3OUT &= ~L_FORWARD;   // Set the initial value Low so N-FET is off
  P3DIR |= L_FORWARD;    // Set direction to output
  //P3_6
  P3SEL0 &= ~R_REVERSE;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
  P3SEL1 &= ~R_REVERSE;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
  P3OUT &= ~R_REVERSE;   // Set the initial value Low so N-FET is off
  P3DIR |= R_REVERSE;    // Set direction to output+
  //P3_7
  P3SEL0 &= ~R_FORWARD;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
  P3SEL1 &= ~R_FORWARD;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
  P3OUT &= ~R_FORWARD;   // Set the initial value Low so N-FET is off
  P3DIR |= R_FORWARD;    // Set direction to output
}

//Initialize port 4
/*
Port 4:
  Pin 0: Not used
  Pin 1: Not used
  Pin 2: Not used
  Pin 3: Not used
  Pin 4: Chip select for LCD
  Pin 5: Not used
  Pin 6: Not used
  Pin 7: Not used
*/
void Init_Port_4(void){
  //P4_0
  P4SEL0 &= ~SD_CS;             //Unused
  P4SEL1 &= ~SD_CS;             //Unused
  P4DIR &= ~SD_CS;              //Unused
  //P4_1
  P4SEL0 &= ~P4_1;              //Unused
  P4SEL1 &= ~P4_1;              //Unused
  P4DIR &= ~P4_1;               //Unused
  //P4_2
  P4SEL0 &= ~P4_2;              //Unused
  P4SEL1 &= ~P4_2;              //Unused
  P4DIR &= ~P4_2;               //Unused
  //P4_3
  P4SEL0 &= ~P4_3;              //Unused
  P4SEL1 &= ~P4_3;              //Unused
  P4DIR &= ~P4_3;               //Unused
  //P4_4
  P4SEL0 &= ~CS_LCD;            //Chip select for LCD
  P4SEL1 |= CS_LCD;             //Chip select for LCD
  P4DIR |= CS_LCD;              //Unused
  //P4_5
  P4SEL0 &= ~P4_5;              //Unused
  P4SEL1 &= ~P4_5;              //Unused
  P4DIR &= ~P4_5;               //Unused
  //P4_6
  P4SEL0 &= ~P4_6;              //Unused
  P4SEL1 &= ~P4_6;              //Unused
  P4DIR &= ~P4_6;               //Unused
  //P4_7
  P4SEL0 &= ~P4_7;              //Unused
  P4SEL1 &= ~P4_7;              //Unused
  P4DIR &= ~P4_7;               //Unused
}

//Initialize port 5
/*
Port 5:
  Pin 0: MOSI for LCD
  Pin 1: MISO for LCD
  Pin 2: CLK for LCD
  Pin 3: Reset for LCD
  Pin 4: Not used
  Pin 5: Button 2
  Pin 6: Button 1
  Pin 7: Backlight for LCD
*/
void Init_Port_5(void){
  //P5_0
  P5SEL0 |= SPIMOSI;            //LCD MOSI
  P5SEL1 &= ~SPIMOSI;           //LCD MOSI
  //P5_1
  P5SEL0 |= SPIMISO;            //LCD MISO
  P5SEL1 &= ~SPIMISO;           //LCD MISO
  //PS_2
  P5SEL0 |= SPICLK;             //LCD CLK
  P5SEL1 &= ~SPICLK;            //LCD CLK
  //PS_3
  P5SEL0 &= ~RESET_LCD;         //LCD reset
  P5SEL1 &= ~RESET_LCD;         //LCD reset
  P5OUT |= RESET_LCD;           //Set high
  P5DIR |= RESET_LCD;           //Set as output
  //P5_4
  P5SEL0 &= ~P5_4;              //Unused
  P5SEL1 &= ~P5_4;              //Unused
  P5DIR &= ~P5_4;               //Unused
  //P5_5
  P5SEL0 &= ~BUTTON2;           //Button 2
  P5SEL1 &= ~BUTTON2;           //Button 2
  P5DIR &= ~BUTTON2;            //Set button 2 to input
  P5OUT |= BUTTON2;             //Configure pull-up resistor
  P5REN |= BUTTON2;             //Enable pull-up resistor
  P5IES |= BUTTON2;             //Hi/Low edge interrupt
  //P5_6
  P5SEL0 &= ~BUTTON1;           //Button 1
  P5SEL1 &= ~BUTTON1;           //Button 1
  P5DIR &= ~BUTTON1;            //Set button 2 to input
  P5OUT |= BUTTON1;             //Configure pull-up resistor
  P5REN |= BUTTON1;             //Enable pull-up resistor
  P5IES |= BUTTON1;             //Hi/Low edge interrupt
  //P5_7
  P5SEL0 &= ~LCD_BACKLITE;      //LCD backlight
  P5SEL1 &= ~LCD_BACKLITE;      //LCD backlight
  P5OUT &= ~LCD_BACKLITE;        //Set backlight to low
  P5DIR |= LCD_BACKLITE;        //Set as output
}

//Initialize port 6
/*
Port 6:
  Pin 0: TX for UCA3
  Pin 1: RX for UCA3
  Pin 2: Not used
  Pin 3: Not used
  Pin 4: Not used
  Pin 5: Not used
  Pin 6: Not used
  Pin 7: Not used
*/
void Init_Port_6(void){
  //P6_0
  P6SEL0 |= UTXD;              //TX for UCA3
  P6SEL1 &= ~UTXD;               //TX for UCA3
  //P6_1
  P6SEL0 |= URXD;              //RX for UCA3
  P6SEL1 &= ~URXD;               //RX for UCA3
  //P6_2
  P6SEL0 &= ~P6_2;              //Unused
  P6SEL1 &= ~P6_2;              //Unused
  P6DIR &= ~P6_2;               //Unused
  //P6_3
  P6SEL0 &= ~MAG_INT;           //Unused
  P6SEL1 &= ~MAG_INT;           //Unused
  P6DIR &= ~MAG_INT;            //Unused
  //P6_4
  P6SEL0 &= ~P6_4;              //Unused
  P6SEL1 &= ~P6_4;              //Unused
  P6DIR &= ~P6_4;               //Unused
  //P6_5
  P6SEL0 &= ~P6_5;              //Unused
  P6SEL1 &= ~P6_5;              //Unused
  P6DIR &= ~P6_5;               //Unused
  //P6_6
  P6SEL0 &= ~P6_6;              //Unused
  P6SEL1 &= ~P6_6;              //Unused
  P6DIR &= ~P6_6;               //Unused
  //P6_7
  P6SEL0 &= ~P6_7;              //Unused
  P6SEL1 &= ~P6_7;              //Unused
  P6DIR &= ~P6_7;               //Unused
}

//Initialize port 7
/*
Port 7:
  Pin 0: I2C data line
  Pin 1: I2C clock line
  Pin 2: SD card detect
  Pin 3: Not used
  Pin 4: Not used
  Pin 5: Not used
  Pin 6: Not used
  Pin 7: Not used
*/
void Init_Port_7(void){
  //P7_0
  P7SEL0 &= ~I2CSDA;            //I2C data line
  P7SEL1 |= I2CSDA;             //I2C data line
  //P7_1
  P7SEL0 &= ~I2CSCL;            //I2C clock line
  P7SEL1 |= I2CSCL;             //I2C clock line
  //P7_2
  P7SEL0 &= ~SD_DETECT;         //SD card detect
  P7SEL1 |= SD_DETECT;          //SD card detect
  //P7_3
  P7SEL0 &= ~MAG_INT;           //Unused
  P7SEL1 &= ~MAG_INT;           //Unused
  P7DIR &= ~MAG_INT;            //Unused
  //P7_4
  P7SEL0 &= ~P7_4;              //Unused
  P7SEL1 &= ~P7_4;              //Unused
  P7DIR &= ~P7_4;               //Unused
  //P7_5
  P7SEL0 &= ~P7_5;              //Unused
  P7SEL1 &= ~P7_5;              //Unused
  P7DIR &= ~P7_5;               //Unused
  //P7_6
  P7SEL0 &= ~P7_6;              //Unused
  P7SEL1 &= ~P7_6;              //Unused
  P7DIR &= ~P7_6;               //Unused
  //P7_7
  P7SEL0 &= ~P7_7;              //Unused
  P7SEL1 &= ~P7_7;              //Unused
  P7DIR &= ~P7_7;               //Unused
}

//Initialize port 8
/*
Port 8:
  Pin 0: Infrared LED
  Pin 1: Not used
  Pin 2: Not used
  Pin 3: Not used
*/
void Init_Port_8(void){
  //P8_0
  P8SEL0 &= ~IR_LED;            //Infrared LED
  P8SEL1 &= ~IR_LED;            //Infrared LED
  P8OUT &= ~IR_LED;              //Set IR LED to high
  P8DIR |= IR_LED;              //Set as output
  //P8_1
  P8SEL0 &= ~OPT_INT;           //Unused
  P8SEL1 &= ~OPT_INT;           //Unused
  P8DIR &= ~OPT_INT;            //Unused
  //P8_2
  P8SEL0 &= ~TMP_INT;           //Unused
  P8SEL1 &= ~TMP_INT;           //Unused
  P8DIR &= ~TMP_INT;            //Unused
  //P8_3
  P8SEL0 &= ~INT2;              //Unused
  P8SEL1 &= ~INT2;              //Unused
  P8DIR &= ~INT2;               //Unused
}

//Initialize port J
/*
Port J:
  Pin 0: Not used
  Pin 1: Not used
  Pin 2: Not used
  Pin 3: Not used
  Pin 4: Low frequency clock in
  Pin 5: Low frequency clock out
  Pin 6: High frequency clock in
  Pin 7: High frequency clock out
*/
void Init_Port_J(void){
  //PJ_0
  PJSEL0 &= ~PJ_0;              //Unused
  PJSEL1 &= ~PJ_0;              //Unused
  PJDIR &= ~PJ_0;               //Unused
  //PJ_1
  PJSEL0 &= ~PJ_1;              //Unused
  PJSEL1 &= ~PJ_1;              //Unused
  PJDIR &= ~PJ_1;               //Unused
  //PJ_2
  PJSEL0 &= ~PJ_2;              //Unused
  PJSEL1 &= ~PJ_2;              //Unused
  PJDIR &= ~PJ_2;               //Unused
  //PJ_3
  PJSEL0 &= ~PJ_3;              //Unused
  PJSEL1 &= ~PJ_3;              //Unused
  PJDIR &= ~PJ_3;               //Unused
  //PJ_4
  PJSEL0 |= LFXIN;             // For XT1 - low frequency clock in
  PJSEL1 &= ~LFXIN;            // For XT1
  //PJ_5
  PJSEL0 |= LFXOUT;            // For XT1 - low frequency clock out
  PJSEL1 &= ~LFXOUT;           // For XT1
  //PJ_6
  PJSEL0 |= HFXIN;             // For XT1 - high frequency clock in
  PJSEL1 &= ~HFXIN;            // For XT1
  //PJ_7
  PJSEL0 |= HFXOUT;            // For XT1 - high frequency clock out
  PJSEL1 &= ~HFXOUT;           // For XT1
}