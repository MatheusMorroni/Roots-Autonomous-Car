#include <Wire.h>
#include <HMC5883L.h>

HMC5883L bussola;

int i;
float graus;
float precisao;

void setup()
{  
Wire.begin();
  bussola = HMC5883L();
  bussola.SetScale(1.3);
  bussola.SetMeasurementMode(Measurement_Continuous);
}

void loop()
{
  precisao = 0;

 

for(i=0;i<100;i++)
  {
    MagnetometerScaled scaled = bussola.ReadScaledAxis();
    int MilliGauss_OnThe_XAxis = scaled.XAxis;
    float heading = atan2(scaled.YAxis, scaled.XAxis);
    float declinationAngle = 0.3339; 
    heading += declinationAngle;
    if(heading < 0)
    {
      heading += 2*PI;
    } 

if(heading > 2*PI)
    {
      heading -= 2*PI;
    }  

graus = heading * 180/M_PI;
    precisao = precisao + graus;
    delay(1);

  }
  graus = precisao/100;
  
  if (graus>0 && graus<90)
  {
    lgraus = graus;
    /*enviar o dado para que a class control gire a roda do carro para a esquerda em lgraus*/
  }
  
  if (graus>270 && graus<360)
  {
    rgraus = graus-270;
    /*enviar o dado para que a class control gire a roda do carro para a direita em rgraus*/
  }
  
  if (graus>90 && graus<180)
  {
    /*fazer o carro ficar paralelo com o traçado, para esse caso específico o carro deve girar a roda para direita para ficar paralelo*/
    lbgraus = graus-90;
    /*enviar o dado para que a class control gire a roda do carro para a esquerda em lbgraus*/
  }
  
  if (graus>180 && graus<270)
  {
    /*fazer o carro dicar paralelo com o traçado, para esse caso específico o carro deve girar a roda para esquerda para ficar paralelo*/
    rbgraus = graus-180;
    /*enviar o dado para que a class control gira a roda do carro para a direita em rbgraus*/
