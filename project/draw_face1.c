#include <msp430.h>
#include <libTimer.h>
#include <lcddraw.h>
#include <lcdutils.h>
#include "draw.h"

void draw_face1(){
  lcd_init();
  
  clearScreen(COLOR_ORANGE);
  
  int col = (screenWidth/2) - 40;
  int row = (screenHeight/2) - 40;
  int current_col = col;
  int current_row = row;
  fillRectangle(col, row, 80, 80, COLOR_YELLOW);

  for(int i = 0; i < 15; i++){        //left eyebrow
    drawPixel(current_col, current_row, COLOR_BLACK);
    current_col += 2;
    current_row++;
  }

  current_col = col + 80;
  current_row = row;
  
  for(int i = 0; i < 15; i++){   //right eyebrow
    drawPixel(current_col, current_row, COLOR_BLACK);
    current_col -= 2;
    current_row++;
  }

  current_col = col + 15;
  current_row = row + 15;
  fillRectangle(current_col, current_row, 15, 15, COLOR_BLACK); //left eyeball

  current_col = col + 50;
  current_row = row + 15;
  fillRectangle(current_col, current_row, 15, 15, COLOR_BLACK); //right eyeball

  current_col = col + 30;
  current_row = row + 40;
  fillRectangle(current_col, current_row, 5, 5, COLOR_BLACK); //left nostril

  current_col = col + 45;
  current_row = row + 40;
  fillRectangle(current_col, current_row, 5, 5, COLOR_BLACK); //right nostril


  current_col = col + 40;
  current_row = row + 65;
  for(int i = 0; i < 10; i++){ //mouth
    drawPixel(current_col + i, current_row + i, COLOR_BLACK);
    drawPixel(current_col - i, current_row + i, COLOR_BLACK);
  }

  current_row = row + 95;
  drawString5x7(current_col, current_row, "Warning...", COLOR_BLACK, COLOR_ORANGE);

  return;
}
