const int trigpin = 37;
const int echopin = 35;
const int trigpin1  = 31;
const int echopin1 = 33;

long duration;
int distance;
long duration1;
int distance1;


/*Linefollower*/


const int motorRPin1 = 22; // signal pin 1 for the right motor, connect to IN1
const int motorREnable = 11; // enable pin for the right motor (PWM enabled)

const int motorLPin1 = 23; // signal pin 1 for the left motor, connect to IN3
const int motorLEnable = 12; // enable pin for the left motor (PWM enabled)

const int irPins[8] = {39,41,43,45,47,49,51,53};
int irSensorDigital[8] = {0,0,0,0,0,0,0,0};
int i,j = 0;
int d = 1000;

int irSensors = B00000000;

int motorLSpeed = 70;
int motorRSpeed = 70;
int error = 140;   // 145 best 200  //  normal 255  // mad 0



void setup() {
/*ultrasonic*/
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(trigpin1,OUTPUT);
pinMode(echopin1,INPUT);
Serial.begin(9600);
/*Linefollower*/


pinMode(motorLPin1,OUTPUT);
pinMode(motorLEnable,OUTPUT);
pinMode(motorRPin1,OUTPUT);
pinMode(motorREnable,OUTPUT);
  /* Set-up IR sensor pins as input */
for (int i = 0; i <= 7; i++)
{pinMode(irPins[i], INPUT);}


Turnleft();
delay(250);
go();
delay(570);
Turnright();
delay(140);
stopme();
}



void loop()
{
     scanD();
     check();
     distace();


}



void distace() {
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
duration = pulseIn(echopin,HIGH);
distance = duration*0.034/2;

digitalWrite(trigpin1,LOW);
delayMicroseconds(2);
digitalWrite(trigpin1,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin1,LOW);
duration1 = pulseIn(echopin1,HIGH);
distance1 = duration1*0.034/2;
Serial.print("Distace: ");
Serial.println(distance);
Serial.print("Distace1:");
Serial.println(distance1);

}





void check( )
{
      if (distance1 <= 15){
      stopme();
    }
  else{
     switch (irSensors) {

     case B00000000: // on white paper
     HardrightS();
     break;

     case B10000000: // leftmost sensor on the line
     HardrightS();
     break;

     case B01000000:
     SoftrightS();
     break;

     case B00100000:
     HardrightS();
     break;


     case B00010000:
     SoftrightS();
     break;

     case B00001000:
     SoftleftS();
     break;

     case B00000100:
     HardleftS();
     break;

     case B00000010:
     HardleftS();
     break;

     case B00000001:
     HardleftS();
     break;

     case B11000000:
     HardrightS();
     break;

     case B01100000:
     SoftrightS();
     break;

     case B00110000:
     SoftrightS();
     break;

     case B00011000:
     go();
     break;

     case B00001100:
     SoftleftS();
     break;

     case B00000110:
     SoftleftS();
     break;

     case B00000011:
     HardleftS();
     break;

     case B11100000:
     SoftrightS();
     break;

     case B01110000:
     SoftrightS();
     break;

     case B00111000:
     SoftrightS();
     break;

     case B00011100:
     SoftleftS();
     break;

     case B00001110:
     SoftleftS();
     break;

     case B00000111:
     SoftleftS();
     break;

     case B11110000:
     SoftrightS1();
     break;

     case B01111000:
      SoftrightS1();
     break;

     case B00111100:
     go();
     break;

     case B00011110:
     SoftleftS1();
     break;

     case B00001111:
     SoftleftS();
     break;

     case B11111000:
     SoftrightS();
     break;

     case B01111100:
     SoftrightS();
     break;

     case B00111110:
     SoftleftS();
     break;

     case B00011111:
     SoftleftS();
     break;

     case B11111100:
     SoftrightS();
     break;

     case B01111110:
     go();
     break;

     case B00111111:
     SoftleftS();
     break;


     case B11111110:
     SoftrightS();
     break;

     case B01111111:
     SoftleftS();
     break;

     case B11111111:
      stopme();

     break;


     default:

     Serial.print("Unhandled case: ");

  }

}

}
void SoftrightS1()

{
     Serial.println("                      right motor forward (spin)");
     analogWrite(motorREnable, motorRSpeed-error);
     digitalWrite(motorRPin1, LOW);


     analogWrite(motorLEnable, motorLSpeed/1.05);
     digitalWrite(motorLPin1, LOW);


}


void SoftleftS1()  //turn left
{
     Serial.println("                         left  motor forward (spin)");
     analogWrite(motorREnable, motorRSpeed/1.05);
     digitalWrite(motorRPin1, LOW);

     analogWrite(motorLEnable, motorLSpeed-error);
     digitalWrite(motorLPin1, LOW);

}





void SoftrightS()

{
     Serial.println("                      right motor forward (spin)");
     analogWrite(motorREnable, motorRSpeed-error);
     digitalWrite(motorRPin1, LOW);


     analogWrite(motorLEnable, motorLSpeed/1.15);
     digitalWrite(motorLPin1, LOW);


}


void SoftleftS()  //turn left
{
     Serial.println("                         left  motor forward (spin)");
     analogWrite(motorREnable, motorRSpeed/1.15);
     digitalWrite(motorRPin1, LOW);

     analogWrite(motorLEnable, motorLSpeed-error);
     digitalWrite(motorLPin1, LOW);


}



void HardrightS()

{
     Serial.println("                      right motor forward (spin)");
     analogWrite(motorREnable, motorRSpeed-error);
     digitalWrite(motorRPin1, LOW);


     analogWrite(motorLEnable,motorLSpeed/1.3);
     digitalWrite(motorLPin1, LOW);


}


void HardleftS()  //turn left
{
     Serial.println("                         left  motor forward (spin)");
     analogWrite(motorREnable, motorRSpeed/1.3);
     digitalWrite(motorRPin1, LOW);

     analogWrite(motorLEnable, motorLSpeed-error);
     digitalWrite(motorLPin1, LOW);


}

void go()
{
    Serial.println("                         forward ");
     analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, LOW);

     analogWrite(motorLEnable,motorLSpeed );
     digitalWrite(motorLPin1, LOW);


}

void stopme()
{
     Serial.println("                         stop");
     analogWrite(motorREnable, 0);
     digitalWrite(motorRPin1, LOW);


     analogWrite(motorLEnable, 0);
     digitalWrite(motorLPin1, LOW);


}




void scanD()
{
  for ( byte count = 0; count < 8;count++ )
{
  bitWrite(irSensors, count, !digitalRead( irPins[count] ));
}
}


void Turnleft()
{
  /*move left to find the line!*/


     Serial.println("                         search");
     analogWrite(motorREnable, 150);
     digitalWrite(motorRPin1, HIGH);

     analogWrite(motorLEnable, 0);
     digitalWrite(motorLPin1, LOW);

     delay(500);

}


void Turnright()
{
  /*move left to find the line!*/


     Serial.println("                         search");
     analogWrite(motorREnable, 0);
     digitalWrite(motorRPin1, LOW);

     analogWrite(motorLEnable, 150);
     digitalWrite(motorLPin1, LOW);

     delay(500);

}

