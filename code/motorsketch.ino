// bind stepper with schmalzhaus.com easydriver to poti
#define DIR_PIN 2
#define STEP_PIN 3
#define ENABLE_PIN 5

pinMode(2, OUTPUT);     

pinMode(3, OUTPUT);
 
int dir = LOW;
 
//speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
float master_speed = .5;
 
 
void setup(){
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
 
 
 
}
void loop(){
 
rotate(10, master_speed, LOW);
delay(1000);
digitalWrite(ENABLE_PIN, HIGH);
delay(1000);
digitalWrite(ENABLE_PIN, LOW);
 
}
 
 
 
void rotate(int steps, float speed, int dir){
  //rotate a specific number of microsteps (8 microsteps per step) - (negitive for reverse movement)
 
 
  digitalWrite(2, dir);
 
  float usDelay = (1/speed) * 70;
 
  for(int i=0; i < steps; i++){
 
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(usDelay);
 
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(usDelay);
  }
}

