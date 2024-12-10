#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

typedef struct {

  short col, row;

}

Pos;

Pos positions[5];
#define NUM_POSITIONS 5

unsigned short sqColors[4];
#define NUM_SQCOLORS 4
#define BG_COLOR COLOR_BLACK

char current_position, current_color;

void draw_face1();

