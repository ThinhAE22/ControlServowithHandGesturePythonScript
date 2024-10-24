#include <ESP32Servo.h>

// Define the servo and its GPIO pin
Servo myServo;
int servoPin = 5;  // Change the pin according to your setup (e.g., D1 is GPIO 5 on NodeMCU)

void setup() {
  // Initialize Serial for debugging
  Serial.begin(115200);
  
  // Attach the servo to the pin
  myServo.attach(servoPin);
  Serial.println("Servo is ready!");
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');  // Read until newline character
    int pos = input.toInt();  // Convert the input string to an integer

    // Ensure pos is within the valid range for the servo
    if (pos >= 0 && pos <= 180) {
      myServo.write(pos);      // Tell servo to go to 'pos'
      Serial.print("Moving servo to: ");
      Serial.println(pos);
      delay(15);               // Wait for the servo to reach the position
    } else {
      Serial.println("Invalid position. Must be between 0 and 180.");
    }
  }
}
