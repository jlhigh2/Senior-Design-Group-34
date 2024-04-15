#include "LedControl.h"
LedControl lc=LedControl(3,2,5,1);
int val0 = 0;
int irPin0 = A0;
bool boot = true;
int pattern = 0;
bool cupPlaced = false;
int oldValue = 0;
bool firstValue = true;
int difference = 0;

const byte N[6]={B11111111,B00000010,B00001100,B00110000,B11111111,B00000000};
const byte C[6]={B10000001,B10000001,B10000001,B10000001,B11111111,B00000000};
const byte S[6]={B10011111,B10010001,B10010001,B10010001,B11110001,B00000000};
const byte U[6]={B11111111,B00000001,B00000001,B00000001,B11111111,B00000000};
const byte E[6]={B10010001,B10010001,B10010001,B10010001,B11111111,B00000000};
const byte T[6]={B10000000,B10000000,B11111111,B10000000,B10000000,B00000000};
const byte H[6]={B11111111,B00010000,B00010000,B00010000,B11111111,B00000000};
const byte L[6]={B00000001,B00000001,B00000001,B00000001,B11111111,B00000000};
const byte O[6]={B11111111,B10000001,B10000001,B10000001,B11111111,B00000000};
const byte A[6]={B11111111,B10010000,B10010000,B10010000,B11111111,B00000000};
const byte P[6]={B11110000,B10010000,B10010000,B10010000,B11111111,B00000000};


const byte cross[2][8]= {{B00011000,B00011000,B00011000,B11111111,B11111111,B00011000,B00011000,B00011000},
                  {B11000011,B11100111,B01100110,B00111100,B00111100,B01100110,B11100111,B11000011}};

const byte heart[8]={B01111000,B10000100,B11000010,B01100001,B11000010,B10000100,B01111000,B00000000};

void display(const byte letter[6]) {
  lc.clearDisplay(0);
 int i,j = 0;
  for (i=8; i>=0; i--) {
  for (j=0; j<6; j++) {
      lc.setRow(0,j+i,letter[j]);
      }
      delay(110);
}
}

void scroll(char * s) {
  int var=0;
  while (s[var]) {
    if (s[var]=='N')
      display(N);
    if (s[var]=='C')
      display(C);  
    if (s[var]=='S')
      display(S);   
    if (s[var]=='U')
      display(U);   
    if (s[var]=='E')
      display(E); 
    if (s[var]=='T')
      display(T);
    if (s[var]=='H')
      display(H);  
    if (s[var]=='L')
      display(L);   
    if (s[var]=='O')
      display(O);  
    if (s[var]=='A')
      display(A); 
    if (s[var]=='P')
      display(P); 
    var++;
  }
}

void setup()
{
  lc.shutdown(0,false);
  lc.setIntensity(0,4);
  lc.clearDisplay(0);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(21, OUTPUT);
  digitalWrite(21, HIGH);
  pinMode(20, OUTPUT);
  digitalWrite(20, HIGH);
  sleep_ms(500);
  // display HELLO
  scroll("TEST");
  lc.clearDisplay(0);
}

void loop()
{
  
  val0 = analogRead(irPin0);

  if (firstValue){
    oldValue = val0;
    firstValue = false;
  }

  difference = val0 - oldValue;
  

  Serial.print(val0);
  Serial.print("      ");
  Serial.print(oldValue);
  Serial.print("      ");
  Serial.print(difference);
  Serial.print("\n");
  oldValue = val0;
  sleep_ms(200);

  if (difference < -45) {
      //int pattern = random(0, 4);
      switch(pattern){
        case 0:
          // NCSU
          scroll("NCSU"); 
          break;
        case 1:
        //cross
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
          break;
        case 2:
          //heart
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
            for (int i=0; i<16; i++)
            {
              lc.setIntensity(0,i);
              delay(50);
            }
          break;
        case 3:
          // ECE
          scroll("ECE"); 
          break;
        case 4:
          //pattern 5
          scroll("ALPHA");
          break;
      }
      pattern++;
      if (pattern >= 5){
        pattern = 0;
      }
      cupPlaced=false; 
      lc.clearDisplay(0);
    }
}