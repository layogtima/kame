#include <Servo.h>
#include <FlexiTimer2.h>

// Individual Servo objects with descriptive names
Servo servo_front_right_hip;
Servo servo_front_left_hip;
Servo servo_back_right_hip;
Servo servo_back_left_hip;
Servo servo_front_right_knee;
Servo servo_front_left_knee;
Servo servo_back_right_knee;
Servo servo_back_left_knee;

// Corresponding pin numbers
const int pin_front_right_hip = 4;
const int pin_front_left_hip = 9;
const int pin_back_right_hip = 7;
const int pin_back_left_hip = 5;
const int pin_front_right_knee = 6;
const int pin_front_left_knee = 8;
const int pin_back_right_knee = 3;
const int pin_back_left_knee = 2;

// Array of pointers to Servo objects
Servo* servos[] = {
  &servo_front_right_hip, &servo_front_left_hip,
  &servo_back_right_hip, &servo_back_left_hip,
  &servo_front_right_knee, &servo_front_left_knee,
  &servo_back_right_knee, &servo_back_left_knee
};

// Array of pin numbers
const int servoPins[] = {
  pin_front_right_hip, pin_front_left_hip,
  pin_back_right_hip, pin_back_left_hip,
  pin_front_right_knee, pin_front_left_knee,
  pin_back_right_knee, pin_back_left_knee
};

// Array of homing positions
const int homePositions[] = {60, 120, 60, 120, 125, 55, 55, 125};

// Servo names for logging
const char* servoNames[] = {
  "Front Right Hip", "Front Left Hip",
  "Back Right Hip", "Back Left Hip",
  "Front Right Knee", "Front Left Knee",
  "Back Right Knee", "Back Left Knee"
};

const int NUM_SERVOS = sizeof(servos) / sizeof(servos[0]);

// Current position and target position for the active servo
volatile int currentPosition = 0;
volatile int targetPosition = 0;

// Index of the currently active servo
volatile int activeServo = 0;

// Step size for smooth movement
const int stepSize = 1;

// Range of motion (±30 degrees)
const int range = 30;

void setup() {
  Serial.begin(115200);
  
  // Attach all servos
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i]->attach(servoPins[i]);
    servos[i]->write(homePositions[i]);
  }
  
  delay(2000); // Wait for servos to reach home position
  
  // Set up FlexiTimer2
  FlexiTimer2::set(20, moveServo);
  FlexiTimer2::start();
  
  // Start with the first servo
  startNextServo();
}

void loop() {
  // The main work is done in the timer interrupt
  // We'll just check if it's time to move to the next servo
  if (currentPosition == homePositions[activeServo]) {
    delay(1000); // Pause at home position
    startNextServo();
  }
}

void moveServo() {
  if (currentPosition < targetPosition) {
    currentPosition = min(currentPosition + stepSize, targetPosition);
  } else if (currentPosition > targetPosition) {
    currentPosition = max(currentPosition - stepSize, targetPosition);
  }
  
  servos[activeServo]->write(currentPosition);
}

void startNextServo() {
  activeServo = (activeServo + 1) % NUM_SERVOS;
  currentPosition = homePositions[activeServo];
  
  Serial.print("Moving servo: ");
  Serial.print(servoNames[activeServo]);
  Serial.print(" (Pin ");
  Serial.print(servoPins[activeServo]);
  Serial.println(")");
  
  // Move to min position
  targetPosition = max(homePositions[activeServo] - range, 0);
  while (currentPosition != targetPosition) {
    delay(20);
  }
  
  // Move to max position
  targetPosition = min(homePositions[activeServo] + range, 180);
  while (currentPosition != targetPosition) {
    delay(20);
  }
  
  // Return to home position
  targetPosition = homePositions[activeServo];
}
