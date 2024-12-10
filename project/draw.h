#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

typedef struct {

  short col, row;

}

Pos;

Pos positions[] = {
  {10,10}, //upper left
  {10, screenHeight-10}, //lower left
  {screenWidth - 10, screenHeight - 10}, //lower right
  {screenWidth - 10, 10}, //upper right
  {screenWidth/2, screenHeight/2} //center
};
#define NUM_POSITIONS 5

unsigned short sqColors[] = {COLOR_RED, COLOR_GREEN, COLOR_ORANGE, COLOR_BLUE};
#define NUM_SQCOLORS 4
#define BG_COLOR COLOR_BLACK

char current_position = 0, current_color = 0;

void draw_face1();

