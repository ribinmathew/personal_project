

int MOTOR1_PIN1 = 3;
int MOTOR1_PIN2 = 5;
int MOTOR2_PIN1 = 6;
int MOTOR2_PIN2 = 9;


int sensor[8]={39,41,43,45,47,49,51,53};

int sensorReading[8] = { 0 };
float activeSensor = 0;
float totalSensor = 0;
//float avgSensor =
float avgSensor = 0; // Average sensor reading

float Kp = 3;   // Max deviation = 10 - 0 = 10 ||  255/10 = 25
float Ki = 0.00015;
float Kd = 2;

float error = 0;
float previousError = 0;
float totalError = 0;

float power = 0;

int PWM_Left;
int PWM_Right;

int MAX_SPEED = 100;

void setup() {
  for(int i=0; i<8; i++) {
    pinMode(sensor[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {



}

void readSensor() {
  for(int i=1; i<7; i++)
    {
       if(digitalRead(sensor[i])==1){
         sensorReading[i]=1;
         }
       if(digitalRead(sensor[i])==0){
             sensorReading[i]=0;

       }
    }

   =
    for(int i=0; i<8; i++)
    {
      if(sensorReading[i]==1) { activeSensor+=1; }
      totalSensor += sensorReading[i] ;
    }
    avgSensor = totalSensor/activeSensor;
    Serial.print("avgSensor=");
    Serial.println(avgSensor);

    activeSensor = 0; totalSensor = 0;
    for(int i=0; i<8; i++)
    {
      sensorReading[i]=0;
    }
}
