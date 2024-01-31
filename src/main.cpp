#include <Arduino.h>
#include <DHT.h>

#define SENSOR 33
#define LED 26
#define DHTTYPE DHT11   // Utilisation du DHT11

DHT dht(SENSOR, DHTTYPE);

void setup() {
  // Initialisation de la communication série
  Serial.begin(9600);
  dht.begin(); // Initialisation du capteur DHT

  // Laissez le temps à la communication série de s'initialiser
  delay(1000); // Attendre 1 seconde

  // Prendre une mesure
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Vérification des lectures échouées
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // Affichage des valeurs de température et d'humidité
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
  }

  // Configuration du timer pour le Deep Sleep (5 secondes = 5000000 microsecondes)
  esp_sleep_enable_timer_wakeup(5000000);

  delay(10);
  Serial.flush();
  // Mise en Deep Sleep
  esp_deep_sleep_start();

}

void loop() {
  // La fonction loop est vide car toute la logique est dans setup et l'ESP32 va dormir après chaque mesure
}
