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

#define BG_COLOR COLOR_BLACK

char current_position;

void draw_face1();

void draw_faces();

