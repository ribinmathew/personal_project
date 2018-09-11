int goback;
int back_line;
int Irvalue;

/*Linefollower*/
int distance1;

int count3;
const int motorLFPin = 8; // signal pin 1 for the right motor, connect to IN1
const int motorLFEnable = 9; // enable pin for the right motor (PWM enabled)

const int motorLBPin = 10; // signal pin 1 for the left motor, connect to IN3
const int motorLBEnable = 11; // enable pin for the left motor (PWM enabled)

const int motorRFPin = 2; // signal pin 1 for the right motor, connect to IN1
const int motorRFEnable = 3; // enable pin for the right motor (PWM enabled)

const int motorRBPin = 4; // signal pin 1 for the left motor, connect to IN3
const int motorRBEnable = 5; // enable pin for the left motor (PWM enabled)



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



int motorLSpeed_start = 150;
int motorRSpeed_start = 150;




void setup() {
/*ultrasonic*/

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

 while (1){
   scanD();
    scan_backline();
   
    if (back_line == 1){
      back_line =0;
      stopme();
      break;
       }
  
   reverse_check();
  }
  stopme();
  delay(500);
Go_Front();
delay(1000);

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

  
}
void loop(){
  stopme();
}


void scanD()
{
  for ( byte count = 0; count < 8;count++ )
{
  bitWrite(irSensors_Front, count, !digitalRead( irPinsF[count] ));
}
//Serial.println(irSensors_Front);
}





void  reverse_check(){
   
     switch (irSensors_Front) {

     case B00000000: // on white paper
     stopme();
     break;

     case B10000000: // leftmost sensor on the line
     HardleftS();
     break;

     case B01000000:
     HardleftS();
     break;

     case B00100000:
     HardleftS();
     break;


     case B00010000:
     SoftrightS();
     break;

     case B00001000:
     SoftrightS();
     break;

     case B00000100:
     HardrightS();
     break;

     case B00000010:
     HardrightS();
     break;

     case B00000001:
     HardrightS();
     break;

     case B11000000:
     HardleftS();
     break;

     case B01100000:
     SoftleftS2();
     break;

     case B00110000:
     SoftleftS4();
     break;

     case B00011000:
     Go_Back();
     break;

     case B00001100:
     SoftrightS3();
     break;

     case B00000110:
     SoftrightS3();
     break;

     case B00000011:
     HardrightS();
     break;

     case B11100000:
     SoftleftS2();
     break;

     case B01110000:
     SoftleftS3();
     break;

     case B00111000:
     Go_Back();
     break;

     case B00011100:
     Go_Back();
     break;

     case B00001110:
     SoftrightS3();
     break;

     case B00000111:
     
     break;
/*here we have straght line*/
     case B11110000:
     SoftleftS4();
     break;

     case B01111000:
      SoftleftS5();
     break;

     case B00111100:
     Go_Back();
     break;

     case B00011110:
     SoftrightS5();
     break;

     case B00001111:
     SoftrightS4();
     break;
/*bigger than straight line */

     case B11111000:
     SoftleftS5();
     break;

     case B01111100:
     SoftleftS5();
     break;

     case B00111110:
     SoftrightS5();
     break;

     case B00011111:
     SoftrightS5();
     break;

     case B11111100:
     SoftleftS5();
     break;

     case B01111110:
     Go_Back();
     break;

     case B00111111:
     SoftrightS();
     break;


     case B11111110:
     SoftleftS();
     break;

     case B01111111:
     SoftrightS();
 
     case B11111111:
      stopme();

     break;



     default:
 Go_Back();
     Serial.print("Unhandled case: ");

  


}
}










void SoftrightS()  //turn left
{
     Serial.println("                         softrightS");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed/1.6);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed/1.6);
     digitalWrite(motorRBPin, HIGH);

}





void SoftleftS()  //turn left
{
     Serial.println("                         softleft");
     analogWrite(motorLFEnable, motorRSpeed/1.6);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed/1.6);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, HIGH);

}




void SoftrightS1()

{
     Serial.println("                      SoftrightS1");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed/1.5);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed/1.5);
     digitalWrite(motorRBPin, HIGH);


}

void SoftleftS1()  //turn left
{
     Serial.println("                         Softlefts1");
     analogWrite(motorLFEnable, motorRSpeed/1.5);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed/1.5);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, HIGH);
}








void   SoftrightS2()

{
     Serial.println("                      Softright2");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed/1.4);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed/1.4);
     digitalWrite(motorRBPin, HIGH);


}

void SoftleftS2()  //turn left
{
     Serial.println("                         Softleft2");
     analogWrite(motorLFEnable, motorRSpeed/1.4);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed/1.4);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, HIGH);
}





void SoftrightS3()

{
     Serial.println("                      SoftrightS3");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed/1.3);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed/1.3);
     digitalWrite(motorRBPin, HIGH);



}

void SoftleftS3()  //turn left
{
     Serial.println("                         Softleft3");
     analogWrite(motorLFEnable, motorRSpeed/1.3);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed/1.3);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, HIGH);


}


void SoftrightS4()

{
     Serial.println("                      softRight4");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, HIGH);
       
     analogWrite(motorRFEnable, motorRSpeed/1.2);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed/1.2);
     digitalWrite(motorRBPin, HIGH);


}

void SoftleftS4()  //turn left
{
     Serial.println("                         Softleft4");
     analogWrite(motorLFEnable, motorRSpeed/1.2);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed/1.2);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, HIGH);


}


void SoftrightS5()

{
     Serial.println("                      SoftrightS5");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed/1.1);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed/1.1);
     digitalWrite(motorRBPin, HIGH);



}


void SoftleftS5()  //turn left
{
     Serial.println("                         Softleft5");
     analogWrite(motorLFEnable, motorRSpeed/1.1);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed/1.1);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, HIGH);


}


void HardrightS()

{
     Serial.println("                      HardRightS");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed/2);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed/2);
     digitalWrite(motorRBPin, HIGH);


}


void HardleftS()  //turn left
{
     Serial.println("                         HardleftS");
     analogWrite(motorLFEnable, motorRSpeed/2);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed/2);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, HIGH);

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
    Serial.println("                         Go_back ");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, HIGH);

}


/*###############scan back line ##########################*/
void scan_backline(){
 switch (irSensors_Front) {
     case B11111110:
   back_line =1;
     break;
     case B01111111:
  back_line =1;
     break;
     case B11111111:
    back_line =1;
     break;

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

