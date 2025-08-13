#include "arduino_bma456.h"
// Define pins
#define LED_PIN 2
#define BUTTON_PIN 15
uint32_t step = 0; // variable to store step count
uint32_t stepoffset = 0; // Offset to simulate step reset
bool ledon = false; // Track LED state
bool buttonPressed = false;
void setup() {
    Serial.begin(115200);
    Serial.println("BMA456 Step Counter");
    // Initialize BMA456 sensor
    bma456.initialize(RANGE_4G, ODR_100_HZ, NORMAL_AVG4, CONTINUOUS);
    bma456.stepCounterEnable();
    // Initialize pins
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Use internal pull-up resistor
    // Ensure LED is off at the start
    digitalWrite(LED_PIN, LOW);
}
// Custom function to reset step count by setting an offset
void resetStepCount() {
    stepoffset = bma456.getStepCounterOutput(); // Store the current step count as offset
}
void loop() {
    // Get the current step count from the sensor
    step = bma456.getStepCounterOutput() - stepoffset; // Subtract offset to reset the count
    Serial.print("Step: ");
    Serial.println(step);
    // Check step count and LED state to control LED
    if (step > 20 && !ledon) {
        digitalWrite(LED_PIN, HIGH);
        ledon = true;
        Serial.println("LED turned on due to step count exceeding 20.");
        resetstepCount(); // Reset step count
    }
    // Check button state to turn off LED
    if (digitalRead(BUTTON_PIN) == LOW) { // Button pressed (assuming active LOW)
        digitalWrite(LED_PIN, LOW); // Turn off LED
        ledon = false;
        Serial.println("Button pressed! LED turned off.");
        delay(500); // Debounce delay
    }
    delay(500); // Delay to reduce print frequency
}