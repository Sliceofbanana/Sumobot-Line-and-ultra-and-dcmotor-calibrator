// Pin assignments
const int triggerPin = 2;   // Ultrasonic sensor trigger pin
const int echoPin = 3;      // Ultrasonic sensor echo pin
const int irPin = 4;        // IR sensor pin
const int motor1Pin1 = 5;   // Motor 1 pin 1
const int motor1Pin2 = 6;   // Motor 1 pin 2
const int motor2Pin1 = 7;   // Motor 2 pin 1
const int motor2Pin2 = 8;   // Motor 2 pin 2

// Threshold values
const int irThreshold = 500;   // IR sensor threshold
const int distanceThreshold = 20;  // Distance threshold for obstacle detection (in cm)

void setup() {
  // Initialize pin modes
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}

void loop() {
  // Read sensors
  int irValue = analogRead(irPin);
  int distance = getUltrasonicDistance();

  // Line following logic
  if (irValue > irThreshold) {
    // Line detected, move forward
    moveForward();
  } else {
    // Line not detected, stop motors
    stopMotors();
  }

  // Obstacle detection logic
  if (distance < distanceThreshold) {
    // Obstacle detected, perform attack pattern
    attackPattern();
  }
}

int getUltrasonicDistance() {
  // Send ultrasonic pulse
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure echo pulse duration
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  int distance = duration * 0.034 / 2;
  return distance;
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void turnAround() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  delay(1000);  // Adjust the delay according to your robot's turning speed
}

void attackPattern() {
  // Perform attack pattern
  moveBackward();
  delay(500);  // Delay for 0.5 seconds

  turnLeft();
  delay(1000);  // Delay for 1 second

  moveForward();
  delay(1000);  // Delay for 1 second

  turnRight();
  delay(1000);  // Delay for 1 second

  stopMotors();
}

void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}