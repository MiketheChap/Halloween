// sketch 01_03_paperclip
int ledPin = 13;


void setup() 
{
  pinMode(ledPin, OUTPUT);
  flash(10, 100);

}

void loop() 
{
  flash(1, 500);
}

void flash(int n, int delayPeriod)
{
   for (int i = 0; i < n; i++)
   {
    digitalWrite(ledPin, HIGH);
    delay(delayPeriod);
    digitalWrite(ledPin, LOW);
    delay(delayPeriod);
   }
}
