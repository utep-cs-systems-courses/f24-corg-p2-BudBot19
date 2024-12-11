#include <msp430.h>
#include <libTimer.h>
#include <lcddraw.h>
#include <lcdutils.h>
#include "draw.h"

void draw_faces(int state){
  lcd_init();
  int col = (screenWidth/2) - 40;
  int row = (screenHeight/2) - 40;
  
  switch(state) {

  case 2:
    clearScreen(COLOR_YELLOW);
    fillRectangle(col, row, 80, 80, COLOR_ORANGE);
    break;
  case 3:
    clearScreen(COLOR_ORANGE);
    fillRectangle(col, row, 80, 80, COLOR_RED);
    break;
  case 4:
    clearScreen(COLOR_ORANGE_RED);
    fillRectangle(col, row, 80, 80, COLOR_FIREBRICK);
    break;
  default:
    clearScreen(COLOR_BLUE);

  }

  return;

}
