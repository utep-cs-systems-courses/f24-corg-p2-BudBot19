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
    face2(col, row);
    break;

  case 3:
    clearScreen(COLOR_ORANGE);
    fillRectangle(col, row, 80, 80, COLOR_RED);
    face3(col, row);
    break;

  case 4:
    clearScreen(COLOR_ORANGE_RED);
    fillRectangle(col, row, 80, 80, COLOR_FIREBRICK);
    face4(col, row);
    break;

  default:
    clearScreen(COLOR_BLUE);
  }
  return;
}

void face2(int col_par, int row_par){
  int col = col_par;
  int row = row_par;
  int current_col = col;
  int current_row = row;

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
  drawString5x7(current_col, current_row, "Warning!!!", COLOR_BLACK, COLOR_YELLOW);
  return;
}


void face3(int col_par, int row_par){
  int col = col_par;
  int row = row_par;
  int current_col = col;
  int current_row = row;

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
  
  current_col = current_col - 5;
  current_row = row + 95;
  drawString5x7(current_col, current_row, "Imminent Danger!!", COLOR_BLACK, COLOR_ORANGE);
  return;
}

void face4(int col_par, int row_par){
  int col = col_par;
  int row = row_par;
  int current_col = col;
  int current_row = row;

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
  current_col = current_col - 5;
  drawString5x7(current_col, current_row, "KABOOM!!!!!", COLOR_BLACK, COLOR_ORANGE_RED);
  return;
}






