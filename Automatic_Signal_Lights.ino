// Define IR sensor pins
const int ir1 = 8;
const int ir2 = 9;
const int ir3 = 10;
const int ir4 = 11;

void setup() {
  // Set IR sensor pins as input
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);

  // Set signal light pins as output
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  // Ensure all outputs are LOW initially
 // resetSignals();
}

void loop() {
  // Read IR sensor states
  int ir1State = digitalRead(ir1);
  int ir2State = digitalRead(ir2);
  int ir3State = digitalRead(ir3);
  int ir4State = digitalRead(ir4);

  resetSignals();

  // Logic for controlling signal lights
  if ((ir1State == 0) && (ir2State == 1) && (ir3State == 1) && (ir4State == 1)) {
    digitalWrite(6, HIGH); delay(1000);   resetSignals();
  } else if ((ir1State == 0) && (ir2State == 0) && (ir3State == 1) && (ir4State == 1)) {
    digitalWrite(7, HIGH); delay(1000);   resetSignals();
  } else if ((ir1State == 1) && (ir2State == 1) && (ir3State == 1) && (ir4State == 0)) {
    digitalWrite(2, HIGH);  delay(1000);   resetSignals();
  } else if ((ir1State == 1) && (ir2State == 1) && (ir3State == 0) && (ir4State == 0)) {
    digitalWrite(3, HIGH);  delay(1000);   resetSignals();
  } else if ((ir1State == 1) && (ir2State == 1) && (ir3State == 1) && (ir4State == 1)) {
    // No IR sensors are detecting anything
    digitalWrite(4, HIGH); // Connect Green Signal Lights at D4, D5
    digitalWrite(5, HIGH);
  }

  delay(100); // Small delay to stabilize readings
}

// Function to reset all signal lights
void resetSignals() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}
