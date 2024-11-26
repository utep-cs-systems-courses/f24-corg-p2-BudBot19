#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "siren_c.c"




#define SW1 BIT0 /* switch1 is p2.0 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4) 



void switch_init() {
  P2REN |= SWITCHES;/* enables resistors */
  P2IE |= SWITCHES;/* enable interrupts */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */

}


void wdt_init() {
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();/* enable periodic interrupt */
}



void main(void)
{
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN; //both leds start off
  P1OUT &= ~LED_RED;
  
  switch_init();
  wdt_init();
  buzzer_init();


  or_sr(0x18);  // CPU off, GIE on
}


static int buttonDown;


void
switch_interrupt_handler()
{
  char p2input = P2IN;/* switch is in P2 */
  P2IES |= (p2input & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2input | ~SWITCHES);/* if switch down, sense up */


  if (~p2input & SW1) {/* button down */
    buttonDown = 1;
  } else if(~p2input & SW2){
    buttonDown = 2; /* value is ready for clock interupt */
  } else if(~p2input & SW3){
    buttonDown = 3;
  } else if(~p2input & SW4){
    buttonDown = 4;
  }
  if((~p2input & SW1) & (~p2input & SW4)){
    buttonDown = 0;
    buzzer_set_period(0);
    P1OUT &= ~LED_GREEN;
    P1OUT &= ~LED_RED;
  }
}

/* Switch on P1 (S2) */

void

__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;    
    switch_interrupt_handler();
  }
}


int siren_state = 0; /* determines the light and tone */
int secondCount = 0;

void

__interrupt_vec(WDT_VECTOR) WDT()/* 250 interrupts == sec */

{
  secondCount++;
  
  int siren_rate = 0;
  switch(buttonDown) {

  case '1':
    siren_rate = 250;

  case '2':
    siren_rate = 125;

  case '3':
    siren_rate = 50;

  case '4':
    siren_rate = 6;

  }
  
  if((secondCount >= 250) & (buttonDown > 0)){ /* button is down and second has passed */
    secondCount = 0;

    if(siren_state){ /* alternates state of siren */
      siren_state = 0;
    }else if(!siren_state){
      siren_state = 1;
    }

    siren_activate(siren_state);
  }
}
