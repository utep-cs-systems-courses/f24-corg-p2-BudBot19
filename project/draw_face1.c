#include <msp430.h>
#include <libTimer.h>
#include <lcddraw.h>
#include <lcdutils.h>
#include "draw.h"

void draw_face1(){
  clearScreen(BG_COLOR);

  current_position = (screenHeight/2) - 40;
  fillRectangle(current_position, current_position, 40, 40, COLOR_YELLOW);
  return;
}
