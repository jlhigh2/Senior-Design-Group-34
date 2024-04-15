#include "LedControl.h"
LedControl lc=LedControl(3,2,5,1);

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,3);
  lc.clearDisplay(0);
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  pinMode(25, OUTPUT);
  digitalWrite(25, HIGH);
}

const byte N[6]={B11111111,B01000000,B00110000,B00001100,B11111111,B00000000};
const byte C[6]={B11111111,B10000001,B10000001,B10000001,B10000001,B00000000};
const byte S[6]={B11110001,B10010001,B10010001,B10010001,B10011111,B00000000};
const byte U[6]={B11111111,B00000001,B00000001,B00000001,B11111111,B00000000};
const byte E[6]={B11111111,B10010001,B10010001,B10010001,B10010001,B00000000};

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
  }
}

void loop() {
  scroll("NCSU");
  delay(10000);
  digitalWrite(10, HIGH);
}
