const char S_cube[11] = {'l',' ', 'j'};
const int Z_cube[11] ={};
const int J_cube[11] = {};
const int L_cube[11] = {};
const int O_cube[11] = {};
const int I_cube[11] = {};
 
void setup(){
Serial.begin(9600);
  
}

void loop(){

if (Serial.available() > 0) {
           char cube_on_the_board = Serial.read();
           Serial.println(cube_on_the_board);
           if (cube_on_the_board == 'S'){
              Serial.print("cube order for s:  ");
              Serial.println(S_cube);}
           if (cube_on_the_board == 'Z'){
              Serial.println("cube order for z");}
           if (cube_on_the_board == 'J'){
              Serial.println("cube order for J");}
           if (cube_on_the_board== 'L'){
              Serial.println("cube order for L");}
           if (cube_on_the_board== 'O'){
              Serial.println("cube order for O");}
           if (cube_on_the_board == 'I'){
              Serial.println("cube order for I");}
             
               
}
}

