/* This example drives each motor on the Zumo forward, then
stops.  

The yellow user LED is on when a motor should be
running forward and off when a motor should be running backward.
If a motor on your Zumo has been flipped, you can correct its
direction by uncommenting the call to flipLeftMotor() or
flipRightMotor() in the setup() function. */

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4LCD lcd;
Zumo32U4Buzzer buzzer;

// From Demo
// A couple of simple tunes, stored in program space.
const char beepBrownout[] PROGMEM = "<c8";
const char beepWelcome[] PROGMEM = ">g32>>c32";
const char beepThankYou[] PROGMEM = ">>c32>g32";


void setup()
{
  // Uncomment if necessary to correct motor directions:
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);

  // Display the message to press A to start.
  lcd.clear();
  lcd.gotoXY(0,0);
  lcd.print(F("Press A"));
  lcd.print(F("..Running.."));

  buzzer.play("c32");
  delay(100);
  buzzer.play("e32");
  delay(100);
  buzzer.play("g32");
  
  // Wait for the user to press button A.
  buttonA.waitForButton();

  // Delay so that the robot does not move away while the user is
  // still touching it.
  delay(1000);
}

  
  
void loop()
{
  // Run both motors forward at full speed.
  ledYellow(1);
  motors.setSpeeds(400, 400);
 
  delay(1500);

  ledYellow(0);
  // Deccelerate
  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setSpeeds(speed, speed);
    delay(2);
  }
  
  delay(500);
  buzzer.play("g32");
  delay(100);
  buzzer.play("e32");
  delay(100);
  buzzer.play("c32");
  delay(100);
  buzzer.stopPlaying();
  exit(0);
}
