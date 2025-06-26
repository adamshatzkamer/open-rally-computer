#define POWER_LED_PIN 2
#define GPS_LOCK_LED_PIN 4
#define STATUS_LED_PIN 19

void setupLEDs() {
  pinMode(POWER_LED_PIN, OUTPUT);
  pinMode(GPS_LOCK_LED_PIN, OUTPUT);
  pinMode(STATUS_LED_PIN, OUTPUT);

  // Turn on the Power LED
  digitalWrite(POWER_LED_PIN, HIGH);
}

void updateGPSLockLED(bool gpsLock) {
  digitalWrite(GPS_LOCK_LED_PIN, gpsLock ? HIGH : LOW);
}

void updateStatusLED(bool status) {
  digitalWrite(STATUS_LED_PIN, status ? HIGH : LOW);
}

void indicateActivity() {
  static bool ledState = false;
  ledState = !ledState; // Toggle LED state
  digitalWrite(STATUS_LED_PIN, ledState ? HIGH : LOW);
}