#include "LedControl.h"
LedControl lc=LedControl(3,2,5,1);

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,3);
  lc.clearDisplay(0);
  // Serial.begin(9600);
  // pinMode(10, OUTPUT);
  // digitalWrite(10, LOW);
  // pinMode(25, OUTPUT);
  // digitalWrite(25, HIGH);
}

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
const byte K[6]={B10000011,B01000100,B00101000,B00010000,B11111111,B00000000};
const byte Y[6]={B11110000,B00010000,B00011111,B00010000,B11110000,B00000000};
const byte J[8]={B00000111,B00000001,B11100001,B00000001,B00000001,B11100001,B00000001,B00000111};
const byte M[8]={B00000111,B01000001,B01000001,B01000001,B00000001,B11100001,B00000001,B00000111};




void display(const byte letter[6]) {
  lc.clearDisplay(0);
 int i,j = 0;
  for (i=8; i>=0; i--) {
  for (j=0; j<6; j++) {
      lc.setRow(0,j+i,letter[j]);
      }
      delay(200);
}
}

void smiles(const byte letter[7]) {
  for(int i = 0; i < 8; i++) {
    lc.setRow(0, i, letter[i]);
  }
  delay(725);
  lc.clearDisplay(0);
}

void stars () {
  lc.setLed(0, 0, 4, true);
  delay(500);
  lc.setIntensity(0,5);  
  lc.setLed(0, 1, 1, true);
  delay(420);
  lc.setIntensity(0,12);
  lc.setLed(0, 2, 7, true);
  delay(370);
  lc.setIntensity(0,9);
  lc.setLed(0, 3, 3, true);
  delay(300);
  lc.setIntensity(0,14);
  lc.setLed(0, 4, 5, true);
  delay(250);
  lc.setIntensity(0,4);
  lc.setLed(0, 5, 0, true);
  delay(220);
  lc.setIntensity(0,12);
  lc.setLed(0, 6, 3, true);  
  delay(195);
  lc.setIntensity(0,6);
  lc.setLed(0, 7, 6, true);
  for(int i = 0; i < 16; i++) {
    delay(100);
    lc.setIntensity(0, i);
  }
}

void rows() {
  for(int i = 0; i < 5; i++) {
    lc.setRow(0, 3, B00011000);
    lc.setRow(0, 4, B00011000);
    delay(130);
    lc.clearDisplay(0);
    lc.setRow(0, 2, B00111100);
    lc.setRow(0, 3, B00100100);
    lc.setRow(0, 4, B00100100);
    lc.setRow(0, 5, B00111100);
    delay(130);
    lc.clearDisplay(0);
    lc.setRow(0, 1, B01111110);
    lc.setRow(0, 2, B01000010);
    lc.setRow(0, 3, B01000010);
    lc.setRow(0, 4, B01000010);
    lc.setRow(0, 5, B01000010);
    lc.setRow(0, 6, B01111110);  
    delay(130);
    lc.clearDisplay(0);
    lc.setColumn(0, 0, B11111111);
    lc.setRow(0, 0, B11111111);
    lc.setColumn(0, 7, B11111111);
    lc.setRow(0, 7, B11111111);
    delay(130);
    lc.clearDisplay(0);
    lc.setRow(0, 1, B01111110);
    lc.setRow(0, 2, B01000010);
    lc.setRow(0, 3, B01000010);
    lc.setRow(0, 4, B01000010);
    lc.setRow(0, 5, B01000010);
    lc.setRow(0, 6, B01111110);  
    delay(130);
    lc.clearDisplay(0);
    lc.setRow(0, 2, B00111100);
    lc.setRow(0, 3, B00100100);
    lc.setRow(0, 4, B00100100);
    lc.setRow(0, 5, B00111100);
    delay(130);
    lc.clearDisplay(0);
  }
}

void scroll(char * s) {
  int var=0;
  while (s[var]) {
    if (s[var]=='N')
      display(N);
    if (s[var]=='H')
      display(H);
    if (s[var]=='K')
      display(K);
    if (s[var]=='C')
      display(C);  
    if (s[var]=='S')
      display(S);   
    if (s[var]=='T')
      display(T);
    if (s[var]=='A')
      display(A);
    if (s[var]=='U')
      display(U);   
    if (s[var]=='E')
      display(E); 
    if (s[var]=='Y')
      display(Y);
    if (s[var]=='O')
      display(O);
    if (s[var]=='J')
      smiles(J);
    if (s[var]=='M')
      smiles(M);
    var++;
  }
}

void loop() {
  scroll("JM");  
  // delay(10000);
  // digitalWrite(10, HIGH);
}
