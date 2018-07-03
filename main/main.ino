#include "Comm.h"
#include "Compass.h"
#include "Motor.h"
#include "Ports.h"
#include "Control.h"
#include "Position.h"
#include "math.h"

#define TRESHOLD_MOTOR 30 //em graus

float checkpoints[20][2];
int numeroDeRegistros;
Comm* comm;
Motor* motor;
Control* control;
Position* position;
Compass* compass;
  
void setup() {
  float pontosReferencia[3][3];
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
  int segundos;
  for(int i = 0; i < 20; i++){
    while(!control->botaoApertado()){
      delay(1);
    }
    segundos = control->botaoPressionado();
    if(segundos<=2000){
      if (position->Acquire()){
      checkpoints[i][0] =  position->getLatitude();
      checkpoints[i][1] = position->getLongitude();
      checkpoints[i][2] = compass->angulo();
      Serial.print("Checkpoint registrado:\nLatitude: ");
      Serial.println(checkpoints[i][0], 8);
      Serial.print("Longitude: ");
      Serial.println(checkpoints[i][1], 8);
      Serial.print("Angulo: ");
      Serial.println(checkpoints[i][2], 8);
      }
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
    motor->defVel(3);
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

// float anguloParaIr(float latGPS,float lonGPS, float lonCheck, float latCheck) {
//   Serial.println("--------------------");
//   Serial.println("ANGULO: ");
//   Serial.println("GPS: ");
//   Serial.println(latGPS, 8);
//   Serial.println(lonGPS, 8);
//   Serial.println("CheckPoint: ");
//   Serial.println(latCheck, 8);
//   Serial.println(lonCheck, 8);

//   float divi = (latCheck - latGPS)/(lonCheck - lonGPS);
//   Serial.println("Divi: ");
//   Serial.println(divi, 8);
//   float arctg = atan(divi)*360.0/(2.0*M_PI);
//   Serial.println("arctg: ");
//   Serial.println(arctg, 8);
//   if (arctg < 0) arctg+=360.0;
//   return arctg;
// }

// float anguloParaIr(float latGPS,float lonGPS, float lonCheck, float latCheck) {
//   Serial.println("--------------------");
//   Serial.println("ANGULO: ");
//   Serial.println("GPS: ");
//   Serial.println(latGPS, 8);
//   Serial.println(lonGPS, 8);
//   Serial.println("CheckPoint: ");
//   Serial.println(latCheck, 8);
//   Serial.println(lonCheck, 8);

//   float divi = (latCheck - latGPS)/(lonCheck - lonGPS);
//   Serial.println("Divi: ");
//   Serial.println(divi, 8);
//   float arctg = atan(divi)*360.0/(2.0*M_PI);
//   Serial.println("arctg: ");
//   Serial.println(arctg, 8);
//   if (arctg < 0) arctg+=360.0;
//   return arctg;
// }

//float calculaDiferenca( float latCheck, float lonCheck, float direcao){
//  float longitude0 = NN*60 + MM*1 + SS/60; /*a longitude é dada pelo GPS como NN°MM'SS"*/
//  float latitude0 = NN*60 + MM*1 + SS/60; /*a latitude segue o mesmo princípio da longitude*/
//  float dif = arctan(latitude0/longitude0);
//}



// float AngleToGo( double lon0, double lat0, double lon,  double lat){
//   double deltaLon = lon - lon0;
//   double deltaLat = lat - lat0;
//   int quadrante = 0;
//   float angle = 0;
//   if(deltaLon > 0 && deltaLat > 0) quadrante = 1;
//   else if(deltaLon < 0 && deltaLat > 0) quadrante = 2;
//   else if(deltaLon < 0 && deltaLat < 0) quadrante = 3;
//   else if(deltaLon > 0 && deltaLat < 0) quadrante = 4;
//   else {
//  //   Serial.print("erro");
//   }
//   double arctg = (atan(abs(deltaLon)/abs(deltaLat))*360)/(2*PI);
//   switch(quadrante){
//   case 1:
//     angle = 360 - arctg;
//     break;
//   case 2:
//     angle = arctg;
//     break;
//   case 3:
//     angle = 180 - arctg;
//     break;
//   case 4:
//     angle = arctg + 180;
//     break;
//   }
//   return angle;
  
// }

// int distanciaAoCheckpoint(float latGPS,float lonGPS, float latCheck, float lonCheck)
// {
//   Serial.println("--------------------");
//   Serial.println("DISTANCIA: ");
//   Serial.println("GPS: ");
//   Serial.println(latGPS, 8);
//   Serial.println(lonGPS, 8);
//   Serial.println("CheckPoint: ");
//   Serial.println(latCheck, 8);
//   Serial.println(lonCheck, 8);
// double distancia;
// double delta = radians(lonGPS - lonCheck);
// Serial.print("Delta: ");
// Serial.println(delta, 8);
// double sdlong = sin(delta);
// Serial.print("sdLong: ");
// Serial.println(sdlong, 8);
// double cdlong = cos(delta);
// Serial.print("cdLong: ");
// Serial.println(cdlong, 8);
// double lat1 = radians(latGPS);
// Serial.print("lat1: ");
// Serial.println(lat1, 8);
// double lat2 = radians(latCheck);
// Serial.print("latCheck: ");
// Serial.println(latCheck, 8);
// double slat1 = sin(lat1);
// Serial.print("slat1: ");
// Serial.println(slat1, 8);
// double clat1 = cos(lat1);
// Serial.print("clat1: ");
// Serial.println(clat1, 8);
// double slat2 = sin(lat2);
// Serial.print("slat2: ");
// Serial.println(slat2, 8);
// double clat2 = cos(lat2);
// Serial.print("clat2: ");
// Serial.println(clat2, 8);
// delta = (clat1 * slat2) - (slat1 * clat2 * cdlong);
// Serial.print("delta: ");
// Serial.println(delta, 8);
// delta = sq(delta);
// Serial.print("delta: ");
// Serial.println(delta, 8);
// delta += sq(clat2 * sdlong);
// Serial.print("delta: ");
// Serial.println(delta, 8);
// delta = sqrt(delta);
// Serial.print("delta: ");
// Serial.println(delta, 8);
// double denom = (slat1 * slat2) + (clat1 * clat2 * cdlong);
// Serial.print("denom: ");
// Serial.println(denom, 8);
// delta = atan2(delta, denom);
// Serial.print("delta: ");
// Serial.println(delta, 8);
// Serial.println("--------------------");
// distancia = delta * 6372795;

// // check to see if we have reached the current waypoint

// return distancia;
// } // distanceToWaypoint()

// double anguloParaIr(float latGPS,float lonGPS, float latCheck, float lonCheck) {
//   Serial.println("--------------------");
//   Serial.println("ANGULO: ");
//   Serial.println("GPS: ");
//   Serial.println(latGPS, 8);
//   Serial.println(lonGPS, 8);
//   Serial.println("CheckPoint: ");
//   Serial.println(latCheck, 8);
//   Serial.println(lonCheck, 8);

//   double dlon = radians(lonCheck - lonGPS);
//   Serial.print("dlon: ");
// Serial.println(dlon, 8);
//   double cLat = radians(latGPS);
//   Serial.print("clat: ");
// Serial.println(cLat, 8);
//   double tLat = radians(latCheck);
//   Serial.print("tlat: ");
// Serial.println(tLat, 8);
//   double a1 = sin(dlon) * cos(tLat);
//   Serial.print("a1: ");
// Serial.println(a1, 8);
//   double a2 = sin(cLat) * cos(tLat) * cos(dlon);
//   Serial.print("a2: ");
// Serial.println(a2, 8);
//   a2 = cos(cLat) * sin(tLat) - a2;
//   Serial.print("a2: ");
// Serial.println(a2, 8);
//   a2 = atan2(a1, a2);
//   Serial.print("a2: ");
// Serial.println(a2, 8);
//   if (a2 < 0.0)
//   {
//     a2 += TWO_PI;
//   }
//   a2 = degrees(a2);
//   Serial.print("a2: ");
// Serial.println(a2, 8);
//   return a2;
// }

// the loop function runs over and over again forever
// void loop() {
  
  
//   Serial.println("------------");
//   float latGPS;
//   float lonGPS;
//   float direcao;
//   double angulo;
//   double distancia;
//   for(int i = 0; i < numeroDeRegistros; i ++) {
//    Serial.println("Indo para:");
//    Serial.println(checkpoints[i][0]);
//    Serial.println(checkpoints[i][1]);
   
//    while (true) {
//    position->Acquire();
//    latGPS = position->getLatitude();
//    lonGPS = position->getLongitude();
//    direcao = compass->angulo();
//    //angulo = anguloParaIr(latGPS, lonGPS, checkpoints[i][1], checkpoints[i][0]);
//    angulo = anguloParaIr(latGPS, lonGPS, checkpoints[i][0], checkpoints[i][1]);
//    distancia = distanciaAoCheckpoint(latGPS, lonGPS, checkpoints[i][0], checkpoints[i][1]);
//    Serial.print("Angulo sem bussola:");
//    Serial.println(angulo);
//    Serial.print("Distancia:");
//    Serial.println(distancia);
//    Serial.print("Angulo com bussola:");
//    Serial.println(angulo-direcao);
//    delay(300);
//    Serial.println("------------");
//    }
//   }
// }

float gpslong, gpslat;
int valorMotor;
float anguloObjetivo;
float ultimoPrint = 0;

bool atingiuPonto(int i){
  float distancia = TinyGPS::distance_between(gpslat, gpslong, checkpoints[i][0], checkpoints[i][1]);
  bool retorno = 0;

  if ((millis()-ultimoPrint)>=3000){
    ultimoPrint = millis();
    Serial.print("Distancia: ");
    Serial.print(distancia);
  }
  if(distancia <= 5){
    retorno = 1;
  }
  return retorno;
}

float calculaCorrecao(float phi, float teta){ //ANGULO QUE ESTOU, ANGULO QUE QUERO IR
  float angulo;
  if (teta - phi > 180.0 || teta - phi < -180.0){
    if(teta - phi >=0){
      angulo = (teta-phi)-360.0;
    }
    else{
      angulo = (teta-phi)+360.0;
    }
  }
  else {
    angulo = teta - phi;
  }
  return angulo;
}

void loop() {
  float angulo, diferenca;
  bool giroCheck; //0 para direita, 1 para esquerda
  double lastMillis = millis();
  for(int i =0; i < numeroDeRegistros; i++){
    if(i!=0){
      anguloObjetivo = checkpoints[i][2];
      motor->parar();
      if (calculaCorrecao(compass->angulo(), anguloObjetivo)>=0)giroCheck = 0;
      else giroCheck = 1;
      delay(1000);
      while(true){
        if(!giroCheck) motor->rotacionar(5);
        else motor->rotacionar(-5);
        angulo = calculaCorrecao(compass->angulo(), anguloObjetivo);
        if(angulo<=3.0 && angulo>=-3.0){
          motor->parar();
          break;
        }
        delay(1000);
      }
    }
    anguloObjetivo = checkpoints[i][2];
    while(!atingiuPonto(i)){
      angulo = compass->angulo();
      if (millis() - lastMillis >= 250){
        lastMillis = millis();
        position->Acquire();
        gpslong = position->getLongitude();
        gpslat = position->getLatitude();

        Serial.println("Captei posição: ");
        Serial.print("LAT: ");
        Serial.println(gpslat);
        Serial.print("LONG: ");
        Serial.println(gpslong);
      }
      angulo = calculaCorrecao(angulo, anguloObjetivo);
      if (angulo<= TRESHOLD_MOTOR && angulo>=(-1*TRESHOLD_MOTOR)){
        valorMotor = map(-1*TRESHOLD_MOTOR, TRESHOLD_MOTOR, -10, 10, angulo);
      }
      else{
        if (angulo>=0){
          valorMotor = 10;
        }
        else {
          valorMotor <= -10;
        }
      }
      motor->avancar(valorMotor);
  }
}
  motor->parar();
  Serial.println("TERMINEI!!!!");
  while(true){
    delay(1000);
  }
}
