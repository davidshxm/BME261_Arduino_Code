#include <Servo.h>

Servo myservo1;
Servo myservo2;

void setup() {
  Serial.begin(9600);

  // === Setup Code for Part 4.1 === //
  myservo1.attach(11); // Position servo

  // === Setup Code for Part 4.2 === //
  myservo2.attach(9);  // Continuous rotation servo
}

void posServo() {
  if (Serial.available() > 0) {
    int targetPos = Serial.parseInt(); // Read integer input from Serial

    // Clamp input between 0 and 180
    targetPos = constrain(targetPos, 0, 180);

    myservo1.write(targetPos); // Move servo to target position
    Serial.print("Moving servo to position: ");
    Serial.println(targetPos);
  }
}

void rotServo() {
  if (Serial.available() > 0) {
    int speedPercent = Serial.parseInt(); // Read integer input from Serial

    // Clamp value between -100 and 100
    speedPercent = constrain(speedPercent, -100, 100);

    // Map -100 to 100 -> 0 to 180 (servo control range)
    int servoSignal = map(speedPercent, -100, 100, 0, 180);

    myservo2.write(servoSignal); // Set servo speed/direction
    Serial.print("Speed (%): ");
    Serial.print(speedPercent);
    Serial.print(" => Servo Signal: ");
    Serial.println(servoSignal);
  }
}

void loop() {
  // Uncomment one of the following to test:
  //posServo(); // For position control on pin 11
  rotServo(); // For continuous rotation on pin 9
  delay(5);
}
