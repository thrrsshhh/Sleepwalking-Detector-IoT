#include <esp_now.h>
#include <WiFi.h>
// Define pins
#define BUZZER_PIN 13 // Buzzer connected to GPIO 13
// Structure to receive data
typedef struct {
    bool ledon;
} struct_message;
struct_message receivedData;
void setup() {
    Serial.begin(115200);
    // Initialize pins
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW); // Ensure buzzer is off at start
    // Set device as a Wi-Fi Station
    WiFi.mode(WIFI_STA);
    // Initialize ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
    // Register receive callback
    esp_now_register_recv_cb(onDataRecv);
}
void onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
    memcpy(&receivedData, incomingData, sizeof(receivedData));
    // Turn on the buzzer if LED is on, otherwise turn it off
    if (receivedData.ledon) {
        digitalWrite(BUZZER_PIN, HIGH); // Turn on buzzer
        Serial.println("Buzzer turned on due to LED on remote ESP32.");
    } else {
        digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
        Serial.println("Buzzer turned off due to LED off on remote ESP32.");
    }
}
void loop() {
    // Nothing needed here, as the onDataRecv callback handles the buzzer control
}