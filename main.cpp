//
//    FILE: AS5600_demo.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo
//    DATE: 2022-05-28

#include <AccelStepper.h>
# include "angle_s.h"
#define ZERO_POS 180
#define KP 0.2
#define KD 0.02
#define STEP_ANGLE_RATIO 17.777777
#define MAX_STEP 6400
bool init_flag = false;
// Define a stepper and the pins it will use
AccelStepper stepper(AccelStepper::DRIVER, 2, 3);  //StepPin D2 and DirPin D3
uint16_t angle_error = 0, angle_error_last = 0, output = 0, velocity = 0;
void setup()
{
 
 angle_s_init();
 stepper.setMaxSpeed(MAX_STEP);

}


void loop()
{
 Serial.println(sensor_angle());
 angle_error = ZERO_POS - sensor_angle();
 Serial.println(angle_error);
 output = STEP_ANGLE_RATIO * angle_error;
 velocity = angle_error/abs(angle_error) * 1000;
 if(output > MAX_STEP)  output = MAX_STEP;
 if(output < -MAX_STEP)  output = -MAX_STEP;
 if(!init_flag) {
  stepper.moveTo(output);   
  stepper.setSpeed(velocity);
 }
  while (stepper.distanceToGo() != 0)
  {
    stepper.runSpeedToPosition();    
  }
  if(!init_flag) {
  init_flag = true;
  }
//   output = KP * angle_error + KD * (angle_error - angle_error_last);
// if(output > 100)  output = 100;
// if(output < -100)  output = -100;
// angle_error_last = angle_error;
//  if(!init_flag) {
//       if(angle_error <= 5)
//         init_flag = true;
//       else{
        // stepper.moveTo(output);   
//         stepper.setSpeed(100); 
//       }
//  }
    // while (stepper.distanceToGo() != 0)
    //   {
    //     stepper.runSpeedToPosition();    
    //   }

      // Serial.println(angle_error);
      Serial.println(output);
      delay(1000);
}

// void setup()
// {  
//   stepper.setMaxSpeed(1000);
//   stepper.moveTo(100);   
//   stepper.setSpeed(1000);    
// }

// void loop()
// { 
//   if (stepper.distanceToGo() == 0)
//   {
//     stepper.moveTo(-(stepper.currentPosition()));
//     stepper.setSpeed(1000);    
//   }
  
//   while (stepper.distanceToGo() != 0)
//   {
//     stepper.runSpeedToPosition();    
//   }
//   delay(1000);
// }


// -- END OF FILE --
