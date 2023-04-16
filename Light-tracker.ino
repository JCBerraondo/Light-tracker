// Definición de variables salida
  const int ledTest= 13;

// variables de entrada
  const int fI= A0;
  const int fD= A1;

// Motores
  int AIA= 3;
  int AIB= 11;
  int BIA= 10;
  int BIB= 6;

// Resistividad
  int rI=0;
  int rD=0;

void setup() {
  Serial.begin(9600);

  // Iniciar pines de salida
    pinMode(ledTest, OUTPUT);  
    pinMode(AIA, OUTPUT);
    pinMode(AIB, OUTPUT);
    pinMode(BIA, OUTPUT);
    pinMode(BIB, OUTPUT);

  //Pines apagados
    digitalWrite(ledTest, LOW);
    analogWrite(AIA, 0);
    analogWrite(BIA, 0);
    analogWrite(AIB, 0);
    analogWrite(BIB, 0);

  // Saludo inicial
    for (int i=0; i<10; i++){
      digitalWrite(ledTest, HIGH);
      delay(50);
      digitalWrite(ledTest, LOW);
      delay(50);
    }

}

void loop() {
  // Lectura de fotoresistencias
  rI= analogRead(fI);
  rD= analogRead(fD);

  Serial.print(rI);
  Serial.print(",");
  Serial.println(rD);


  // Condiciones
    if (rD<500 && rI<500){       //obscuridad=1023; claridad=0
      adelante();
    }
    else if (rD<500 && rI>500){
      izquierda();
      delay(10);
    }
    else if (rD>500 && rI<500){
      derecha();
      delay(10);
    }
    else{
      busqueda();
      delay(10);
    }
}

//Movimientos
void adelante(){
  analogWrite(AIA,0);
  analogWrite(AIB,180);
  analogWrite(BIA,180);
  analogWrite(BIB,0);
}

void derecha(){
  analogWrite(AIA,0);
  analogWrite(AIB,180);
  analogWrite(BIA,0);
  analogWrite(BIB,0);
}

void izquierda(){
  analogWrite(AIA,0);
  analogWrite(AIB,0);
  analogWrite(BIA,180);
  analogWrite(BIB,0);
}

void busqueda(){
  analogWrite(AIA,0);
  analogWrite(AIB,120);
  analogWrite(BIA,0);
  analogWrite(BIB,0);
}








