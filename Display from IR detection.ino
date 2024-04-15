#include "LedControl.h"
LedControl lc=LedControl(3,2,5,1);
int val0 = 0;
int irPin0 = A0;
bool cupPlaced = false;

const byte N[6]={B11111111,B00000010,B00001100,B00110000,B11111111,B00000000};
const byte C[6]={B10000001,B10000001,B10000001,B10000001,B11111111,B00000000};
const byte S[6]={B10011111,B10010001,B10010001,B10010001,B11110001,B00000000};
const byte U[6]={B11111111,B00000001,B00000001,B00000001,B11111111,B00000000};
const byte E[6]={B10010001,B10010001,B10010001,B10010001,B11111111,B00000000};

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
    var++;
    springroll = false;    
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
  sleep_ms(3000);
}

void loop()
{
  val0 = analogRead(irPin0);
  if (val0 > 800) {cupPlaced = true;}
  if (cupPlaced && (val0 < 395)) {scroll("NCSUECE");}
}