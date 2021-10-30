/*
Nama: Giga Hidjrika Aura Adkhy
NIM : 21/479228/TK/52833
*/

//Pin declaration using const int
const int enablePin1 = 2;	//Enable pin for driver
const int inputPin1 = 3;	//input pin 1 for driver
const int inputPin2 = 4;	//input pin 2 for driver

const int enablePin2 = 5;
const int inputPin3 = 6;
const int inputPin4 = 7;

void setup()
{
  //Set the pins as OUTPUT
  pinMode(enablePin1, OUTPUT);
  pinMode(inputPin1, OUTPUT);
  pinMode(inputPin2, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  pinMode(inputPin3, OUTPUT);
  pinMode(inputPin4, OUTPUT);
  
  //Initial motor state OFF
  digitalWrite(inputPin1, LOW);
  digitalWrite(inputPin2, LOW);
  digitalWrite(inputPin3, LOW);
  digitalWrite(inputPin4, LOW);
  Serial.begin(9600);
}

void loop()
{
  //Turn on Clockwise, then off, then Counter CW, then off, repeat
  turnOnCW();
  turnOff();
  turnOnCCW();
  turnOff();
}

void turnOnCCW()
{
  //print to serial monitor as checker
  Serial.print("CCW ON\n");
  digitalWrite(inputPin1, HIGH); //rotate the motor
  digitalWrite(inputPin2, LOW);  //Counter clockwise
  analogWrite(enablePin1, 255);  //Set the speed to maximum (8-bit)
  
  digitalWrite(inputPin3, HIGH); //second motor rotation
  digitalWrite(inputPin4, LOW);
  analogWrite(enablePin2, 255);
  delay(3000);   //do this for 3 seconds
}

void turnOnCW()
{
  Serial.print("CW ON\n");
  digitalWrite(inputPin1, LOW);  //rotate the motor
  digitalWrite(inputPin2, HIGH); //Clockwise
  analogWrite(enablePin1, 255);  //Set the speed to maximum (8-bit)
  
  digitalWrite(inputPin3, LOW); //second motor rotation
  digitalWrite(inputPin4, HIGH);
  analogWrite(enablePin2, 255);
  delay(3000);
}

void turnOff()
{
  Serial.print("OFF\n");
  digitalWrite(inputPin1, LOW);  //Turn off first motor
  digitalWrite(inputPin2, LOW);
  
  digitalWrite(inputPin3, LOW);  //Turn off second motor
  digitalWrite(inputPin4, LOW);
  delay(3000);
}
