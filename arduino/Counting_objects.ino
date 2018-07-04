/*now we are gonna count the number of object picked*/

#define trigPin 37
 #define echoPin 35
 // initialize the library with the numbers of the interface pins

 int counter = 0;
 int currentState = 0;
 int previousState = 0;

 void setup() {
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

 }

 void loop() {
 long duration, distance;
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;




 if (distance <= 10 && isobject==false){
 counter +=1;
 isobject =true;
 delay(2000);
 }
 if(distance > 10)
 {
 isobject =false
 }

 Serial.println(counter);
 }


