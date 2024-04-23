#include "LedControl.h"
#include <time.h>
#include "pico/rand.h"
LedControl lc=LedControl(3,2,5,1);


int val0 = 0;
int irPin0 = A0;
bool boot = true;
int pattern = -1;
bool cupPlaced = false;
int oldValue = 0;
bool firstValue = true;
int difference = 0;
int pingCount = 0;

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

const byte cross[2][8]= {{B00011000,B00011000,B00011000,B11111111,B11111111,B00011000,B00011000,B00011000},
                  {B11000011,B11100111,B01100110,B00111100,B00111100,B01100110,B11100111,B11000011}};

const byte heart[8]={B01111000,B10000100,B11000010,B01100001,B11000010,B10000100,B01111000,B00000000};

void smiles(const byte letter[7]) {
  for(int i = 0; i < 8; i++) {
    lc.setRow(0, i, letter[i]);
  }
  delay(725);
  lc.clearDisplay(0);
}

void display(const byte letter[6]) {
 lc.clearDisplay(0);
 int i,j = 0;
  for (i=0; i<=7; i++) {
  for (j=0; j<6; j++) {
      lc.setRow(0,j+i,letter[j]);
      }
      delay(150);
      lc.clearDisplay(0);
}
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

void enableSoftPower(){
  digitalWrite(10, LOW);
}

void setup()
{
  lc.shutdown(0,false);
  lc.setIntensity(0,3);
  lc.clearDisplay(0);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(21, OUTPUT);
  digitalWrite(21, HIGH);
  pinMode(20, OUTPUT);
  digitalWrite(20, HIGH);
  lc.clearDisplay(0);
  srand (time(NULL));
  delay(100);
}

void loop()
{
  
  val0 = analogRead(irPin0);

  // if getting absolute light values when pinging sensor, save power mode for 15 seconds
  if ((val0 < 350 && cupPlaced == false)){
    //enableSoftPower();
    printf("Soft Power Triggered");
  }

  if (firstValue){
    oldValue = val0;
    firstValue = false;
  }

  difference = val0 - oldValue;
  
  //if big spike up in ir sensor value, cup is most likley placed, prevent soft power shut down to monitor cup removal
  if (difference > 30){
    cupPlaced = true;
  }

  //for testing, delete for final source code
  Serial.print(val0);
  Serial.print("      ");
  Serial.print(oldValue);
  Serial.print("      ");
  Serial.print(difference);
  Serial.print("\n");

  oldValue = val0;
  sleep_ms(200);

  if (difference < -45) {
      //randomize patterns
      uint8_t pattern = (uint8_t)get_rand_32();
      while (pattern >= 8){
        pattern = (uint8_t)get_rand_32();        
      }
      //perform patterns in linear order
      // pattern++;
      // if (pattern >= 8){
      //   pattern = 0;
      // }

      switch(pattern){
        case 0:
          // NCSU
          scroll("NCSTATE"); 
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
            for (int i=0; i<6; i++)
            {
              lc.setIntensity(0,i);
              delay(50);
            }
            for (int i=5; i>=0; i--)
            {
              lc.setIntensity(0,i);
              delay(50);
            }
            for (int i=0; i<6; i++)
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
          stars();
          break;
        case 5:
          //pattern 6
          scroll("THANKYOU");
          break;
        case 6:
          //pattern 7
          rows();
          break;
        case 7:
          //pattern 8
          for (int i = 0; i <= 4; i++) {
          scroll("JM");  
          }
          
          break;
      }
      firstValue = true;
      cupPlaced=false; 
      lc.clearDisplay(0);
    }
}