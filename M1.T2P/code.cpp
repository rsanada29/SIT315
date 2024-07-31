int ledPin = 13; //Pin for the LED
int pirPin = 2;  //Pin for the PIR sensor output
volatile int pirState = LOW; //marked as volatile

void setup() {
  pinMode(ledPin, OUTPUT); //Set LED pin as output
  pinMode(pirPin, INPUT);  //Set PIR sensor pin as input
  Serial.begin(9600);      //Initialize serial communication

  delay(1500); //Wait 1.5 seconds
  Serial.println("PIR Sensor initialized");

  //the initial state of the built-in LED to off
  digitalWrite(ledPin, LOW);
  Serial.println("LED OFF");

  //attach interrupt to the PIR sensor pin
  attachInterrupt(digitalPinToInterrupt(pirPin), pirISR, CHANGE);
}

void loop() {
  //using interrupts
}

void pirISR() {
  pirState = digitalRead(pirPin); //Read the PIR sensor

  if (pirState == HIGH) {
    digitalWrite(ledPin, HIGH); //LED On
    Serial.println("LED ON");
  } else {
    digitalWrite(ledPin, LOW); //LED Off
    Serial.println("LED OFF");
  }
}
