//For TinkerCAD version: https://www.tinkercad.com/things/7Ym7eT9OgIe-ultrasonic-actuator/editel

/*
Nama: Giga Hidjrika Aura Adkhy
NIM: 21/479228/TK/52833
*/

//define Pins
#define echoPin 4
#define trigPin 5
#define motorPin 3

//declare variables for ultrasonic sensor
long time;
int distance;

void setup() {
  //Set pins as output and input
  pinMode(trigPin, OUTPUT);		//trigger as output (transmits ultrasonic wave)
  pinMode(echoPin, INPUT);		//echo as input (receives ultrasonic wave
  pinMode(motorPin, OUTPUT);	//actuator (DC motor)
  
  Serial.begin(9600); 
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  time = pulseIn(echoPin, HIGH);
  distance = time * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if(distance < 100)
  {
    digitalWrite(motorPin, HIGH);
    analogWrite(motorPin, 255);
  }
  else
  {
    digitalWrite(motorPin, LOW);
  }
}
