#include "Comm.h"
#include "Compass.h"
#include "Motor.h"
#include "Ports.h"
#include "Control.h"
#include "Position.h"


Comm comm;
Control control;
Compass compass(Serial, control);
Motor motor;
Position position;
float checkpoints[20][2];
int numeroDeRegistros;
void setup() {
  Serial.begin(9600);
  Serial.println("Inicializando...");
  control.begin();
  motor.begin();
  position.begin();
  //inicio do registro de checkpoints
  do{
    Serial.println("Aguardando sinal de GPS...");
    control.piscaLed(1,500);
  } while (!position.sinalOK());
  Serial.println("OK!");
  Serial.println("Registrando checkpoints...");
  control.piscaLed(3,200);
  int i=0;
  int segundos;
  for(i = 0; i < 20; i++){
    while(!control.botaoApertado()){
      delay(1);
    }
    segundos = control.botaoPressionado();
    if(segundos<=2000){
      position.Acquire();
      checkpoints[i][0] =  position.getLatitude();
      checkpoints[i][1] = position.getLongitude();
      Serial.print("Checkpoint registrado:\nLatitude: ");
      Serial.println(checkpoints[i][0]);
      Serial.print("Longitude: ");
      Serial.println(checkpoints[i][1]);
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
  control.botaoPressionado();
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

// the loop function runs over and over again forever
void loop() {

}
