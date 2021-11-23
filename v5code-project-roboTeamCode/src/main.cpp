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
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
// :^)
using namespace vex;

void turn(bool rDir, int rotationDegrees) {
  RightMotor.setVelocity(0, percent);
  LeftMotor.setVelocity(0, percent);
  if (rDir) {
    double rotationTotal = Inertial7.rotation(degrees) + rotationDegrees;
    while (Inertial7.rotation(degrees) < rotationTotal) {

      RightMotor.spin(reverse);
      LeftMotor.spin(forward);

      RightMotor.setVelocity(50, percent);
      LeftMotor.setVelocity(50, percent);
    }
  } else {
    double rotationTotal = Inertial7.rotation(degrees) - rotationDegrees;
    while (Inertial7.rotation(degrees) > rotationTotal) {

      RightMotor.spin(forward);
      LeftMotor.spin(reverse);

      RightMotor.setVelocity(50, percent);
      LeftMotor.setVelocity(50, percent);
    }
  }
  RightMotor.setVelocity(0, percent);
  LeftMotor.setVelocity(0, percent);
}

void autoMode(bool rSide) {
  // uncurl

  if (rSide) {
    // move forward lil bit
    // rotate 45ish degrees right
    // move forward until hit goal (method TBD)

    // move back small amount
    // turn so arm is over pole
    // dump the rings

    // turn back
    // move forwards
    // pick up goal
    // move back until past line
    // rotate goal
    // put down

    // move to other goal
    // pickup
    // bring back

  } else {
    // angle bot
    // dump rings
    // unangle bot
    // pick up goal
    // move onto goal
  }
}

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
  if (Controller1.ButtonRight.pressing()) {
    autoMode(1);
  } else if (Controller1.ButtonLeft.pressing()) {
    autoMode(0);
  }
}
