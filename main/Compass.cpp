#include "Compass.h"

Compass::Compass(HardwareSerial& _serial, Control& _control) : serial(_serial), control(_control)
{
  serial.println("Initialize HMC5883L");
  while (!compass.begin())
  {
    serial.println("Could not find a valid HMC5883L sensor, check wiring!");
    delay(500);
  }
  compass.setRange(HMC5883L_RANGE_1_3GA);
  compass.setMeasurementMode(HMC5883L_CONTINOUS);
  compass.setDataRate(HMC5883L_DATARATE_30HZ);
  compass.setSamples(HMC5883L_SAMPLES_8);
  compass.setOffset(0, 0);
}

float Compass::angulo()
{
  norm = compass.readNormalize();

  // Calculate heading
  heading = atan2(norm.YAxis, norm.XAxis);

  // Set declination angle on your location and fix heading
  // You can find your declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative
  // For Bytom / Poland declination angle is 4'26E (positive)
  // Formula: (deg + (min / 60.0)) / (180 / M_PI);
  float declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / M_PI);
  heading += declinationAngle;

  // Correct for heading < 0deg and heading > 360deg
  if (heading < 0)
  {
    heading += 2 * PI;
  }

  if (heading > 2 * PI)
  {
    heading -= 2 * PI;
  }

  // Convert to degrees
  float headingDegrees = heading * 180/M_PI; 

  delay(1);
  return headingDegrees;
}

void Compass::definePrecisao(int p)
{

}

void Compass::calibrar()
{
  // Initialize Initialize HMC5883L
  while (!compass.begin())
  {
    delay(500);
  }
  float maxX;
  float minX;
  float maxY;
  float minY;
  // Set measurement range
  compass.setRange(HMC5883L_RANGE_1_3GA);

  // Set measurement mode
  compass.setMeasurementMode(HMC5883L_CONTINOUS);

  // Set data rate
  compass.setDataRate(HMC5883L_DATARATE_30HZ);

  // Set number of samples averaged
  compass.setSamples(HMC5883L_SAMPLES_8);
  while (!control.botaoPressionado())
  {
    Vector mag = compass.readRaw();

    // Determine Min / Max values
    if (mag.XAxis < minX)
      minX = mag.XAxis;
    if (mag.XAxis > maxX)
      maxX = mag.XAxis;
    if (mag.YAxis < minY)
      minY = mag.YAxis;
    if (mag.YAxis > maxY)
      maxY = mag.YAxis;

    // Calculate offsets
    float offX = (maxX + minX) / 2;
    float offY = (maxY + minY) / 2;

    serial.print(mag.XAxis);
    serial.print(":");
    serial.print(mag.YAxis);
    serial.print(":");
    serial.print(minX);
    serial.print(":");
    serial.print(maxX);
    serial.print(":");
    serial.print(minY);
    serial.print(":");
    serial.print(maxY);
    serial.print(":");
    serial.print(offX);
    serial.print(":");
    serial.print(offY);
    serial.print("\n");
  }
}
