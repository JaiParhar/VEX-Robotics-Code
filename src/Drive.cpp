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

void Drive::setDriveSideSpeed(bool rightSide, int speed) {
  //Where the iterator should begin
  int start = 0;

  //Where the iterator should end
  int end = driveMotors.size()/2;

  if(!rightSide) {
    start += driveMotors.size()/2;
    end += driveMotors.size()/2;
  }

  for(; start < end; start++) {
    motorSet(driveMotors.get(start), speed);
  }
}
