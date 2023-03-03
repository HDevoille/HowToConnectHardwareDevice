#include <WiFi.h>

const char* ssid = "YourSSID";
const char* password = "YourPassword";
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }

  Serial.println("Connected to Wi-Fi.");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Server started.");
}

void loop() {
   WiFiClient client = server.available();
  if (client) {
    Serial.println("New client connected.");
    while (client.connected()) {
      if (client.available()) {
        String request = client.readStringUntil('\r');
        Serial.println(request);
        client.flush();
      }
    }
    Serial.println("Client disconnected.");
  }
}
