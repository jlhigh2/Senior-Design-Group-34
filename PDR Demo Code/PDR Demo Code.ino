#define LOW (0)
#define HIGH (1)

int buttonState = LOW;
int lastMillis = 0;
int ledState = 0;
hw_timer_t *My_timer = NULL;

void IRAM_ATTR function_ISR() {
         if (buttonState == HIGH){
           buttonState = LOW;
         }
         else buttonState = HIGH;
 
}

void IRAM_ATTR onTimer(){
    ledState++;
    if (ledState == 4){
      ledState = 0;
    }
}

void setup() {
  Serial.begin(115200);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(18, INPUT_PULLUP);
	attachInterrupt(18, function_ISR, CHANGE);

  My_timer = timerBegin(0, 80, true);
  timerAttachInterrupt(My_timer, &onTimer, true);
  timerAlarmWrite(My_timer, 1000000, true);
  timerAlarmEnable(My_timer);
}

void loop() {
    if (buttonState == HIGH) {
          switch(ledState){
            case 0:
              digitalWrite(23, LOW);
              digitalWrite(32, HIGH);
              break;
            case 1:
              digitalWrite(32, LOW);
              digitalWrite(33, HIGH);
              break;
            case 2:
              digitalWrite(33, LOW);
              digitalWrite(22, HIGH);
              break;
            case 3:
              digitalWrite(22, LOW);
              digitalWrite(23, HIGH);
              break;
          }
    }
    else{
      digitalWrite(33, LOW);
      digitalWrite(32, LOW);
      digitalWrite(22, LOW);
      digitalWrite(23, LOW);
    }
}

