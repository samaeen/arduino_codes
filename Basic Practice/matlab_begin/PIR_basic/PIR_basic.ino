const int ledPin= 13;
const int inputPin= 2;

void setup(){
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(inputPin, INPUT);
}

void loop(){
int value= digitalRead(inputPin);

if (value == HIGH)
{
Serial.println("HIGH");
digitalWrite(ledPin, HIGH);
delay(600);
digitalWrite(ledPin, LOW);
}
else
{
Serial.println("LOW");
digitalWrite(ledPin, LOW);
}
}
