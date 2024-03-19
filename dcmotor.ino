
#define ENA 3    // Enable pin for Motor A
#define IN1 4    // Input 1 pin for Motor A
#define IN2 5    // Input 2 pin for Motor A
#define ENB 6    // Enable pin for Motor B
#define IN3 7    // Input 1 pin for Motor B
#define IN4 8    // Input 2 pin for Motor B

void setup() {
  // Set pin modes
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Move both motors forward
  motorControl(255, HIGH, LOW, 255, LOW, HIGH);  // Speed: 255 (max), Direction: Forward
  delay(2000);                                   // Move forward for 2 seconds

  // Stop both motors
  motorControl(0, LOW, LOW, 0, LOW, LOW);         // Speed: 0 (Stop), Direction: None
  delay(1000);                                   // Pause for 1 second

  // Move both motors backward
  motorControl(255, LOW, HIGH, 255, LOW, HIGH);  // Speed: 255 (max), Direction: Backward
  delay(2000);                                  // Move backward for 2 seconds

  // Stop both motors
  motorControl(0, LOW, LOW, 0, LOW, LOW);        // Speed: 0 (Stop), Direction: None
  delay(1000);                                  // Pause for 1 second
}

// Function to control the motors
void motorControl(int speedA, bool in1StateA, bool in2StateA, int speedB, bool in3StateB, bool in4StateB) {
  analogWrite(ENA, speedA);  // Set motor A speed using PWM
  digitalWrite(IN1, in1StateA);
  digitalWrite(IN2, in2StateA);

  analogWrite(ENB, speedB);  // Set motor B speed using PWM
  digitalWrite(IN3, in3StateB);
  digitalWrite(IN4, in4StateB);
}