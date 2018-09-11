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

int motorLSpeed = 255;
int motorRSpeed = 255;
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
/*
Serial.print("Distace: ");
Serial.println(distance);

Serial.print("Distace1:");
Serial.println(distance1); */

}





void check( )
{
  Serial.print("Counter = ");
  Serial.println(counter);

      if (distance1 <= 10){
      stopme();
    }
    if(counter == 3){
      Serial.println("Turn Around");
    }
  else{
     switch (irSensors_Front) {

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
     Go_Front();
     break;

     case B00001100:
     SoftleftS();
     break;

     case B00000110:
     HardleftS();
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
     SoftleftS1();
     break;

     case B00000111:
     SoftleftS1();
     break;
/*here we have straght line*/
     case B11110000:
     SoftrightS2();
     break;

     case B01111000:
      SoftrightS3();
     break;

     case B00111100:
     Go_Front();
     break;

     case B00011110:
     SoftleftS3();
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
     Go_Front();
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
       analogWrite(motorLFEnable, motorRSpeed);
       digitalWrite(motorLFPin, LOW);
  
  
       analogWrite(motorLBEnable, motorLSpeed);
       digitalWrite(motorLBPin, LOW);
       
       analogWrite(motorRFEnable, motorRSpeed/1.4);
       digitalWrite(motorRFPin, LOW);
  
  
       analogWrite(motorRBEnable, motorLSpeed/1.4);
       digitalWrite(motorRBPin, LOW);
  
  
  }


void SoftleftS2()  //turn left
{
     Serial.println("                         Softleft2");
     analogWrite(motorLFEnable, motorRSpeed/1.4);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/1.4);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);


}


void SoftleftS3()  //turn left
{
     Serial.println("                         Softleft3");
     analogWrite(motorLFEnable, motorRSpeed/1.2);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/1.2);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);


}



void SoftrightS1()

{
     Serial.println("                      SoftrightS1");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed/1.6);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed/1.6);
     digitalWrite(motorRBPin, LOW);



}

void SoftrightS3()

{
     Serial.println("                      SoftrightS1");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed/1.1);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed/1.1);
     digitalWrite(motorRBPin, LOW);



}

void SoftleftS1()  //turn left
{
     Serial.println("                         Softleft1");
     analogWrite(motorLFEnable, motorRSpeed/1.6);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/1.6);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);
}





void SoftrightS()

{
     Serial.println("                      softRight");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, LOW);
       
     analogWrite(motorRFEnable, motorRSpeed/1.8);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed/1.8);
     digitalWrite(motorRBPin, LOW);


}


void SoftleftS()  //turn left
{
     Serial.println("                         softleft");
     analogWrite(motorLFEnable, motorRSpeed/1.8);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/1.8);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);

}



void HardrightS()

{
     Serial.println("                      HardRight");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed/2);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed/2);
     digitalWrite(motorRBPin, LOW);


}


void HardleftS()  //turn left
{
     Serial.println("                         Hardleft");
     analogWrite(motorLFEnable, motorRSpeed/2);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/2);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);

}

void Go_Front()
{
    Serial.println("                         forward ");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);

}

void stopme()
{
     Serial.println("                         stop");
     analogWrite(motorLFEnable, 0);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, 0);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, 0);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, 0);
     digitalWrite(motorRBPin, LOW);

}

void Go_Back()
{
    Serial.println("                         forward ");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, HIGH);

}




void scanD()
{
  for ( byte count = 0; count < 8;count++ )
{
  bitWrite(irSensors_Front, count, !digitalRead( irPinsF[count] ));
}
}


void Turnleft()
{
  /*move left to find the line!*/


     Serial.println("                         search");
    analogWrite(motorLFEnable, 0);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, 0);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, 150);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, 150);
     digitalWrite(motorRBPin, LOW);

     delay(500);

}


void Turnright()
{
  /*move left to find the line!*/


     Serial.println("                         search");
     analogWrite(motorLFEnable, 150);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, 150);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, 0);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, 0);
     digitalWrite(motorRBPin, LOW);

     delay(500);

}




void Hardright()

{
     Serial.println("                      HardRight");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed/3);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed/3);
     digitalWrite(motorRBPin, LOW);



}


void Hardleft()  //turn left
{
     Serial.println("                         Hardleft");
     analogWrite(motorLFEnable, motorRSpeed/3);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/3);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);


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

 /*Serial.println(counter);*/
 }

