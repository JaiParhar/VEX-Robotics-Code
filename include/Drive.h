#include <main.h>
#include <vector>
#include <map>

class Drive {

  //Distance the bot will attempt to move to using PID
  int desiredDistance;

  //Rotation value the bot will attempt to turn to
  int desiredRotation;

  //Current distance
  int currentDistance;

  //Current rotation
  int currentRotation;

  //Constructor (Will initialize the bot)
  Drive();

  //Resets all the bot variables (Will be called in constructor)
  void reset();

  //Motor ports of the drive side (First half is right side, second half is left side)
  std::vector<int> driveMotors;

  //Set port as a drive motor (Boolean will be true if motor is on the right side)
  void addDriveMotor(int, bool);

  //This will automatically attempt to reach desiredRotation and desiredDistance
  //Must be run in a loop
  void updateDrive();

private:
  //Sets the motor speed of the drive side (True is right side)
  void setDriveSideSpeed(bool, int);

  //Sets the motor speed from the port
  void setMotorSpeed(int, int);

};
