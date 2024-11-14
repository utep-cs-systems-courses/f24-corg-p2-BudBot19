#include <msp430.h>
#include "buzzer.h"
#include "led.h"

void siren_activate(int siren_state)
{
  if(siren_state){

    P1OUT &= ~LED_GREEN;

    P1OUT |= LED_RED;

    buzzer_set_period(1000);

  }else if(!siren_state){

    P1OUT |= LED_GREEN;

    P1OUT &= ~LED_RED;

    buzzer_set_period(1200);

  }



}
