/*here we are gonna define function for finding the junction*/


const int irPins[8] = {39,41,43,45,47,49,51,53};
int irSensorDigital[8] = {0,0,0,0,0,0,0,0};

int irSensors = B00000000;
boolean junction= false;
int junction_counter = 0;




void setup()
  /* Set-up IR sensor pins as input */
for (int i = 0; i <= 7; i++)
{pinMode(irPins[i], INPUT);}


void loop()
{
scanD();
junction_count();


}





void scanD()
{
  for ( byte count = 0; count < 8;count++ )
{
  bitWrite(irSensors, count, !digitalRead( irPins[count] ));
}
}




void junction_count()
{

     switch (irSensors) {

     case B11111111:
      Serial.println("Found Junction")
     break;


     default:

     Serial.print("Unhandled case: ");

  }