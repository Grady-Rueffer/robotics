/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Parker                                           */
/*    Created:      Tue Nov 09 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightMotor           motor         1               
// LeftMotor            motor         10              
// Inertial7            inertial      7               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

bool rc = true;
int deadBand = 5;
int rightSpeed;
int leftSpeed;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while (rc) {

    // how fast it move
    rightSpeed = Controller1.Axis2.position(percent);
    leftSpeed = Controller1.Axis3.position(percent);
    // antistick-drift
    if (abs(rightSpeed) < deadBand) {
      RightMotor.setVelocity(0, percent);

    } else {
      RightMotor.setVelocity(rightSpeed, percent);
    }

    if (abs(leftSpeed) < deadBand) {
      LeftMotor.setVelocity(0, percent);

    } else {
      LeftMotor.setVelocity(leftSpeed, percent);
    }
    RightMotor.spin(forward);
    LeftMotor.spin(forward);
  }
}
// test test test