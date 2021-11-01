#include <IRremote.h>
#include <Servo.h>

Servo myservo;
int value;
double angle;

int RECV_PIN_1 = 6;
int RECV_PIN_2 = 2;
const int pingPin = 7;
const int ledPin = 4;

decode_results results;

void setup()
{
  pinMode(13, OUTPUT); // Motor A +
  pinMode(12, OUTPUT); // Motor A -
  pinMode(11, OUTPUT); // Enable 1&2
  pinMode(10, OUTPUT); // Enable 3&4 
  pinMode (9, OUTPUT); // Motor B -
  pinMode (8, OUTPUT); // Motor B + 
  pinMode(ledPin, OUTPUT);
  myservo.attach(2);
  Serial.begin(9600);

}

void loop()
{
 forward();
  int starttime=millis();
  int endtime=starttime;
  while((endtime-starttime)<=5000)
  {
    distance();
    endtime=millis();
  }
 //delay(3000);
 left();
  delay(3000);
  /*
   while((endtime-starttime)<=3000)
  {
    distance();
    endtime=millis();
  }*/
}

// Declaring Functions
void forward()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  analogWrite(11, 80);
  analogWrite(10, 80);
  
}

void left()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  analogWrite(11, 70);
  analogWrite(10, 50);
}

void right()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  analogWrite(11, 50);
  analogWrite(10, 70);
}

void stop()
{
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  analogWrite(11, 0);
  analogWrite(10, 0);
}
long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
void distance(){
long duration, cm;

   pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

   pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  // Print the distance
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  // Turn on the LED if the object is too close:
  /*if(cm<5){
  	forward();
    myservo.write(-90);                 
  	delay(15);
	}
  else */
  if(cm<5){
    //myservo.write(-180);
    digitalWrite(ledPin, LOW);
    forward();
  }
  if(cm < 100) {
    stop();
    int angle = map(cm, 0, 100, 0, 180); 
  //Serial.println(angle);
     myservo.write(angle);
    digitalWrite(ledPin, HIGH);
  	delay(15);
  }
  else{
  digitalWrite(ledPin, LOW);
  forward();
  }
 }

