

const int trigpin = 3;
const int echopin = 2;
const int count_data = 4;
const int count_data6 = 5;
const int count_data9 = 6;
const int distance_data =7;
long duration;
int distance;


/*counter*/

 int counter = 0;
 boolean isobject = false;





void setup() {
/*ultrasonic*/
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(count_data,OUTPUT);
pinMode(count_data6,OUTPUT);
pinMode(count_data9,OUTPUT);
pinMode(distance_data,OUTPUT);
Serial.begin(9600);
/*Linefollower*/
}


void loop()
{
   
     Distance();
     
     count();

}

void Distance()
{
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(5);
digitalWrite(trigpin,LOW);
duration = pulseIn(echopin,HIGH);
distance = duration*0.034/2;
/*
digitalWrite(trigpin1,LOW);
delayMicroseconds(2);
digitalWrite(trigpin1,HIGH);
delayMicroseconds(5);
digitalWrite(trigpin1,LOW);
duration1 = pulseIn(echopin1,HIGH);
distance1 = duration1*0.034/2;
*/
if (distance <20){
  digitalWrite(distance_data,HIGH);
}
else {
  digitalWrite(distance_data,LOW);
}

Serial.print("Distace: ");
Serial.println(distance);
/*
Serial.print("Distance1:");
Serial.println(distance1); 

*/
}


void count()
{
 if (distance <= 20 && isobject==false){
 counter +=1;
 isobject =true;
 delay(1000);
 }
 if(distance > 25)
 {
 isobject =false;
 }
 
 Serial.println("counter ");
 Serial.println(counter); 
 if (counter == 3){
  digitalWrite(count_data,HIGH);
 }
 if(counter == 6){
  digitalWrite(count_data6,HIGH);
 }
 if (counter == 9){
   digitalWrite(count_data9,HIGH);
 
 }
 /*
else{
  digitalWrite(count_data12,LOW);
  digitalWrite(count_data6,LOW);
  digitalWrite(count_data,LOW);
}*/
}

