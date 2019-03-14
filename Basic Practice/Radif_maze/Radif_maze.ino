/*
Name:    Maze_Final.ino
Created: 2/8/2016 12:26:20 PM
Author:  Radif Uddin Ahmed
Team: RMA-13
*/



#include <EEPROM.h>
#include <OrangutanMotors.h>


#define buttonSelect 4 
#define buttonA 12
#define buttonB 10
#define buzzer 9
#define led1 8
#define led2 10
#define led3 12
#define led4 13
#define led5 4
#define led6 7

OrangutanMotors motors;

int l = 0;   //pathlength
int z = 0;   //solved path integer
char way[500]; //character that stores path
char spath[500];// character that stores solved path


int sensorValues[7];    ////////// Raw sensor values////////////////
int calibratedValue[7] = { 0, 0, 0, 0, 0, 0, 0 }; // calibrated values //
bool dv[7] = { 0, 0, 0, 0, 0, 0, 0 };  // digitized values //
int LSpeed = 0; //Left motor speed
int RSpeed = 0; //Right motor speed
int count0 = 0;
int forward_spd = 120;
int zig_spd = 70;
int turn_spd = 50;
int hardTurn_spd = 100;
int pred_spd = 120; // predefined funtion speed
int times = 265;
int ck = 0;
bool onLine;
bool leftFlag = 0;  // front left flag boolean
bool rightFlag = 0; // front right flag boolean
bool mazeSolved = 0;  //as the name suggests
bool white_on_black;
bool black_on_white;
bool left_hand_rule;
bool right_hand_rule;
bool flag = false;
int count1 = 0, count2 = 0;
bool flag1 = false, flag2 = false;
int che = 130;
void setup() {
	pinMode(buttonA, INPUT);  //button a
	pinMode(buttonB, INPUT);  //button b
	pinMode(buttonSelect, INPUT);  //button select
	   /*initialization of track and priority*/
	white_on_black = false;
	black_on_white = true;
	left_hand_rule = true;
	right_hand_rule = false;
	Serial.begin(38400);
	//checkButton();
	//blindleft();
	calibrateSensors();
	stop();
	delay(2000);
	eepromRead();
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	pinMode(led4, OUTPUT);
	pinMode(led5, OUTPUT);
	pinMode(led6, OUTPUT);
	pinMode(buzzer, OUTPUT);
}
void loop() {
	readSensors_BOW();
	led();

	
	
	lineTrack();
	if (mazeSolved==0) { flag_count(); }
	else { solvedflag_count(); }

	//readSensors_BOW();
	

/*	Serial.print(count1);
	Serial.print(" - ");
	Serial.print(count2);
	Serial.println();*/

}





void eepromRead()
{
	for (int i = 0; i < 7; i++)
	{
		calibratedValue[i] = map(EEPROM.read(i), 0, 255, 0, 1023); //reading values from eeprom by converting 8bit number to a 10bit one an storing it in an array
	}

}
void calibrateSensors() {
	//Serial.begin(9600);
	motors.setSpeeds(0, 0);
	int maximum[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int minimum[7] = { 1023, 1023, 1023, 1023, 1023, 1023, 1023 };

	for (int j = 0; j < 3000; j++) {

		/*	if (white_on_black == true) {
		readSensors_WOB();
		}
		if (black_on_white == true) {
		readSensors_BOW();
		}*/
		sensorValues[0] = analogRead(A6);
		sensorValues[1] = analogRead(A5);
		sensorValues[2] = analogRead(A4);
		sensorValues[3] = analogRead(A3);
		sensorValues[4] = analogRead(A2);
		sensorValues[5] = analogRead(A1);
		sensorValues[6] = analogRead(A0);

		blindright(); // rotates clockwise


		for (int i = 0; i < 7; i++) {
			if (sensorValues[i] > maximum[i]) {
				maximum[i] = sensorValues[i];
			}
			if (sensorValues[i] < minimum[i]) {
				minimum[i] = sensorValues[i];
			}
		}

	}
	for (int j = 0; j < 3000; j++) {
		/*		if (white_on_black == true) {
		readSensors_WOB();
		}
		if (black_on_white == true) {
		readSensors_BOW();
		} */

		sensorValues[0] = analogRead(A6);
		sensorValues[1] = analogRead(A5);
		sensorValues[2] = analogRead(A4);
		sensorValues[3] = analogRead(A3);
		sensorValues[4] = analogRead(A2);
		sensorValues[5] = analogRead(A1);
		sensorValues[6] = analogRead(A0);

		blindleft(); // rotates counter clockwise


		for (int i = 0; i < 7; i++) {
			if (sensorValues[i] > maximum[i]) {
				maximum[i] = sensorValues[i];
			}
			if (sensorValues[i] < minimum[i]) {
				minimum[i] = sensorValues[i];
			}
		}

	}
	stop();
	Serial.println("CCCCVVVV");
	for (int k = 0; k < 7; k++) {
		calibratedValue[k] = (minimum[k] + maximum[k]) / 2; //Assumption
		Serial.print(calibratedValue[k]);
		Serial.print(" ");
	}

	for (int i = 0; i < 7; i++) {
		EEPROM.write(i, map(calibratedValue[i], 0, 1023, 0, 255));
		delay(5);
	}
	//   Serial.end();
}
void printAnalogSensorValues() {
	// this function prints analog sensor values
	if (white_on_black == true) {
		readSensors_WOB();
	}
	if (black_on_white == true) {
		readSensors_BOW();
	}
	for (int i = 0; i < 7; i++) {
		Serial.print(sensorValues[i]);
		Serial.print("  ");
	}
	Serial.println();

}
void printDigitalSensorValues() {
	// this function prints digital sensor values
	if (white_on_black == true) {
		readSensors_WOB();
	}
	if (black_on_white == true) {
		readSensors_BOW();
	}
	for (int i = 0; i < 7; i++) {
		Serial.print(dv[i]);
		Serial.print("  ");
	}
	Serial.println();

}
void printAnalog() {
	// this function prints raw analog values
	Serial.print(analogRead(A6));
	Serial.println(" ");
	Serial.print(analogRead(A5));
	Serial.print(" ");
	Serial.print(analogRead(A4));
	Serial.print(" ");
	Serial.print(analogRead(A3));
	Serial.print(" ");
	Serial.print(analogRead(A2));
	Serial.print(" ");
	Serial.print(analogRead(A1));
	Serial.print(" ");
	Serial.print(analogRead(A0));
	Serial.print(" ");

}
void readSensors_WOB() {
	// white line on black track  //

	sensorValues[0] = analogRead(A6);
	sensorValues[1] = analogRead(A5);
	sensorValues[2] = analogRead(A4);
	sensorValues[3] = analogRead(A3);
	sensorValues[4] = analogRead(A2);
	sensorValues[5] = analogRead(A1);
	sensorValues[6] = analogRead(A0);


	for (int i = 0; i < 7; i++) {

		if (sensorValues[i] < calibratedValue[i]) { // gives 1 for white
			dv[i] = 1;
		}

		else if (sensorValues[i] > calibratedValue[i]) { // gives 0 for black
			dv[i] = 0;
		}
	}

}
void readSensors_BOW() {
	// black line on white track
	sensorValues[0] = analogRead(A6);
	sensorValues[1] = analogRead(A5);
	sensorValues[2] = analogRead(A4);
	sensorValues[3] = analogRead(A3);
	sensorValues[4] = analogRead(A2);
	sensorValues[5] = analogRead(A1);
	sensorValues[6] = analogRead(A0);


	for (int i = 0; i < 7; i++) {

		if (sensorValues[i] < calibratedValue[i]) { // gives 0 for white
			dv[i] = 0;
		}

		else if (sensorValues[i] > calibratedValue[i]) { // gives 1 for black
			dv[i] = 1;
		}
	}

}
void lineTrack() {
	//*** lineTrack ***//

	if (dv[2] == 0 && (dv[3] == 1 && dv[4] == 1) && dv[5] == 0) {
		// 00 x11x 00
		forward();
	}
	else if (dv[2] == 0 && (dv[3] == 0 && dv[4] == 1) && dv[5] == 1) {
		// 00 xx11 00
		rightzig();
	}

	else if (dv[2] == 1 && (dv[3] == 1 && dv[4] == 0) && dv[5] == 0) {
		// 00 11xx 00
		leftzig();
	}
	else if (dv[2] == 0 && (dv[3] == 1 && dv[4] == 1) && dv[5] == 1) {
		// 00 x111 00
		forward();
	}
	else if (dv[2] == 1 && (dv[3] == 1 && dv[4] == 1) && dv[5] == 0) {
		// 00 111x 00
		forward();
	}
	else if (dv[2] == 0 && (dv[3] == 0 && dv[4] == 0) && dv[5] == 1) {
		// 00 xxx1 00
		right();
	}
	else if (dv[2] == 1 && (dv[3] == 0 && dv[4] == 0) && dv[5] == 0) {
		// 00 1xxx 00
		left();
	}
/*	else if (dv[2] == 1 && (dv[3] == 0 && dv[4] == 0) && dv[5] == 1) {
		// 00 1xx1 00
		forward();
	}*/
	else if (dv[2] == 1 && dv[3] == 1 && dv[4] == 1 && dv[5] == 1) {
		// 00 1111 00
		forward();
	}
	/*
*/   	else if (dv[1] == 0 && dv[2] == 0 && dv[3] == 0 && dv[4] == 0 && dv[5] == 0 && dv[6] == 0 && count1<che && count2<che) {
// 00 xxxx 00

	stop();
	delay(100);
	node_D();
	stop();
}
	else if (dv[2] == 0 && dv[3] == 0 && dv[4] == 0 && dv[5] == 0) {
		forward();
	}

}
void flag_count()
{
	if (dv[1] == 1) {
		count1++;
	}
	if (dv[6] == 1) {
		count2++;
	}
	if (dv[1] == 1 && dv[2] == 1 && dv[3] == 1 && dv[4] == 1 && dv[5] == 1 && dv[6] == 1 && count1>che && count2> che) {
		// 00 xxxx 00

		stop();
		delay(100);
		node_END();
		stop();
		count1 = 0;
		count2 = 0;

	}
	else if (dv[1] == 0 && dv[6] == 0) {
		if (count1 < che) {
			count1 = 0;
		}
		if (count2 < che) count2 = 0;
		if (count1 > che && count2 > che) {
			Serial.println("1   1");

			count1 = 0;
			count2 = 0;

			readSensors_BOW();
			if (dv[2] == 1 || (dv[3] == 1 && dv[4] == 1) || dv[5] == 1) {
				nodeLeft_P();
			}
			else {

				nodeLeft_T();
			}
		}
		else if (count1 > che && count2 < che)
		{
			Serial.println("1  0");
			count1 = 0;
			count2 = 0;
			if (dv[2] == 1 || (dv[3] == 1 && dv[4] == 1) || dv[5] == 1) {
				nodeLeft_LF();
			}
			else{
				turnLeft_90();
			}

		}
		else if (count1 < che && count2 > che)
		{
			Serial.println("0  1");
			count1 = 0;
			count2 = 0;
			if (dv[2] == 1 || (dv[3] == 1 && dv[4] == 1) || dv[5] == 1) {
				nodeLeft_RF();
			}
			else {
				turnRight_90();
			}
		}
	}
}
void solvedflag_count()
{
	if (dv[1] == 1) {
		count1++;
	}
	if (dv[6] == 1) {
		count2++;
	}
	if (dv[1] == 1 && dv[2] == 1 && dv[3] == 1 && dv[4] == 1 && dv[5] == 1 && dv[6] == 1 && count1>che && count2> che) {
		// 00 xxxx 00

		stop();
		delay(100);
		solved_End();
		stop();
		count1 = 0;
		count2 = 0;

	}

	else if (dv[1] == 0 && dv[6] == 0) {
		if (count1 < che) {
			count1 = 0;
		}
		if (count2 < che) count2 = 0;
		if (count1 > che && count2 > che) {
			Serial.println("1   1");

			count1 = 0;
			count2 = 0;

			readSensors_BOW();
			if (dv[2] == 1 || (dv[3] == 1 && dv[4] == 1) || dv[5] == 1) {
				solved_P();
			}
			else {

				solved_T();
			}
		}
		else if (count1 > che && count2 < che)
		{
			Serial.println("1  0");
			count1 = 0;
			count2 = 0;
			if (dv[2] == 1 || (dv[3] == 1 && dv[4] == 1) || dv[5] == 1) {
				solved_LF();
			}
			else {
				turnLeft_90();
			}

		}
		else if (count1 < che && count2 > che)
		{
			Serial.println("0  1");
			count1 = 0;
			count2 = 0;
			if (dv[2] == 1 || (dv[3] == 1 && dv[4] == 1) || dv[5] == 1) {
				solved_RF();
			}
			else {
				turnRight_90();
			}
		}
	}
}
void nodeLeft_P() {
	//zero();
	flag = false;
	//forward_inch();
	stop_momentum();
	turnLeft_90_plus();
	stop_momentum();
	//zero();

	Serial.println("PLUS");

	way[l] = 'L';
	l++;
	simplify();
}
void nodeLeft_T() {
	//zero();
	flag = false;
	stop_momentum();
	turnLeft_90();
	stop_momentum();
	//zero();

	Serial.println("T");
	way[l] = 'L';
	l++;
	simplify();
}
void nodeLeft_RF() {
	zero();
	motors.setSpeeds(80, 80);
	zero();

	Serial.println("RF");
	way[l] = 'S';
	l++;
	simplify();
}
void nodeLeft_LF() {
	stop_momentum();
	turnLeft_90();
	/*	while(dv[4] == 1)
	{
	readSensors_BOW();
	blindleft();
	}
	while(dv[5] == 1)
	{
	readSensors_BOW();
	blindleft();
	}
	while(dv[4] == 0)
	{
	readSensors_BOW();
	blindleft();
	}
	while (dv[3] == 1 && dv[4] == 1)
	{
	readSensors_BOW();
	stop_momentum();
	break;
	} */
	stop_momentum();


	Serial.println("LF");
	way[l] = 'L';
	l++;
	simplify();
}
void nodeRight_P() {
	zero();
	forward_inch();
	stop_momentum();
	turnRight_90();
	stop_momentum();

	Serial.println("PLUS");

	way[l] = 'R';
	l++;
	simplify();

}
void nodeRight_T() {
	zero();
	stop_momentum();
	turnRight_90();
	stop_momentum();
	zero();

	Serial.println("T");
	way[l] = 'R';
	l++;
	simplify();
}
void nodeRight_RF() {
	zero();
	stop_momentum();
	turnRight_90();
	stop_momentum();
	zero();

	Serial.println("RF");
	way[l] = 'R';
	l++;
	simplify();
}
void nodeRight_LF() {
	zero();
	forward();
	zero();

	Serial.println("LF");
	way[l] = 'S';
	l++;
	simplify();
}
void node_D() {
	zero();
	//	led_HIGH();  // indication for dead node
	//	motors.setSpeeds(40, 40); // go forward a little
	//	delay(90);
	turnLeft_180();  // turn 180 degree
	stop_momentum();
	//	led_LOW();  // turning leds off

	Serial.println("Dead");
	way[l] = 'B';
	l++;
	simplify();
}
void node_END() {
	
    backward();
	delay(200);
	stop_momentum();
	turnLeft_180();
	stop_momentum();

	readSensors_BOW();
	stop();
	delay(1000);
	Serial.println("End");
	mazeSolved = 1;
	if (ck == 0)reverse();
/*
	for (int i = 0; i < l;i++) {
		Serial.println(spath[i]);
	}
	*/
}
void solved_P() {
	if (spath[l - 1] == 'S') {
		node_Straight();
	}
	if (spath[l - 1] == 'R') {
		stop();
		node_Right();
	}
	if (spath[l - 1] == 'L') {
		node_Left();
	}
	Serial.println("solved_P");
	l--;

}
void solved_T() {
	if (spath[l - 1] == 'R') {
		node_Right();
	}
	if (spath[l - 1] == 'L') {
		node_Left();
	}
	Serial.println("solved_T");
	l--;
}
void solved_RF() {
	if (spath[l - 1] == 'S') {
		node_Straight();
	}
	if (spath[l - 1] == 'R') {
		node_Right();
	}
	/*if (spath[z] == 'L') {
	node_Left();
	}*/
	Serial.println("solved_RF");
	l--;
}
void solved_LF() {
	if (spath[l - 1] == 'S') {
		node_Straight();
	}
	/*  if (spath[z] == 'R') {
	node_Right();
	}*/
	if (spath[l - 1] == 'L') {
		node_Left();
	}
	Serial.println("solved_LF");
	l--;
}
void solved_End() {
	while (1) {
		stop();
		buzzEnd();
	}
	//  digitalWrite(2, HIGH);
	//	led_last(); // blink the red led for 3 seconds
	//mazeSolved == 0;
	Serial.println("Solved_End");
}
void node_Straight() {
	// go straight in a node in solved run
	lineTrack();
}
void node_Right() {
	// turn right in a node in the solved run 
	stop_momentum();
	turnRight_90();
	stop_momentum();
	Serial.println("node_right");
}
void node_Left() {
	// turn left in a node in the solved run 
	stop_momentum();
	turnLeft_90();
	stop_momentum();

}
void forward() {
	LSpeed = forward_spd - 2.5; RSpeed = forward_spd;
	motors.setSpeeds(LSpeed, RSpeed);
}
void backward() {
	LSpeed = -50; RSpeed = -50;
	motors.setSpeeds(LSpeed, RSpeed);
}
void right() {
	LSpeed = forward_spd; RSpeed = turn_spd;
	motors.setSpeeds(LSpeed, RSpeed);
}
void left() {
	LSpeed = turn_spd; RSpeed = forward_spd;
	motors.setSpeeds(LSpeed, RSpeed);
}
void rightzig() {
	LSpeed = forward_spd; RSpeed = zig_spd;
	motors.setSpeeds(LSpeed, RSpeed);
}
void leftzig() {
	LSpeed = zig_spd; RSpeed = forward_spd;
	motors.setSpeeds(LSpeed, RSpeed);
}
void hardright() {
	// right turn without node
	backward();
	delay(10);
	stop_momentum();
	turnRight_90();
	stop_momentum();
	zero();
	Serial.println("Hard right");
}
void hardleft() {
	// left turn without node
	backward();
	delay(10);
	stop_momentum();
	turnLeft_90();
	stop_momentum();
	zero();
	Serial.println("Hard left");
}
void blindleft() {
	LSpeed = -100; RSpeed = 100;
	motors.setSpeeds(LSpeed, RSpeed);
}
void blindright() {
	LSpeed = 100; RSpeed = -100;
	motors.setSpeeds(LSpeed, RSpeed);
}
void blindForward() {
	LSpeed = 50; RSpeed = 50;
	motors.setSpeeds(LSpeed, RSpeed);
	delay(100);
}
void stop() {
	LSpeed = 0; RSpeed = 0;
	motors.setSpeeds(LSpeed, RSpeed);
}
void zero() {
	// turning all flag zero
	leftFlag = 0; rightFlag = 0;
}
void simplify() {
	if (l<3 || way[l - 2] != 'B')return;
	int t = 0, i;
	for (i = l - 3; i<l; i++)
	{
		if (way[i] == 'R')t += 90;
		if (way[i] == 'L')t += 270;
		if (way[i] == 'S')t += 0;
		if (way[i] == 'B')t += 180;
	}
	t %= 360;
	switch (t)
	{
	case 0:
		way[l - 3] = 'S';
		break;
	case 90:
		way[l - 3] = 'R';
		break;
	case 180:
		way[l - 3] = 'B';
		break;
	case 270:
		way[l - 3] = 'L';
	}

	l = l - 2;
}
void reverse()
{
	int i;
	for (i = 0; i<l; i++)
	{

		if (way[i] == 'L') spath[i] = 'R';


		else if (way[i] == 'R') spath[i] = 'L';

		else
			spath[i] = way[i];
	}
	ck = 1;
}
void led() {
	// this funcion turns leds on or of depending on line detection
	if (dv[1] == 1) {
		digitalWrite(led1, HIGH);
	}
	if (dv[1] == 0) {
		digitalWrite(led1, LOW);
	}
	if (dv[2] == 1) {
		digitalWrite(led2, HIGH);
	}
	if (dv[2] == 0) {
		digitalWrite(led2, LOW);
	}
	if (dv[3] == 1) {
		digitalWrite(led3, HIGH);
	}
	if (dv[3] == 0) {
		digitalWrite(led3, LOW);
	}
	if (dv[4] == 1) {
		digitalWrite(led4, HIGH);
	}
	if (dv[4] == 0) {
		digitalWrite(led4, LOW);
	}
	if (dv[5] == 1) {
		digitalWrite(led5, HIGH);
	}
	if (dv[5] == 0) {
		digitalWrite(led5, LOW);
	}
	if (dv[6] == 1) {
		digitalWrite(led6, HIGH);
	}
	if (dv[6] == 0) {
		digitalWrite(led6, LOW);
	}
}
void led_HIGH() {
	// turn all leds on
	digitalWrite(led1, HIGH);
	digitalWrite(led2, HIGH);
	digitalWrite(led3, HIGH);
	digitalWrite(led4, HIGH);
	digitalWrite(led5, HIGH);
	digitalWrite(led6, HIGH);
}
void led_LOW() {
	// turn all leds off
	digitalWrite(led1, LOW);
	digitalWrite(led2, LOW);
	digitalWrite(led3, LOW);
	digitalWrite(led4, LOW);
	digitalWrite(led5, LOW);
	digitalWrite(led6, LOW);
}
void ledTest() {
	led_HIGH();
	delay(100);
	led_LOW();
	delay(200);
}
void buz() {
	digitalWrite(buzzer, HIGH);
	//	delay(100);
	//	digitalWrite(buzzer,LOW);
	//	delay(100);
}
void buzz() {
	digitalWrite(buzzer, LOW);
	//	delay(50);
	//	digitalWrite(buzzer, LOW);
	//	delay(50);
	//	digitalWrite(buzzer, HIGH);
	//	delay(50);
	//	digitalWrite(buzzer, LOW);
	//	delay(50);
}
void buzzEnd() {
	digitalWrite(buzzer, HIGH);
	delay(100);
	digitalWrite(buzzer, LOW);
	delay(200);
}
void buttonTest() {
	if (!(digitalRead(buttonA))) {
		Serial.println("AAAAAAA released");
		digitalWrite(buzzer, LOW);
	}
	if ((digitalRead(buttonA))) {
		Serial.println("a Pressed");
		digitalWrite(buzzer, HIGH);
	}
	if (!(digitalRead(buttonB))) {

		Serial.println("BBBBBBBB released");
	}
	if ((digitalRead(buttonB))) {
		buzz();
		Serial.println("b Pressed");
	}
	if (!(digitalRead(buttonSelect))) {
		Serial.println("sssSelecTttt released");
	}
	if ((digitalRead(buttonSelect))) {
		buz();
		Serial.println("Select pressed");
	}
}
void checkButton() {
	// first step == white track / black track
	while (!digitalRead(buttonSelect)) { ; }
	if ((digitalRead(buttonSelect))) { ; }
	while ((!digitalRead(buttonA)) && (!digitalRead(buttonB))) {}
	if ((digitalRead(buttonB))) {
		// for selecting black track
		white_on_black = true;
	}
	if ((digitalRead(buttonA))) {
		//  for selecting white track
		black_on_white = true;
	}
	while (!digitalRead(buttonSelect)) { ; }
	// second step == left hand rule / right hand rule
	while (!digitalRead(buttonSelect)) { ; }
	if ((digitalRead(buttonSelect))) { ; }
	while ((!digitalRead(buttonA)) && (!digitalRead(buttonB))) {}

	if ((digitalRead(buttonB))) {
		left_hand_rule = true;
	}
	if ((digitalRead(buttonA))) {
		right_hand_rule = true;
	}
	while (!digitalRead(buttonSelect)) { ; }
	// third step == calibration
	while (!digitalRead(buttonSelect)) { ; }
	if ((digitalRead(buttonSelect))) { ; }
	while ((!digitalRead(buttonA)) && (!digitalRead(buttonB))) {}

	if ((digitalRead(buttonB))) {
		eepromRead();
		for (int k = 0; k < 7; k++) {
			Serial.print(EEPROM.read(k));
		}
	}
	if ((digitalRead(buttonA))) {

		calibrateSensors();
		delay(5000);
		eepromRead();
	}
}
void turnRight_90() {
	// predefined 90 degree right turn
	/*motors.setSpeeds(pred_spd, -pred_spd-5);
	delay(times);*/
	motors.setSpeeds(pred_spd, -pred_spd);
	delay(times - 3);
	forward();
	delay(50);
}
void turnLeft_90_plus() {
	motors.setSpeeds(-pred_spd, pred_spd);
	delay(times - 3);
	forward();
	delay(50);
}
void turnLeft_90() {
	// predefined 90 degree left turn
	motors.setSpeeds(-pred_spd, pred_spd);
	delay(times - 3);
	forward();
	delay(50);
	/*while (dv[2] == 0) {
	readSensors_BOW();
	motors.setSpeeds(-pred_spd, pred_spd);
	}*/
	/*while (dv[2] == 1) {
	readSensors_BOW();
	motors.setSpeeds(-pred_spd, pred_spd + 5);
	}*/
	/*stop();
	motors.setSpeeds(-pred_spd, pred_spd + 5);
	delay(times-3);*/
}
void turnLeft_180() {
	// predefined 180 degree turn
	motors.setSpeeds(-pred_spd, pred_spd);
	delay(times * 2);
}
void turnRight_180() {
	motors.setSpeeds(pred_spd, -pred_spd);
	delay(410);
}
void forward_inch() {
	// go forward a little
	motors.setSpeeds(pred_spd, pred_spd);
	delay(10);
}
void backward_inch() {
	// go backward a bit
	motors.setSpeeds(-pred_spd, -pred_spd);
	delay(180);
}
void stop_momentum() {
	LSpeed = 0; RSpeed = 0;
	motors.setSpeeds(LSpeed, RSpeed);
	delay(50);
}
