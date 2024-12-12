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
    fillRectangle(col, row, 80, 80, COLOR_RED);
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
    drawPixel(current_col - 1, current_row, COLOR_BLACK);
    drawPixel(current_col - 2, current_row, COLOR_BLACK);
    current_col += 2;
    current_row++;
  }

  current_col = col + 80;
  current_row = row;

  for(int i = 0; i < 15; i++){   //right eyebrow
    drawPixel(current_col, current_row, COLOR_BLACK);
    drawPixel(current_col + 1, current_row, COLOR_BLACK);
    drawPixel(current_col + 2, current_row, COLOR_BLACK);
    current_col -= 2;
    current_row++;
  }

  current_col = col + 15;
  current_row = row + 15;
  fillRectangle(current_col, current_row, 15, 10, COLOR_BLACK); //left eyeball

  current_col = col + 50;
  current_row = row + 15;
  fillRectangle(current_col, current_row, 15, 10, COLOR_BLACK); //right eyeball

  current_col = col + 30;
  current_row = row + 50;
  fillRectangle(current_col, current_row, 5, 5, COLOR_BLACK); //left nostril

  current_col = col + 45;
  current_row = row + 50;
  fillRectangle(current_col, current_row, 5, 5, COLOR_BLACK); //right nostril


  current_col = col + 20;
  current_row = row + 60; //mouth
  fillRectangle(current_col, current_row, 40, 20, COLOR_BLACK);


  current_row = row + 95;
  drawString5x7(current_col, current_row, "Warning!!!", COLOR_BLACK, COLOR_YELLOW);
  return;
}


void face3(int col_par, int row_par){
  int col = col_par;
  int row = row_par;
  int current_col = col;
  int current_row = row;

  for(int i = 0; i < 25; i++){        //left eyebrow
    for(int j = 0; j < 7; j++){       //j is eyebrow thickness
      drawPixel(current_col + j, current_row, COLOR_BLACK);
    }
    current_col++;
    current_row++;
  }

  current_col = col + 80;
  current_row = row;

  for(int i = 0; i < 25; i++){   //right eyebrow
    for(int j = 0; j < 5; j++){
      drawPixel(current_col - j, current_row, COLOR_BLACK);
    }
    current_col--;
    current_row++;
  }

  current_col = col + 15;
  current_row = row + 20;
  fillRectangle(current_col, current_row, 15, 10, COLOR_BLACK); //left eyeball

  current_col = col + 50;
  current_row = row + 20;
  fillRectangle(current_col, current_row, 15, 10, COLOR_BLACK); //right eyeball

  current_col = col + 30;
  current_row = row + 30;
  fillRectangle(current_col, current_row, 3, 3, COLOR_BLACK); //left nostril

  current_col = col + 45;
  current_row = row + 30;
  fillRectangle(current_col, current_row, 3, 3, COLOR_BLACK); //right nostril

  current_col = col + 10;
  current_row = row + 50;
  fillRectangle(current_col, current_row, 60, 30, COLOR_BLACK); //mouth

  current_col += 5;
  current_row += 5;
  for(int i = 0; i < 2; i++){ //teeth rows
    for(int j = 0; j < 5; j++){ //teeth cols
      fillRectangle(current_col, current_row, 8, 8, COLOR_WHITE);
      current_col += 10;
    }
    current_col -= 50; //first col pos
    current_row += 10;
  }
  
  current_col = col;
  current_row = row + 95;
  drawString5x7(current_col, current_row, "Imminent Danger!!", COLOR_BLACK, COLOR_ORANGE);
  return;
}

void face4(int col_par, int row_par){
  int col = col_par;
  int row = row_par;
  int current_col = col;
  int current_row = row;

  for(int i = 0; i < 30; i++){        //left flap
    for(int j = 0; j < 10; j++){
      drawPixel(current_col + j, current_row, COLOR_RED);
    }
    current_col--;
    current_row--;
  }

  current_col = col + 80;
  current_row = row;

  for(int i = 0; i < 30; i++){   //right flap
    for(int j = 0; j < 10; j++){
      drawPixel(current_col - j, current_row, COLOR_RED);
    }
    current_col++;
    current_row--;
  }

  //explosion here
  current_col = col;
  current_row = 0;
  while(current_row < row){
    for(int i = 0; current_col < (col+80); i++){
      drawPixel(current_col, current_row, COLOR_WHITE);
      current_col += 3;
      drawPixel(current_col, current_row, COLOR_GRAY);
      current_col += 3;
    }
    current_col = col;
    current_row++;
  }
	  

  current_col = col + 5;
  current_row = row + 5;
  fillRectangle(current_col, current_row, 20, 20, COLOR_BLACK); //left eyeball
  fillRectangle(current_col + 5, current_row + 2, 5, 5, COLOR_WHITE);

  current_col = col + 50;
  current_row = row + 5;
  fillRectangle(current_col, current_row, 20, 20, COLOR_BLACK); //right eyeball
  fillRectangle(current_col + 5, current_row + 2, 5, 5, COLOR_WHITE);

  
  current_col = col + 30;
  current_row = row + 50;
  fillRectangle(current_col, current_row, 5, 5, COLOR_BLACK); //left nostril

  current_col = col + 45;
  current_row = row + 50;
  fillRectangle(current_col, current_row, 5, 5, COLOR_BLACK); //right nostril
  
  current_col = col + 40;
  current_row = row + 65;
  fillRectangle(current_col, current_row, 20, 20, COLOR_BLACK);

  current_row = row + 95;
  current_col = current_col - 5;
  drawString5x7(current_col, current_row, "KABOOM!!!!!", COLOR_BLACK, COLOR_ORANGE_RED);
  return;
}






