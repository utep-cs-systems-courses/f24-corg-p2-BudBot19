#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "siren_c.c"
#include "siren_s.s"




#define SW1 BIT3/* switch1 is p1.3 */
#define SWITCHES SW1/* only 1 switch on this board */



void switch_init() {
  P1REN |= SWITCHES;/* enables resistors for switches */
  P1IE |= SWITCHES;/* enable interrupts from switches */
  P1OUT |= SWITCHES;/* pull-ups for switches */
  P1DIR &= ~SWITCHES;/* set switches' bits for input */

}


void wdt_init() {
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();/* enable periodic interrupt */
}



void main(void)
{
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
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
  char p1val = P1IN;/* switch is in P1 */
  P1IES |= (p1val & SWITCHES);/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);/* if switch down, sense up */


  if (p1val & SW1) {/* button up */
    buttonDown = 1;
  } else {/* button down */
    buttonDown = 0;
  }
}

/* Switch on P1 (S2) */

void

__interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHES) {      /* did a button cause this interrupt? */
    P1IFG &= ~SWITCHES;      /* clear pending sw interrupts */
    switch_interrupt_handler();/* single handler for all switches */
  }
}


int siren_state = 0; //determines the light and tone
int secondCount = 0;

void

__interrupt_vec(WDT_VECTOR) WDT()/* 250 interrupts/sec */

{
  secondCount++;
  
  if((secondCount >= 250) & (buttonDown = 1)){
    secondCount = 0;

    if(siren_state){
      siren_state = 0;
    }else if(!siren_state){
      siren_state = 1;
    }

    siren_activate(siren_state);
  }
}
