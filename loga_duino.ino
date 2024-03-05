/*
  logaduino v1.0.0 
  March 5, 2024
  DESCRIPTION:
    Provides some of logic gates (AND, OR, NOT)
  OWNER:
    hm 
  PINOUT:
    AND GATE PINS:
      A1: 22
      B1: 23
      A2: 24
      B2: 25
      A3: 26
      B3: 27
      A4: 28
      B4: 29

      Y1: 2
      Y2: 3
      Y3: 4
      Y4: 5

    OR GATE PINS:
      A1: 30
      B1: 31
      A2: 32
      B2: 33
      A3: 34
      B3: 35
      A4: 36
      B4: 37

      Y1: 8
      Y2: 9
      Y3: 10
      Y4: 11

    NOT GATE PINS:
      A1: 38
      A2: 40
      A3: 42
      A4: 44
      A5: 46
      A6: 48

      Y1: 39
      Y2: 41
      Y3: 43
      Y4: 45
      Y5: 47
      Y6: 49
*/
byte andGateInputs[8];
byte orGateInputs[8];
byte notGateInputs[6];

byte andGateOutputs[4];
byte orGateOutputs[4];
byte notGateOutputs[6];

void setup() {
  for (int i = 0; i < 8; i++) {
    andGateInputs[i] = i + 22;
    orGateInputs[i] = i + 30;
    pinMode(andGateInputs[i], INPUT);
    pinMode(orGateInputs[i], INPUT);
  }
  byte x = 38;
  for (int i = 0; i < 6; i++) {
    notGateInputs[i] = x++;
    notGateOutputs[i] = x++;
    pinMode(notGateInputs[i], INPUT);
    pinMode(notGateOutputs[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    andGateOutputs[i] = i + 2;
    orGateOutputs[i] = i + 8;
    pinMode(andGateOutputs[i], OUTPUT);
    pinMode(orGateOutputs[i], OUTPUT);
  }
}

void checkAndGates() {
  byte x;
  for (int i = 0; i < 4; i++) {
    x = i * 2;
    if (digitalRead(andGateInputs[x]) && digitalRead(andGateInputs[x + 1])) {
      digitalWrite(andGateOutputs[i], HIGH);
    } else {
      digitalWrite(andGateOutputs[i], LOW);
    }
  }
}

void checkOrGates() {
  byte x;
  for (int i = 0; i < 4; i++) {
    x = i * 2;
    if (digitalRead(orGateInputs[x]) || digitalRead(orGateInputs[x + 1])) {
      digitalWrite(orGateOutputs[i], HIGH);
    } else {
      digitalWrite(orGateOutputs[i], LOW);
    }
  }
}

void checkNotGates() {
  for (int i = 0; i < 6; i++) {
    if (digitalRead(notGateInputs[i])) {
      digitalWrite(notGateOutputs[i], LOW);
    } else {
      digitalWrite(notGateOutputs[i], HIGH);
    }
  }
}

void loop() {
  checkAndGates();
  checkOrGates();
  checkNotGates();
  delay(50);
}
