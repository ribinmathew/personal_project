

const int motorLFPin = 8; // signal pin 1 for the right motor, connect to IN1
const int motorLFEnable = 9; // enable pin for the right motor (PWM enabled)

const int motorLBPin = 10; // signal pin 1 for the left motor, connect to IN3
const int motorLBEnable = 11; // enable pin for the left motor (PWM enabled)

const int motorRFPin = 2; // signal pin 1 for the right motor, connect to IN1
const int motorRFEnable = 3; // enable pin for the right motor (PWM enabled)

const int motorRBPin = 4; // signal pin 1 for the left motor, connect to IN3
const int motorRBEnable = 5; // enable pin for the left motor (PWM enabled)



int motorLSpeed = 150;
int motorRSpeed = 150;
int error = 140;   // 145 best 200  //  normal 255  // mad 0


void setup() {


pinMode(motorLFPin,OUTPUT);
pinMode(motorLFEnable,OUTPUT);
pinMode(motorLBPin,OUTPUT);
pinMode(motorLBEnable,OUTPUT);
pinMode(motorRFPin,OUTPUT);
pinMode(motorRFEnable,OUTPUT);
pinMode(motorRBPin,OUTPUT);
pinMode(motorRBEnable,OUTPUT);


}

void loop()
{
   



movingleft();
delay(2000);

}


void movingright()  //turn left
{
     Serial.println("                         softrightS");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, LOW);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, HIGH);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, HIGH);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, LOW);

}


void movingleft()  //turn left
{
     Serial.println("                         softrightS");
     analogWrite(motorLFEnable, motorRSpeed);
     digitalWrite(motorLFPin, HIGH);


     analogWrite(motorLBEnable, motorLSpeed);
     digitalWrite(motorLBPin, LOW);
     
     analogWrite(motorRFEnable, motorRSpeed);
     digitalWrite(motorRFPin, LOW);


     analogWrite(motorRBEnable, motorLSpeed);
     digitalWrite(motorRBPin, HIGH);

}

