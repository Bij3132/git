# include "angle_s.h"



AS5600 as5600;      // initiate the sensor instance using the I2c configuration

void angle_s_init()
{
    Wire.begin();         //init i2c
    as5600.begin();        //init the sensor
}

void sensor_status()
{
int b = as5600.isConnected();    // variable for storing angle status
  Serial.print("Connect: ");
  Serial.println(b);
}

uint16_t sensor_angle()
{
  uint16_t angle;
  angle= as5600.readAngle()* AS5600_RAW_TO_DEGREES; // reading angle and printing to serail
  return angle;
  delay(1000);
    
}




