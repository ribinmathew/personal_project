int value;

void setup() {
  Serial.begin(9600);
  while(1){
    Serials();
    Serial.println(value);
    if (value == 1){
      Serial.print("bye");
  
   
      break;
     }
  }
  

}

void loop() {
 Serial.print("hoi");
}
void Serials(){
  if (Serial.available() > 0) {
  value = Serial.parseInt();
   
  }
}
