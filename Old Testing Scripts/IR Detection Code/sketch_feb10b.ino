int val0 = 0;
int irPin0 = A0;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(21, OUTPUT);
  digitalWrite(21, HIGH);
  pinMode(20, OUTPUT);
  digitalWrite(20, HIGH);
}

void loop()
{
  val0 = analogRead(irPin0);
  Serial.print(val0);
  Serial.print("\n\r");
  delay(1500);
}