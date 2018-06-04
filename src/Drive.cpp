#include <Drive.h>

Drive::Drive() {
  reset();
}

void Drive::addDriveMotor(unsigned char motorPort, bool rightSide) {
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
    motorSet(driveMotors.at(start), speed);
  }
}

void Drive::moveTo(int distance) {
  desiredDistance = distance;
}

void Drive::turnTo(int rotation) {
  desiredRotation = rotation;
}

int Drive::getCurrentDistance() {
  return currentDistance;
}

int Drive::getCurrentRotation() {
  return currentRotation;
}

void Drive::resetDistance() {
  desiredDistance = 0;
  currentDistance = 0;
}

void Drive::resetRotation() {
  desiredRotation = 0;
  currentRotation = 0;
}

void Drive::reset() {
  desiredDistance = 0;
  desiredRotation = 0;
  currentDistance = 0;
  currentRotation = 0;
}
