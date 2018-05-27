#include <Wire.h>
#include <HMC5883L.h>

HMC5883L bussola;

int i;
float graus0, graus, lgraus, rgaus, lbgraus, rbgraus;
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
  graus0 = 
  
      if (graus>0 && graus<90)
  {
    lgraus = graus0 - graus;
      if(lgraus<0);
     {
      if(|lgraus|<90 && |lgraus|>0)
      {
        /*enviar o dado para que a class control gire a roda do carro para a 
      }
      if(|lgraus|<180 && |lgraus|>90
      {
        /*enviar o dado para que a class control gire a roda do carro para a 
      }
      if(|lgraus|<270 && |lgraus|>180)
      {
        /*enviar o dado para que a class control gire a roda do carro para a 
      }
      if(|lgraus|<360 && |lgraus|>270)
      {
        /*enviar o dado para que a class control gire a roda do carro para a
     }
      if(lgraus>0);
        {
        if(|lgraus|<90 && |lgraus|>0)
        {
          /*enviar o dado para que a class control gire a roda do carro para a 
        }
       if(|lgraus|<180 && |lgraus|>90
        {
         /*enviar o dado para que a class control gire a roda do carro para a 
        }
       if(|lgraus|<270 && |lgraus|>180)
        {
         /*enviar o dado para que a class control gire a roda do carro para a 
        }
        if(|lgraus|<360 && |lgraus|>270)
        {
         /*enviar o dado para que a class control gire a roda do carro para a
        }
      }
  }
   
      if (graus>270 && graus<360)
  {
    rgraus = graus0 - graus;
      if(rgraus<0)
      {
        if(|rgraus|<90 && |rgraus|>0)
        {
          /*enviar o dado para que a class control gire a roda do carro para a 
        }
        if(|rgraus|<180 && |rgraus|>90
        {
          /*enviar o dado para que a class control gire a roda do carro para a 
        }
        if(|rgraus|<270 && |rgraus|>180)
        {
         /*enviar o dado para que a class control gire a roda do carro para a 
       }
       if(|rgraus|<360 && |rgraus|>270)
        {
         /*enviar o dado para que a class control gire a roda do carro para a
       }
      if(rgraus>0)
      {
        if(|rgraus|<90 && |rgraus|>0)
        {
          /*enviar o dado para que a class control gire a roda do carro para a 
        }
        if(|rgraus|<180 && |rgraus|>90
        {
         /*enviar o dado para que a class control gire a roda do carro para a 
       }
       if(|rgraus|<270 && |rgraus|>180)
       {
          /*enviar o dado para que a class control gire a roda do carro para a 
        }
       if(|rgraus|<360 && |rgraus|>270)
       {
         /*enviar o dado para que a class control gire a roda do carro para a
        }
      }
  }
  
      if(graus>90 && graus<180)
    {
      /*fazer o carro dicar paralelo com o traçado, para esse caso específico o carro deve girar a roda para direita para ficar paralelo*/
      lbgraus = graus0 - graus;
        if(lbgraus<0);
        {
          if(|lbgraus|<90 && |lbgraus|>0)
          {
            /*enviar o dado para que a class control gire a roda do carro para a 
          }
          if(|lbgraus|<180 && |lbgraus|>90
          {
            /*enviar o dado para que a class control gire a roda do carro para a 
          }
          if(|lbgraus|<270 && |lbgraus|>180)
          {
            /*enviar o dado para que a class control gire a roda do carro para a 
          }
          if(|lbgraus|<360 && |lbgraus|>270)
          {
            /*enviar o dado para que a class control gire a roda do carro para a
          }
        }
      if(lbgraus>0)
      {
        if(|lbgraus|<90 && |lbgraus|>0)
        {
          /*enviar o dado para que a class control gire a roda do carro para a 
        }
        if(|lbgraus|<180 && |lbgraus|>90
        {
          /*enviar o dado para que a class control gire a roda do carro para a 
        }
        if(|lbgraus|<270 && |lbgraus|>180)
        {
          /*enviar o dado para que a class control gire a roda do carro para a 
        }
        if(|lbgraus|<360 && |lbgraus|>270)
        {
          /*enviar o dado para que a class control gire a roda do carro para a
        }
      }
  }
      
      if(graus>180 && graus<270)
  {
    /*fazer o carro dicar paralelo com o traçado, para esse caso específico o carro deve girar a roda para esquerda para ficar paralelo*/
    rbgraus = graus0 - graus;
      if(rbgraus<0);
     {
      if(|rbgraus|<90 && |rbgraus|>0)
      {
        /*enviar o dado para que a class control gire a roda do carro para a 
      }
      if(|rbgraus|<180 && |rbgraus|>90
      {
        /*enviar o dado para que a class control gire a roda do carro para a 
      }
      if(|rbgraus|<270 && |rbgraus|>180)
      {
        /*enviar o dado para que a class control gire a roda do carro para a 
      }
      if(|rbgraus|<360 && |rbgraus|>270)
      {
        /*enviar o dado para que a class control gire a roda do carro para a
      }
     }
      if(rbgraus>0);
      {
        if(|rbgraus|<90 && |rbgraus|>0)
        {
          /*enviar o dado para que a class control gire a roda do carro para a 
        }
        if(|rbgraus|<180 && |rbgraus|>90
        {
          /*enviar o dado para que a class control gire a roda do carro para a 
        }
        if(|rbgraus|<270 && |rbgraus|>180)
        {
          /*enviar o dado para que a class control gire a roda do carro para a 
        }
        if(|rbgraus|<360 && |rbgraus|>270)
        {
          /*enviar o dado para que a class control gire a roda do carro para a
        }
      }
  }
