int x1;
int x2;
float c1x;
float c1y;
float c2x;
float c2y;
float final_co_ordinatesX;
float final_co_ordinatesY;
void setup(){
  Serial.begin(9600);
}
void loop(){
  if (Serial.available ()>0)
  {
    
           String shape  = Serial.readStringUntil(',');
          Serial.read(); //next character is comma, so skip it using this
          String angle = Serial.readStringUntil(',');
          Serial.read();
          String circle_1_x = Serial.readStringUntil(',');
          Serial.read();
          String circle_1_y = Serial.readStringUntil(',');
          Serial.read();
          String circle_2_x = Serial.readStringUntil(',');
          Serial.read();
          String circle_2_y = Serial.readStringUntil(',');
          Serial.read();
          String circle_3_x = Serial.readStringUntil(',');
          Serial.read();
          String circle_3_y  = Serial.readStringUntil(',');
          Serial.read();
          String circle_4_x = Serial.readStringUntil(',');
          Serial.read();
          String circle_4_y = Serial.readStringUntil('\0');
          Serial.read();
         Serial.println(shape);
          Serial.println(angle);
         float circle_1_x1 = circle_1_x.toFloat();
          float  circle_1_y1 =  circle_1_y.toFloat();
          float circle_2_x2 = circle_2_x.toFloat();
          float  circle_2_y2 =  circle_2_y.toFloat();
          float circle_3_x3 = circle_3_x.toFloat();
          float  circle_3_y3 =  circle_3_y.toFloat();
          float circle_4_x4 = circle_4_x.toFloat();
          float  circle_4_y4 =  circle_4_y.toFloat();


          
          if (circle_1_x1 != 0 || circle_1_y1 != 0){
            
            
            x1 = 1;
            c1x = circle_1_x1;
            c1y =circle_1_y1;
            
          }
          
            
         if(circle_2_x2 != 0 || circle_2_y2 != 0){
          
            /*
       
            Serial.println( circle_2_x2);
        
            Serial.println( circle_2_y2);
            */
            x2 = 1;
            c2x = circle_2_x2;
            c2y =circle_2_y2;

            
         
         }

         
         if(circle_3_x3 !=0 || circle_3_y3 !=0 ){
          
          if (x1 ==0){
            x1=1;
             c1x = circle_1_x1;
            c1y =circle_1_y1;
            
          }
        if (x1==1 && x2==0){
           x2 = 1;
           c2x = circle_2_x2;
            c2y =circle_2_y2;
        }
        /*    Serial.println( circle_3_x3);
       
            Serial.println( circle_3_y3);
            */
         }
         
         if(circle_4_x4 !=0|| circle_4_x4 != 0){
             
                /*
            Serial.println( circle_4_x4);
        
            Serial.println( circle_4_x4);
            */
             if (x1 ==0){
            x1=1;
             c1x = circle_1_x1;
            c1y =circle_1_y1;
            
          }
          
        if (x1==1 && x2==0){
           x2 = 1;
           c2x = circle_2_x2;
            c2y =circle_2_y2;
        }
         }



float X_value = abs(c1x - c2x);
Serial.println(X_value);

float Y_value = abs(c1y - c2y);
Serial.println(Y_value);


if (X_value > Y_value){
  Serial.println("X>Y");
  if (c1x < c2x){
     final_co_ordinatesX = c1x;
     final_co_ordinatesY = c1y;
    
  }
   if (c2x < c1x){
    final_co_ordinatesX= c2x;
      final_co_ordinatesY = c2y;
     
  }
  
}

if (X_value < Y_value){
  Serial.println("X<Y");
  if (c1y < c2y){
      final_co_ordinatesX = c1x;
      final_co_ordinatesY = c1y;
    
  }
   if (c2y < c1y){
      final_co_ordinatesX = c2x;
      final_co_ordinatesY = c2y;
    
  }
  
}



        
 
  
//I,182.7,-3.3,13.4,1.5,13.3,0,0,0,0
//I,1.9,0.0,0.0,-3.7,21.7,1.1,21.6,0.0,0.0

  
 Serial.print("c1x: ");
  Serial.println(c1x,c1y);
   Serial.print("c1y: ");
   Serial.println(c1y);
   
  Serial.print("c2x: ");
   Serial.println(c2x);
    Serial.print("c2y: ");
    Serial.println(c2y);
    Serial.print("finalX:");
 Serial.print(final_co_ordinatesX); 
 Serial.print("finalY:");
  Serial.println(final_co_ordinatesY); 
  }}

