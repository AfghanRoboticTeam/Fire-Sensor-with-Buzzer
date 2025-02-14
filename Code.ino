// Pin definitions
const int fireSensorPin = 2; // Digital pin for fire sensor
const int buzzerPin = 9;      // Digital pin for buzzer

void setup() {
  // Initialize the fire sensor pin as an input
  pinMode(fireSensorPin, INPUT);
  // Initialize the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
  // Start the serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the value from the fire sensor
  int sensorValue = digitalRead(fireSensorPin);
  
  // Print the sensor value to the Serial Monitor
  Serial.print("Fire Sensor Value: ");
  Serial.println(sensorValue);
  
  // Check if the sensor detects fire (LOW means fire detected)
  if (sensorValue == LOW) {
    // If fire is detected, sound the buzzer
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    delay(5000);                    // Buzzer on for 1 second
    digitalWrite(buzzerPin, LOW);  // Turn off the buzzer
    delay(1000);                    // Wait for 1 second before checking again
  } else {
    // If no fire is detected, ensure the buzzer is off
    digitalWrite(buzzerPin, LOW);
  }
  
  // Small delay before the next reading
  delay(500);
}
