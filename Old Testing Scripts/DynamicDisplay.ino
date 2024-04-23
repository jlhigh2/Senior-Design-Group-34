#include "LedControl.h"

LedControl lc=LedControl(3,2,5,1);

byte cross[2][8]= {{B00011000,B00011000,B00011000,B11111111,B11111111,B00011000,B00011000,B00011000},
                  {B11000011,B11100111,B01100110,B00111100,B00111100,B01100110,B11100111,B11000011}};

byte heart[8]={B01111000,B10000100,B11000010,B01100001,B11000010,B10000100,B01111000,B00000000};
void setup() 
{
  lc.shutdown(0,false);
  lc.setIntensity(0,1);
  lc.clearDisplay(0);
}

void loop() 
{ 
  for(int k=0; k<20; k++)
  {
  for (int i=0; i<2; i++)
  {
    for (int j=0; j<8; j++)
    {
      lc.setRow(0,j,cross[i][j]);
    }
    delay(100);
  }
  }
while(1)
{
  for (int j=0; j<8; j++)
  {
    lc.setRow(0,j,heart[j]);
  }
  for (int i=0; i<16; i++)
  {
    lc.setIntensity(0,i);
    delay(50);
  }
  for (int i=15; i>=0; i--)
  {
    lc.setIntensity(0,i);
    delay(50);
  }
}
}