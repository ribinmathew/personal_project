float num;
String vlaue = "N";
void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
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
       
          float circle_1_x1 = circle_1_x.toFloat();
          float  circle_1_y1 =  circle_1_y.toFloat();
          float circle_2_x2 = circle_2_x.toFloat();
          float  circle_2_y2 =  circle_2_y.toFloat();
          float circle_3_x3 = circle_3_x.toFloat();
          float  circle_3_y3 =  circle_3_y.toFloat();
          float circle_4_x4 = circle_4_x.toFloat();
          float  circle_4_y4 =  circle_4_y.toFloat();
         
            Serial.println( circle_1_x1);
        
            Serial.println( circle_1_y1);
         
            Serial.println( circle_2_x2);
        
            Serial.println( circle_2_y2);
       
            Serial.println( circle_3_x3);
       
            Serial.println( circle_3_y3);
       
            Serial.println( circle_4_x4);
        
            Serial.println( circle_4_x4);
        
        
        
         

         
    
    /*    
        Serial.println(circle_1_y1);
        
        Serial.println( circle_2_x2);
        
        Serial.println(circle_2_y2);
        
        Serial.println(circle_3_x3);
        
        Serial.println(circle_3_y3);
        
        Serial.println(circle_4_x4);
        
        Serial.println(circle_4_y4);
         */
          
        }
}
 



