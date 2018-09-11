const int trigpin = 23;
const int echopin = 25;
const int trigpin1  = 27;
const int echopin1 = 29;

long duration;
int distance;
long duration1;
int distance1;

/*counter*/

 int counter = 0;
 boolean isobject = false;

/*Linefollower*/


const int motorLFPin = 2; // signal pin 1 for the right motor, connect to IN1
const int motorLFEnable = 3; // enable pin for the right motor (PWM enabled)

const int motorLBPin = 4; // signal pin 1 for the left motor, connect to IN3
const int motorLBEnable = 5; // enable pin for the left motor (PWM enabled)

const int motorRFPin = 6; // signal pin 1 for the right motor, connect to IN1
const int motorRFEnable = 7; // enable pin for the right motor (PWM enabled)

const int motorRBPin = 8; // signal pin 1 for the left motor, connect to IN3
const int motorRBEnable = 9; // enable pin for the left motor (PWM enabled)



const int irPinsF[8] = {22,24,26,28,30,32,34,36};
const int irPinsM[8] = {38,40,42,44,46,48,50,52};
int irSensorDigitalF[8] = {0,0,0,0,0,0,0,0};
int irSensorDigitalM[8] = {0,0,0,0,0,0,0,0};
int i,j = 0;
int d = 1000;

int irSensors_Front= B00000000;
int irSensors_Middle= B00000000;

int motorLSpeed = 100;
int motorRSpeed = 100;
int error = 140;   // 145 best 200  //  normal 255  // mad 0



void setup() {
/*ultrasonic*/
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(trigpin1,OUTPUT);
pinMode(echopin1,INPUT);
Serial.begin(9600);
/*Linefollower*/


pinMode(motorLFPin,OUTPUT);
pinMode(motorLFEnable,OUTPUT);
pinMode(motorLBPin,OUTPUT);
pinMode(motorLBEnable,OUTPUT);
pinMode(motorRFPin,OUTPUT);
pinMode(motorRFEnable,OUTPUT);
pinMode(motorRBPin,OUTPUT);
pinMode(motorRBEnable,OUTPUT);
  /* Set-up IR sensor pins as input */
for (int i = 0; i <= 7; i++)
{pinMode(irPinsF[i], INPUT);}
for (int i = 0; i <= 7; i++)
{pinMode(irPinsM[i], INPUT);}



}



void loop()
{
    /* scanD();
     check();
     distace();
     count();
*/
Go_Front();

}
void Go_Front()
{
    Serial.println("                         forward ");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/1.4);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed/1.4);
     digitalWrite(motorRBPin, LOW);
}
