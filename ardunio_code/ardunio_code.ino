#include <Wire.h>
#include <DS3231.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// RTC and timer variables
DS3231 rtc;
bool timerRunning = false;
unsigned long setTime = 0;
unsigned long startTime = 0;

// Button pin assignments
const int button30Sec = 2;
const int button1Min = 3;
const int buttonStart = 4;

// MP3 module pins and objects
static const uint8_t PIN_MP3_TX = 10; // Connects to DFPlayer RX
static const uint8_t PIN_MP3_RX = 11; // Connects to DFPlayer TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
DFRobotDFPlayerMini player;

void setup() {
  // Button pin modes
  pinMode(button30Sec, INPUT_PULLUP);
  pinMode(button1Min, INPUT_PULLUP);
  pinMode(buttonStart, INPUT_PULLUP);
  
  // Initialize serial for debugging and DFPlayer
  Serial.begin(9600);
  softwareSerial.begin(9600);

  // Initialize DFPlayer Mini
  if (player.begin(softwareSerial)) {
    Serial.println("DFPlayer Mini online.");
    player.volume(30);  // Set volume to maximum (30)
    player.stop();      // Ensure no track is playing initially
  } else {
    Serial.println("Failed to initialize DFPlayer Mini.");
  }
}

void loop() {
  // 30-second button pressed
  if (digitalRead(button30Sec) == LOW) {
    setTime += 30000; // Add 30 seconds
    delay(300);       // Debounce delay
    Serial.print("Timer Set: ");
    Serial.println(setTime / 1000); // Display timer in seconds
  }

  // 1-minute button pressed
  if (digitalRead(button1Min) == LOW) {
    setTime += 60000; // Add 1 minute
    delay(300);       // Debounce delay
    Serial.print("Timer Set: ");
    Serial.println(setTime / 1000); // Display timer in seconds
  }

  // Start button pressed
  if (digitalRead(buttonStart) == LOW && setTime > 0 && !timerRunning) {
    startTime = millis(); // Record the start time
    timerRunning = true;
    Serial.println("Timer Started");
    delay(300); // Debounce delay
    
    // Play the MP3 when the timer starts
    player.play(1);  // Play the first track (0001.mp3)
  }

  // Timer running, check if time is up
  if (timerRunning) {
    if (millis() - startTime >= setTime) {
      timerRunning = false;
      setTime = 0;
      Serial.println("Timer Done");
      // Stop the MP3 when the timer finishes
      player.stop();   // Stop the song
    }
  }
}
