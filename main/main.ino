#include "Comm.h"
#include "Compass.h"
#include "Motor.h"
#include "Ports.h"
#include "Control.h"
#include "Position.h"
#include "math.h"

float checkpoints[20][2];
int numeroDeRegistros;
Comm* comm;
Motor* motor;
Control* control;
Position* position;
Compass* compass;
  
void setup() {
  comm = new Comm();
  motor = new Motor();
  control = new Control();
  position = new Position(Serial);
  compass = new Compass(Serial,*control);
  Serial.begin(9600);
  Serial.println("Inicializando...");
  //control.begin();
  motor->begin();
  //compass.calibrar();
  //inicio do registro de checkpoints
  do{
    Serial.println("Aguardando sinal de GPS...");
    control->piscaLed(1,500);
  } while (!position->Acquire());
  Serial.println("OK!");
  Serial.println("Inicializando GPS");
  Serial.println("Registrando checkpoints...");
  control->piscaLed(3,200);
  int i=0;
  int segundos;
  for(i = 0; i < 20; i++){
    while(!control->botaoApertado()){
      delay(1);
    }
    segundos = control->botaoPressionado();
    if(segundos<=2000){
      if (position->Acquire()){
      checkpoints[i][0] =  position->getLatitude();
      checkpoints[i][1] = position->getLongitude();
      Serial.print("Checkpoint registrado:\nLatitude: ");
      Serial.println(checkpoints[i][0], 8);
      Serial.print("Longitude: ");
      Serial.println(checkpoints[i][1], 8);
      Serial.print("Bussola: ");
      Serial.println(compass->angulo(), 5);
      Serial.println("");}
      else {
        Serial.print("Erro");
        i--;
      }
    }
    else{
      if (i == 0){
        Serial.println("Precisa de um checkpoint!");
      }
      else {
        Serial.print(i);
        Serial.println(" checkpoints registrados");
        numeroDeRegistros = i;
        break;
      }
    }
  }
  //Registro de checkpoints acaba aqui
  Serial.println("Coloque o carrinho no lugar de partida.");
  Serial.println("Quando tudo estiver pronto aperte o botão");
  delay(1000);
  control->botaoPressionado();
  Serial.println("Iniciando em 5...");
  delay(1000);
  Serial.println("4...");
  delay(1000);
  Serial.println("3...");
  delay(1000);
  Serial.println("2...");
  delay(1000);
  Serial.println("1...");
  delay(1000);

}

//
//float subGraus(float teta, float fi) {
//  if ((teta - fi) < 0){
//    return 360.0+(teta-fi);
//  }
//  else {
//    return teta-fi;
//  }
//}

float anguloParaIr(float latGPS,float lonGPS, float lonCheck, float latCheck) {
  float divi = (latCheck - latGPS)/(lonCheck - lonGPS);
  Serial.println(divi, 8);
  float arctg = atan(divi)*360.0/(2.0*M_PI);
  
  Serial.println(arctg, 8);
  if (arctg < 0) arctg+=360.0;
  return arctg;
}


// the loop function runs over and over again forever
void loop() {
  
  
  Serial.println("------------");
  float latGPS;
  float lonGPS;
  float direcao;
  float angulo;
  for(int i = 0; i < numeroDeRegistros; i ++) {
   while (true) {
   position->Acquire();
   latGPS = position->getLatitude();
   lonGPS = position->getLongitude();
   direcao = compass->angulo();
   //angulo = anguloParaIr(latGPS, lonGPS, checkpoints[i][1], checkpoints[i][0]);
   angulo = anguloParaIr(latGPS, lonGPS, -23.502215, -46.675412);
   Serial.println(angulo, 8);
   direcao -= 90;
   Serial.println(direcao-angulo, 8);
   delay(300);
   Serial.println("------------");
   }
  }
}


