const int trigpin = 37;
const int echopin = 35;
const int trigpin1  = 31;
const int echopin1 = 33;

long duration;
int distance;
long duration1;
int distance1;

/*counter*/

 int counter = 0;
 boolean isobject = false;

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
     count();


}



void distace()
{
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
      if (distance1 <= 10){
      stopme();
    }
  else{
     switch (irSensors) {

     case B00000000: // on white paper
     HardrightS();
     break;

     case B10000000: // leftmost sensor on the line
     Hardright();
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
     Hardleft();
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
     SoftrightS1();
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
     SoftleftS1();
     break;
/*here we have straght line*/
     case B11110000:
     SoftrightS2();
     break;

     case B01111000:
      SoftrightS2();
     break;

     case B00111100:
     go();
     break;

     case B00011110:
     SoftleftS2();
     break;

     case B00001111:
     SoftleftS2();
     break;
/*bigger than straight line */

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

void SoftrightS2()

{
     Serial.println("                      Softright2");
     analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, LOW);


     analogWrite(motorLEnable, motorLSpeed/1.4);
     digitalWrite(motorLPin1, LOW);


}


void SoftleftS2()  //turn left
{
     Serial.println("                         Softleft2");
     analogWrite(motorREnable, motorRSpeed/1.4);
     digitalWrite(motorRPin1, LOW);

     analogWrite(motorLEnable, motorLSpeed);
     digitalWrite(motorLPin1, LOW);

}




void SoftrightS1()

{
     Serial.println("                      SoftrightS1");
     analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, LOW);


     analogWrite(motorLEnable, motorLSpeed/1.6);
     digitalWrite(motorLPin1, LOW);


}


void SoftleftS1()  //turn left
{
     Serial.println("                         Softleft1");
     analogWrite(motorREnable, motorRSpeed/1.6);
     digitalWrite(motorRPin1, LOW);

     analogWrite(motorLEnable, motorLSpeed);
     digitalWrite(motorLPin1, LOW);

}





void SoftrightS()

{
     Serial.println("                      softRight");
     analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, LOW);


     analogWrite(motorLEnable, motorLSpeed/1.8);
     digitalWrite(motorLPin1, LOW);


}


void SoftleftS()  //turn left
{
     Serial.println("                         softleft");
     analogWrite(motorREnable, motorRSpeed/1.8);
     digitalWrite(motorRPin1, LOW);

     analogWrite(motorLEnable, motorLSpeed);
     digitalWrite(motorLPin1, LOW);


}



void HardrightS()

{
     Serial.println("                      HardRight");
     analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, LOW);


     analogWrite(motorLEnable,motorLSpeed/2);
     digitalWrite(motorLPin1, LOW);


}


void HardleftS()  //turn left
{
     Serial.println("                         Hardleft");
     analogWrite(motorREnable, motorRSpeed/2);
     digitalWrite(motorRPin1, LOW);

     analogWrite(motorLEnable, motorLSpeed);
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




void Hardright()

{
     Serial.println("                      HardRight");
     analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, LOW);


     analogWrite(motorLEnable,motorLSpeed/3);
     digitalWrite(motorLPin1, LOW);


}


void Hardleft()  //turn left
{
     Serial.println("                         Hardleft");
     analogWrite(motorREnable, motorRSpeed/3);
     digitalWrite(motorRPin1, LOW);

     analogWrite(motorLEnable, motorLSpeed);
     digitalWrite(motorLPin1, LOW);


}


void count()
{  
 if (distance <= 10 && isobject==false){
 counter +=1;
 isobject =true;
 delay(1000);
 }
 if(distance > 20)
 {
 isobject =false;
 }

 Serial.println(counter);
 }


