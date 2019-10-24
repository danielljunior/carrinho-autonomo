#define COMM_MAX_IDLE 2000

#define ENA 6
#define ENB 3
#define IN1 5
#define IN2 4
#define IN3 2
#define IN4 7

unsigned long lastCommunication;

void setup(){
  /*
   * PinMode from motors
   */
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  carStop();

  //left motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  //right motor
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  /*
   * Setup Serial communication
   */
  Serial.begin(115200);
  while(!Serial); //wait communication
  
  lastCommunication = millis();
}

void loop(){
  /*
   * check if master device still communicating, if not stop the car
   */
  if(millis() - lastCommunication > COMM_MAX_IDLE){
    carStop();
  }
  
  delay(1);
}

void serialEvent(){
  /*
  * Parse Command
  */
  String command = Serial.readStringUntil('\n');
  lastCommunication = millis();
  
  if(command.startsWith("Turn")){
    command.remove(0, 5); // "Turn "
    carRun( command.toInt() );
  
  } else if(command.startsWith("Run")){
    carRun(0);
  } else {
    carStop();
  }
  
}

void carStop(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

/*
 * factor - int between -255 and 255;
 *              < 0 - turn left
 *              0   - run
 *              > 0 - turn right
 */
void carRun(int factor){
  
  //run
  if(factor == 0){
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
  }
  //left
  else if (factor < 0){
    analogWrite(ENA, -factor);
    analogWrite(ENB, 255);
  }
  //right
  else{
    analogWrite(ENA, 255);
    analogWrite(ENB, factor);
  }
}
