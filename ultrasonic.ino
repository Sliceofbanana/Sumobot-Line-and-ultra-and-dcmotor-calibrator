// Define the pins for Trig and Echo
const int trigPin = 9;
const int echoPin = 10;

// Variables to store the distance and duration
long duration;
int distance;

void setup() {
  // Set the trigPin as an output and echoPin as an input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize the serial communication
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a short pulse to the trigPin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo signal
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the speed of sound
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Wait for a short delay before taking another measurement
  delay(500);
}
