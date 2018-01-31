#include  "msp430.h"
#include  "functions.h"
#include "macros.h"

void Init(void){
  PM5CTL0 &= ~LOCKLPM5;
  enable_interrupts();
}