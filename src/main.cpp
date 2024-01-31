#include <Arduino.h>
#include <DHT.h>

// Define the pins that we will use
#define SENSOR 33
#define LED 26
#define DHTTYPE DHT11   // DHT 11

// Initialize DHT sensor.
DHT dht(SENSOR, DHTTYPE);

void setup() {
  Serial.begin(9600); // Start the serial communication
  pinMode(LED, OUTPUT); // Initialize the LED pin as an output
  dht.begin(); // Initialize the DHT sensor
}

void loop() {
  // Effectuer une mesure toutes les 5s
  delay(2000); // Wait for 5 seconds between measurements

  // Read humidity and temperature values
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Afficher l'humidité relative avec un peu de formatage
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.println(F("%"));

  // Afficher la température avec un peu de formatage
  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.println(F("°C"));
}
