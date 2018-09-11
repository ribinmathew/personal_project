/*######################## junction count#######################*/
boolean junction= false;
int junction_counter = 0;
int goback = 0;
int count3;
int count6;
int wait;
/*####################backline detection going back #############*/
int back_line;
int Irvalue_left;
/*counter*/
const int distance_data = 13;
const int count_data3 = 6;
const int count_data6 = 7;
const int count_data9 = 12;

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



const int irPinsF[8] = {22,24,26,28,30,32,34,36};
const int irPinsM[8] = {38,40,42,44,46,48,50,52};
int irSensorDigitalF[8] = {0,0,0,0,0,0,0,0};
int irSensorDigitalM[8] = {0,0,0,0,0,0,0,0};
int i,j = 0;
int d = 1000;

int irSensors_Front= B00000000;
int irSensors_Middle= B00000000;

int motorLSpeed = 150;
int motorRSpeed = 150;
int error = 140;   // 145 best 200  //  normal 255  // mad 0


int motorLSpeed_start = 150;
int motorRSpeed_start = 150;


void setup() {
/*ultrasonic*/
pinMode(distance_data,INPUT);
pinMode(count_data3,INPUT);
pinMode(count_data6,INPUT);
pinMode(count_data9,INPUT);
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

/*###################following line till finding 3 cubes ######################*/

while(1){
  scanD();
  cube_counting3();
  check();
  if(goback ==1)
    {
       break;
    }
}
/*##################################stop once 3 cubes picked ####################*/
 stopme();
delay(1000);
/*####################### going back till finds the line #############################*/
  while (1){
    scan_backline();
    Go_Back();
    if (back_line == 1){
      back_line =0;
      break;
    }
  }

/*######################### going left till finds next line ######################3*/
Go_Front();
delay(500);


while(1){
  scanD();
 
  initial_check1();
   movingleft();// here it moves from 
  Serial.println(Irvalue_left);
  if (Irvalue_left == 1) {
    stopme();
      break;
 }
}

/*#############################moving forward till 6 cubes detected  #####################*/

/*
while(1){
  scanD();
  cube_counting6();
  check();
  if(wait ==1)
    {
       break;
    }
}*/
/*################################waiting for next 3 cubes ###########################*/


/*##################################going back till find the line #####################*/

 while (1){
    scan_backline();
    Go_Back();
    if (back_line == 1){
      back_line =0;
      break;
    }
  }


 /*#################################left turn #######################################*/


 /*############################moving forward nearest to the board ###################*/
}

void loop()
{
   

/*
Serial.print("distance:    ");
Serial.println(digitalRead(distance_data));*/
/*
Serial.print("count:    ");
Serial.println(digitalRead(count_data));
/*

Serial.print("count2:    ");
Serial.println(digitalRead(count_data6));


Serial.print("count3:    ");
Serial.println(digitalRead(count_data12));
*/
/*
scanD();
check();*/
//Hardright();
//Hardleft();
//Turnright();
//Go_Back();
//HardleftS();
//HardrightS();
//SoftleftS5();
//SoftrightS5();
//SoftleftS4();
//SoftrightS4();
//SoftleftS3();
//SoftrightS3();
//SoftleftS2();
//SoftrightS2();
//SoftleftS1();
//SoftrightS1();
}

void check(){
    distance1 = digitalRead(distance_data);
    if (distance1==1){
      stopme();
    }
//    if(counter =3){
  //    Serial.println("Turn Around");
    else{
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
     Go_Front();
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
     Go_Front();
     break;

     case B00011100:
     Go_Front();
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
     Go_Front();
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
     Go_Front();
     break;

     case B00111111:
     SoftrightS();
     break;


     case B11111110:
     SoftleftS();
     break;

     case B01111111:
     SoftrightS();
     break;

    /* case B11111111:
      stopme();

     break;
*/

     default:

     Serial.print("Unhandled case: ");

  


}
}
}


void scanD()
{
  for ( byte count = 0; count < 8;count++ )
{
  bitWrite(irSensors_Front, count, !digitalRead( irPinsF[count] ));
}
//Serial.println(irSensors_Front);
}




void SoftrightS()  //turn left
{
     Serial.println("                         softrightS");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed/1.6);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed/1.6);
     digitalWrite(motorRBPin, LOW);

}





void SoftleftS()  //turn left
{
     Serial.println("                         softleft");
     analogWrite(motorLFEnable, motorRSpeed/1.6);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/1.6);
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
     
     analogWrite(motorRFEnable, motorRSpeed/1.5);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed/1.5);
     digitalWrite(motorRBPin, LOW);


}

void SoftleftS1()  //turn left
{
     Serial.println("                         Softlefts1");
     analogWrite(motorLFEnable, motorRSpeed/1.5);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/1.5);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);
}








void   SoftrightS2()

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





void SoftrightS3()

{
     Serial.println("                      SoftrightS3");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed/1.3);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed/1.3);
     digitalWrite(motorRBPin, LOW);



}

void SoftleftS3()  //turn left
{
     Serial.println("                         Softleft3");
     analogWrite(motorLFEnable, motorRSpeed/1.3);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/1.3);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);


}


void SoftrightS4()

{
     Serial.println("                      softRight4");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, LOW);
       
     analogWrite(motorRFEnable, motorRSpeed/1.2);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed/1.2);
     digitalWrite(motorRBPin, LOW);


}

void SoftleftS4()  //turn left
{
     Serial.println("                         Softleft4");
     analogWrite(motorLFEnable, motorRSpeed/1.2);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/1.2);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);


}


void SoftrightS5()

{
     Serial.println("                      SoftrightS5");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed/1.1);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed/1.1);
     digitalWrite(motorRBPin, LOW);



}


void SoftleftS5()  //turn left
{
     Serial.println("                         Softleft5");
     analogWrite(motorLFEnable, motorRSpeed/1.1);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/1.1);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);


}


void HardrightS()

{
     Serial.println("                      HardRightS");
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
     Serial.println("                         HardleftS");
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



void Turnleft()
{
  /*move left to find the line!*/


     Serial.println("                         Turnleft");
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


     Serial.println("                         Turnright");
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




void Hardleft()

{
     Serial.println("                      Hardleft");
     analogWrite(motorLFEnable, motorRSpeed/3);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed/3);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);



}


void Hardright()  //turn left
{
     Serial.println("                         Hardright");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed/3);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed/3);
     digitalWrite(motorRBPin, LOW);


}

/*###############################################3cube3 counting ###########################*/
void cube_counting3 (){
  
 distance1 = digitalRead(distance_data);
 Serial.println(distance1);
 
 count3 = digitalRead(count_data3);
 Serial.println(count3);
    if (count3==1){
     if (distance1 ==0){
      Serial.println("Go_back");
      goback= 1;
       
     }
    }
}

/*###############################################3cube3 counting ###########################*/
void cube_counting6 (){
  
 distance1 = digitalRead(distance_data);
 Serial.println(distance1);
 
 count6 = digitalRead(count_data6);
 Serial.println(count3);
    if (count6==1){
     if (distance1 ==0){
      Serial.println("Wait for next 3 cubes");
      wait= 1;
       
     }
    }
}

/*############################ junction counting############################*/
void junction_count()
{

     switch (irSensors_Front) {

     case B11111111:
    junction_count1();          

     break;
    
     case B11100000:
     junction2();
     break;

     case B01110000:
    junction2();
     break;

     case B00111000:
    junction2();
     break;

     case B00011100:
     junction2();
     break;

     case B00001110:
     junction2();
     break;

     case B00000111:
    junction2();
     break;
/*here we have straght line*/
     case B11110000:
   junction2();
     break;

     case B01111000:
     junction2();
     break;

     case B00111100:
    junction2();
     break;

     case B00011110:
    junction2();
     break;

     case B00001111:
    junction2();
     break;

     default:

     Serial.println("not Junction ");

  }
}
 void junction_count1 ()
  {

  if(junction == false){
          junction_counter +=1;
          junction = true;
          Serial.println("Found Junction");
          }
}
void junction2(){
 if(junction==true){
      junction = false;
      }
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



/*######################### left moving after 3 cubes picked ##################*/
void initial_check1(){

    switch (irSensors_Front) {
     case B00111000:
     Irvalue_left = 1;
     break;

     case B00011100:
       Irvalue_left = 1;
     break;

     case B00001110:
       Irvalue_left = 1;
     break;

     case B00000111:
       Irvalue_left = 1;
     
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


