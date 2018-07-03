const int trigpin = 37;
const int echopin = 35;
const int trigpin1  = 31;
const int echopin1 = 33;

long duration;
int distance;
long duration1;
int distance1;
void setup() {
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(trigpin1,OUTPUT);
pinMode(echopin1,INPUT);
Serial.begin(9600);

}
void loop() {
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

delay(1000);
}