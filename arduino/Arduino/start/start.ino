
int Irvalue = 0;
/*counter*/
const int distance_data = 13;
const int count_data = 6;
const int count_data6 = 7;
const int count_data12 = 12;

/*Linefollower*/
int distance1;


const int motorLFPin = 8; // signal pin 1 for the right motor, connect to IN1
const int motorLFEnable = 9; // enable pin for the right motor (PWM enabled)

const int motorLBPin = 10; // signal pin 1 for the left motor, connect to IN3
const int motorLBEnable = 11; // enable pin for the left motor (PWM enabled)

const int motorRFPin = 2; // signal pin 1 for the right motor, connect to IN1
const int motorRFEnable = 3; // enable pin for the right motor (PWM enabled)

const int motorRBPin = 4; // signal pin 1 for the left motor, connect to IN3
const int motorRBEnable = 5; // enable pin for the left motor (PWM enabled)



int motorLSpeed_start = 150;
int motorRSpeed_start = 150;


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

void setup() {


pinMode(motorLFPin,OUTPUT);
pinMode(motorLFEnable,OUTPUT);
pinMode(motorLBPin,OUTPUT);
pinMode(motorLBEnable,OUTPUT);
pinMode(motorRFPin,OUTPUT);
pinMode(motorRFEnable,OUTPUT);
pinMode(motorRBPin,OUTPUT);
pinMode(motorRBEnable,OUTPUT);
Serial.begin(9600);

  /* Set-up IR sensor pins as input */
for (int i = 0; i <= 7; i++)
{pinMode(irPinsF[i], INPUT);}
for (int i = 0; i <= 7; i++)
{pinMode(irPinsM[i], INPUT);}
/*
while(1){
  scanD();
 
  initial_check();
   movingleft();// here it moves from 
  Serial.println(Irvalue);
  if (Irvalue == 1) {
    stopme();
      break;
 }
}
*/
}

void loop(){
movingleft();


}



void initial_check(){

    switch (irSensors_Front) {

    


     case B00111000:
     Irvalue = 1;
     break;

     case B00011100:
       Irvalue = 1;
     break;

     case B00001110:
       Irvalue = 1;
     break;

     case B00000111:
       Irvalue = 1;

       

  }

 
}


void movingleft()  //turn left
{
     Serial.println("                        movingleft");
     analogWrite(motorLFEnable, motorRSpeed_start);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed_start);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed_start);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed_start);
     digitalWrite(motorRBPin, LOW);

}


void movingright()  //right
{
     Serial.println("                         movingright");
     analogWrite(motorLFEnable, motorRSpeed_start);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed_start);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed_start);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed_start);
     digitalWrite(motorRBPin, HIGH);

}

void scanD()
{
  for ( byte count = 0; count < 8;count++ )
{
  bitWrite(irSensors_Front, count, !digitalRead( irPinsF[count] ));
}
//Serial.println(irSensors_Front);
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
