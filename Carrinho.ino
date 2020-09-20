#include <SoftwareSerial.h>
#define RX 5
#define TX 6

const int frente = 3;
const int tras = 9;
const int esquerda = 10;
const int direita = 11;
const int led = 12;
const int arraySensibilidade[] = {70,150,200};
int sensibilidade = 70;
int velocidade = 0;
int countMarcha = 0;
char command = '.';
unsigned long millisLed = millis();
bool piscar = false;


SoftwareSerial bluetooth(TX,RX);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

pinMode(frente,OUTPUT);
pinMode(tras,OUTPUT);
pinMode(esquerda,OUTPUT);
pinMode(direita,OUTPUT);
pinMode(led,OUTPUT);
  
}

void loop() {

 
  if(bluetooth.available()){
    command = bluetooth.read();
    switch (command){
      case 'A': Frente(); break;
      case 'E': Tras(); break;
      case 'C': Esquerda(); break;
      case 'B': Direita(); break;
      case 'D': interromperSinais(); break;
      case 'J': interromperDirecao(); break;
      case 'K': interromperMovimento(); break;
      //---------------------//
      //-----VELOCIDADES-----//
      //---------------------// 
      case 'Y': Velocidade('-'); break;
      case 'Z': Velocidade('+'); break;
      //-----------------------//
      //-----SENSIBILIDADE-----//
      //-----------------------// 
      case '1': sensibilidade = arraySensibilidade[0]; break;
      case '2': sensibilidade = arraySensibilidade[1]; break;
      case 'T': sensibilidade = arraySensibilidade[0]; break;
      case 'U': sensibilidade = arraySensibilidade[1]; break;
      case '3': sensibilidade = arraySensibilidade[2]; break;
      //---------------------//
      //---------LED---------//
      //---------------------// 
      case 'L': piscar = !piscar; break;
    }
    Serial.println(command);
  }

  //----------------------------------------------------------------//
  //-------------------------    LED     ---------------------------//
  //----------------------------------------------------------------//
  
  if(piscar){
    if((millis() - millisLed) < 100){
      digitalWrite(led, HIGH);
    }else{
      digitalWrite(led, LOW);
    }
    if((millis() - millisLed) > 200){
      millisLed = millis();
    }
  }
  
  
}


void Velocidade(char v){
  const int MIN = 0, MAX = 250;
  const int range = 50;
  if(velocidade >= MIN && velocidade <= MAX ){
      if(v == '+'){
          velocidade += range;
          countMarcha++;
      }else{
          velocidade -= range;
          countMarcha--;
      }
  } 
  
  if(velocidade > MAX){velocidade = 250; countMarcha = 5;}
  if(velocidade < MIN){velocidade = 0; countMarcha = 0;}
  bluetooth.print(countMarcha);
}


void interromperSinais(){
  digitalWrite(frente,0);
  digitalWrite(tras,0);
  digitalWrite(direita,0);
  digitalWrite(esquerda,0);  
}

void interromperDirecao(){
  digitalWrite(direita,0);
  digitalWrite(esquerda,0); 
}

void interromperMovimento(){
  digitalWrite(frente,0);
  digitalWrite(tras,0);
}

void Frente(){
  analogWrite(frente,velocidade);
}

void Tras(){
  analogWrite(tras,velocidade);
}

void Esquerda(){
  analogWrite(esquerda,sensibilidade);
}

void Direita(){
  analogWrite(direita,sensibilidade);
}
