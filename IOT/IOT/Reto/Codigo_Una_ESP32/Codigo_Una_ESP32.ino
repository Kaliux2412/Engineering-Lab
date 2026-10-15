#define BLYNK_TEMPLATE_ID "TMPL2KC7fDYow"
#define BLYNK_TEMPLATE_NAME "Practica IOT"
#define BLYNK_AUTH_TOKEN "9KdDHkEV07ca0InFcdB4HLkOvoSIVXX_"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <WiFiClient.h>

// Configuración de Wi-Fi
char ssid[] = "DAMARIS 3266";
char pass[] = "damarissss";

const int LED_PIN = 12;
const int BUTTON_PIN = 13;

bool ledState = false;

// Variables para antirrebote
int buttonState = HIGH;
int lastButtonReading = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

// Recibir el estado desde la aplicación
BLYNK_WRITE(V0) {
  ledState = (param.asInt() != 0);
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);

  Serial.print("LED: ");
  Serial.println(ledState ? "Encendido" : "Apagado");
}

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V0);
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  digitalWrite(LED_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
  Blynk.syncVirtual(V0);

  int reading = digitalRead(BUTTON_PIN);

  // Reiniciar el tiempo si cambia la lectura
  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  // Aceptar el cambio cuando la lectura sea estable
  if (millis() - lastDebounceTime >= debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      // Con INPUT_PULLUP, LOW significa presionado
      if (buttonState == LOW) {
        ledState = !ledState;

        // Actualizar el interruptor de la aplicación
        if (Blynk.connected()) {
          Blynk.virtualWrite(V1, ledState ? 1 : 0);
        }
      }
    }
  }

  lastButtonReading = reading;
}
