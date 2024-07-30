int ledPin = 13; // Built-in LED pin on Arduino board
int pirPin = 2;  // Pin for the PIR sensor output
int pirState = LOW; // Variable to store the PIR state
int lastPirState = LOW; // Variable to store the last PIR state

void setup() {
  pinMode(ledPin, OUTPUT); // Set built-in LED pin as output
  pinMode(pirPin, INPUT);  // Set PIR sensor pin as input
  Serial.begin(9600);      // Initialize serial communication

  // Give the PIR sensor time to stabilize
  delay(2000); // Wait 2 seconds
  Serial.println("PIR Sensor initialized");
}

void loop() {
  pirState = digitalRead(pirPin); // Read PIR sensor state

  if (pirState != lastPirState) {
    if (pirState == HIGH) {
      // Motion detected
      digitalWrite(ledPin, HIGH); // Turn on built-in LED
      Serial.println("Motion detected");
    } else {
      // No motion detected
      digitalWrite(ledPin, LOW); // Turn off built-in LED
      Serial.println("No motion detected");
    }
    // Update lastPirState
    lastPirState = pirState;
  }

  delay(100); // Wait for a while
}
