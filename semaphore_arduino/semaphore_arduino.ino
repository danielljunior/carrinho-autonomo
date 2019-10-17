#define L1_R 3
#define L1_Y 4
#define L1_G 5

#define L2_R 6
#define L2_Y 7
#define L2_G 8


void setup() {
  pinMode(L1_R, OUTPUT);
  pinMode(L1_Y, OUTPUT);
  pinMode(L1_G, OUTPUT);
  
  pinMode(L2_R, OUTPUT);
  pinMode(L2_Y, OUTPUT);
  pinMode(L2_G, OUTPUT);

}

void loop() {
  //L2 Green
  digitalWrite(L1_R, HIGH);
  digitalWrite(L1_Y, LOW);
  digitalWrite(L1_G, LOW);

  digitalWrite(L2_R, LOW);
  digitalWrite(L2_Y, LOW);
  digitalWrite(L2_G, HIGH);

  delay(4000);

  //L2 Yellow
  digitalWrite(L1_R, HIGH);
  digitalWrite(L1_Y, LOW);
  digitalWrite(L1_G, LOW);

  digitalWrite(L2_R, LOW);
  digitalWrite(L2_Y, HIGH);
  digitalWrite(L2_G, LOW);
  
  delay(1000);

  //L1 Green
  digitalWrite(L1_R, LOW);
  digitalWrite(L1_Y, LOW);
  digitalWrite(L1_G, HIGH);

  digitalWrite(L2_R, HIGH);
  digitalWrite(L2_Y, LOW);
  digitalWrite(L2_G, LOW);
  
  delay(4000);

  //L1 Yellow
  digitalWrite(L1_R, LOW);
  digitalWrite(L1_Y, HIGH);
  digitalWrite(L1_G, LOW);

  digitalWrite(L2_R, HIGH);
  digitalWrite(L2_Y, LOW);
  digitalWrite(L2_G, LOW);
  
  delay(1000);
}
