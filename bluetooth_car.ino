char command = 's'; // move forward, backward; turn left or right
const int A1A = 2; // pins for two motors
const int A1B = 3;
const int B1A = 8;
const int B1B = 9;

void setup() {
  Serial.begin(9600); // baud rate
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  pinMode(B1A, OUTPUT);
  pinMode(B1B, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    command = Serial.read(); // read the command from bluetooth
    Serial.println(command); // print the command on serial monitor

    switch (command) {
      case 'f': // move forward
        digitalWrite(A1A, HIGH);
        digitalWrite(A1B, LOW);
        digitalWrite(B1A, HIGH);
        digitalWrite(B1B, LOW);
        break;
      case 'b': // move backward
        digitalWrite(A1A, LOW);
        digitalWrite(A1B, HIGH);
        digitalWrite(B1A, LOW);
        digitalWrite(B1B, HIGH);
        break;
      case 'l': // turn left
        digitalWrite(A1A, HIGH);
        digitalWrite(A1B, LOW);
        digitalWrite(B1A, LOW);
        digitalWrite(B1B, HIGH);
        break;
      case 'r': // turn right
        digitalWrite(A1A, LOW);
        digitalWrite(A1B, HIGH);
        digitalWrite(B1A, HIGH);
        digitalWrite(B1B, LOW);
        break;
      default: // stop
        digitalWrite(A1A, LOW);
        digitalWrite(A1B, LOW);
        digitalWrite(B1A, LOW);
        digitalWrite(B1B, LOW);
        break;
    }
  }
}
