#include <Arduino.h>

// Pin definitions
const int RE_A = 18;   // CLK
const int RE_B = 19;   // DT
const int RE_BTN = 21; // SW

// Global variables for encoder state
volatile int encoderValue = 0;
volatile bool rotated = false;
volatile bool clockwise = false;

// Interrupt Service Routine (ISR) for the encoder
void IRAM_ATTR handleEncoder() {
  int aState = digitalRead(RE_A);
  int bState = digitalRead(RE_B);

  if (aState == LOW) {
    if (bState == HIGH) {
      encoderValue++;
      clockwise = true;
    } else {
      encoderValue--;
      clockwise = false;
    }
    rotated = true;
  }
}

void setup() {
  Serial.begin(9600);
  
  pinMode(RE_A, INPUT_PULLUP);
  pinMode(RE_B, INPUT_PULLUP);
  pinMode(RE_BTN, INPUT_PULLUP);

  // Attach interrupt to pin A (CLK) on falling edge
  attachInterrupt(digitalPinToInterrupt(RE_A), handleEncoder, FALLING);

  Serial.println("Rotary Encoder Initialized");
}

void loop() {
  // Handle rotation
  if (rotated) {
    Serial.print("Rotation: ");
    if (clockwise) {
      Serial.println("Clockwise");
    } else {
      Serial.println("Anticlockwise");
    }
    Serial.print("Encoder Value: ");
    Serial.println(encoderValue);
    rotated = false;
  }

  // Handle button press
  static int lastBtnState = HIGH;
  int btnState = digitalRead(RE_BTN);
  
  if (btnState != lastBtnState) {
    if (btnState == LOW) {
      Serial.println("Button: Pressed");
    } else {
      Serial.println("Button: Released");
    }
    lastBtnState = btnState;
    delay(50); // Simple debounce
  }
}
