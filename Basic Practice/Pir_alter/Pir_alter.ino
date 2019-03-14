void setup(){
Serial.begin(9600);
pinMode(13, OUTPUT);
pinMode(A0, INPUT);
}
void loop(){
int value= analogRead(A0);

if (value >500)
{
//Serial.println("HIGH");
Serial.println(value);
digitalWrite(13, HIGH);
}
else
{
//Serial.println("LOW");
Serial.println(value);
digitalWrite(13, LOW);
}
}
