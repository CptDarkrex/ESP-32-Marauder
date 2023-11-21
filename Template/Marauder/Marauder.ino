#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "Gaming Network";
const char* password = "Wherewedropping?";

WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>Welcome to my home ESP32 web server!</h1>");
}

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  Serial.println("Access Point Started");

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
