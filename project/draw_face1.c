#include <msp430.h>
#include <libTimer.h>
#include <lcddraw.h>
#include <lcdutils.h>
#include "draw.h"

void draw_face1(){
  current_position = (screenHeight/2) - 20;
  fillRectangle(40, 40, 20, 20, COLOR_YELLOW);
  return;
}
