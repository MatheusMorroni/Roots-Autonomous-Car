#include <Wire.h>
#include <HMC5883L.h>

HMC5883L bussola;

int i;
float graus0, graus, dgraus, dgraus1, dgraus2, latitude0, longitude0;
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
  longitude0 = NN*1380 + MM*1 + SS/60; /*a longitude é dada pelo GPS como NN°MM'SS"*/
  latitude0 = NN*1380 + MM*1 + SS/60; /*a latitude segue o mesmo princípio da longitude*/
  graus0 = arctan(latitude0/longitude0);
  dgraus = graus0 - graus;
      if(dgraus<0)
      {
        if(|dgraus|<=180 && |dgraus|>0)
        {
          /*enviar o dado para que a class control gire o carro para a direita em dgraus*/
        }
        if(|dgraus|>180 && |dgraus|<=360)
        {
          dgraus1 = 360 - dgraus;
          /*enviar o dado para que a class control gire o carro para a esquerda em dgraus1*/
        }
      }
      if(dgraus>0)
      {
        if(|dgraus|<=180 && |dgraus|>0)
        {
          /*enviar o dado para que a class control gire o carro para a esquerda em dgraus*/
        }
        if(|dgraus|>180 && |dgraus|<=360)
        {
          dgraus2 = 360 - dgraus;
          /*enviar o dado para que a class control gire o carro para a direita em dgraus*/
        }
      }
      
