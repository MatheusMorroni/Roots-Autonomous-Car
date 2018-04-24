#include <Position.h>

void setup() {
  Position atual(4, 3);

}

void loop() {
  Position.Acquire();
  float latToGo, longToGo;
  if(abs(latToGo - atual.getLatitude) > eps && abs(longToGo - atual.getLongitude) > eps){
    // Então aqui a gente coloca a rotina pro carrinho começar a andar em direção a longToGo e latToGo
  }
}
