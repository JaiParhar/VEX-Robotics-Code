#include <Drive.h>

Drive::Drive() {
  reset();
}

void Drive::addDriveMotor(int motorPort, bool rightSide) {
  if(rightSide) {
    //Adds motor port to the front of the driveMotor vector if the motor is on the right side
    driveMotors.insert(driveMotors.begin(), motorPort);
  } else {
    //Adds motor port to the back of the driveMotor vector if the motor is on the left side
    driveMotors.push_back(motorPort);
  }
}
