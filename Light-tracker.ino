// Outputs
  const int ledTest= 13;

// Inputs
  const int fI= A0;
  const int fD= A1;

// Engines
  int AIA= 3;
  int AIB= 11;
  int BIA= 10;
  int BIB= 6;

// Photoresists
  int rI=0;
  int rD=0;

void setup() {
  Serial.begin(9600);

  // Setting outputs
    pinMode(ledTest, OUTPUT);  
    pinMode(AIA, OUTPUT);
    pinMode(AIB, OUTPUT);
    pinMode(BIA, OUTPUT);
    pinMode(BIB, OUTPUT);

  //Turns off outputs
    digitalWrite(ledTest, LOW);
    analogWrite(AIA, 0);
    analogWrite(BIA, 0);
    analogWrite(AIB, 0);
    analogWrite(BIB, 0);

  // Beginning greeting
    for (int i=0; i<10; i++){
      digitalWrite(ledTest, HIGH);
      delay(50);
      digitalWrite(ledTest, LOW);
      delay(50);
    }

}

void loop() {
  // Read photoresists value
  rI= analogRead(fI);
  rD= analogRead(fD);

  Serial.print(rI);
  Serial.print(",");
  Serial.println(rD);


  // Conditions
    if (rD<500 && rI<500){       //darkness=1023; clarity=0
      forward();
    }
    else if (rD<500 && rI>500){
      left();
      delay(10);
    }
    else if (rD>500 && rI<500){
      right();
      delay(10);
    }
    else{
      search();
      delay(10);
    }
}

//Motion
void forward(){
  analogWrite(AIA,0);
  analogWrite(AIB,180);
  analogWrite(BIA,180);
  analogWrite(BIB,0);
}

void right(){
  analogWrite(AIA,0);
  analogWrite(AIB,180);
  analogWrite(BIA,0);
  analogWrite(BIB,0);
}

void left(){
  analogWrite(AIA,0);
  analogWrite(AIB,0);
  analogWrite(BIA,180);
  analogWrite(BIB,0);
}

void search(){
  analogWrite(AIA,0);
  analogWrite(AIB,120);
  analogWrite(BIA,0);
  analogWrite(BIB,0);
}








