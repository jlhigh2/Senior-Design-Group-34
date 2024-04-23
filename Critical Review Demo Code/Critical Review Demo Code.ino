#include "LedControl.h"

LedControl lc=LedControl(3, 2, 5, 1);

byte letters[4][8]={{B10000001,B10000011,B10000101,B10001001,B10010001,B10100001,B11000001,B10000001},
                   {B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110,B00000000},
                   {B01111110,B00000010,B00000010,B01111110,B01000000,B01000000,B01111110,B00000000},
                   {B00000000,B01111110,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010}};

byte cross[3][8]= {{B01111100,B01000000,B01000000,B01111100,B01000000,B01000000,B01111100,B00000000},
                  {B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110,B00000000},
                  {B01111100,B01000000,B01000000,B01111100,B01000000,B01000000,B01111100,B00000000}};

int executeDisplay = 0;



void setup() 
{
  lc.shutdown(0,false);
  lc.setIntensity(0,1);
  lc.clearDisplay(0);
  pinMode(14, INPUT);
  attachInterrupt(14, enablePattern, CHANGE);
}

void loop() 
{ 
  if (executeDisplay == 2){
    for (int i=0; i<4; i++)
      {
        for (int j=0; j<8; j++)
        {
          lc.setRow(0,j,letters[i][j]);
        }
        delay(850);
      }
    lc.clearDisplay(0);
    executeDisplay = 3;
  }
  if (executeDisplay == 5){
    for (int i=0; i<3; i++)
      {
        for (int j=0; j<8; j++)
        {
          lc.setRow(0,j,cross[i][j]);
        }
        delay(850);
      }
    lc.clearDisplay(0);
    executeDisplay = 0;
    }
}

void enablePattern(){
  executeDisplay = executeDisplay + 1;
  delay(10);
}



