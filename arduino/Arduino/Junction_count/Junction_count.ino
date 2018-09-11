boolean junction= false;
int junction_counter = 0;




void setup(){
  /* Set-up IR sensor pins as input */
  Serial.begin(9600);
for (int i = 0; i <= 7; i++)
{pinMode(irPins[i], INPUT);}}


void loop()
{
scanD();
junction_count();
Serial.println("junction_counter");
Serial.print(junction_counter);
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
      junction = false;}
}
