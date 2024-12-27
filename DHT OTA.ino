#include <ESP8266WiFi.h>  // Ganti dengan <WiFi.h> jika menggunakan ESP32
#include <ESP8266WebServer.h>  // Ganti dengan <WebServer.h> jika menggunakan ESP32
#include <ArduinoOTA.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Konfigurasi WiFi
const char* ssid = "JiTi MtrEdtn";
const char* password = "Rjitime21";

// Konfigurasi DHT
#define DHTPIN D2  // Pin data DHT22
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Web server
ESP8266WebServer server(80);

void setup() {
  // Inisialisasi Serial
  Serial.begin(115200);
  Serial.println("Booting...");

  // Inisialisasi DHT
  dht.begin();

  // Koneksi WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.println(WiFi.localIP());

  // Setup OTA
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else  // U_SPIFFS
      type = "filesystem";

    // Hapus file jika perlu
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() { Serial.println("\nEnd"); });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR)
      Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR)
      Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR)
      Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR)
      Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR)
      Serial.println("End Failed");
  });
  ArduinoOTA.begin();

  // Setup server
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  ArduinoOTA.handle();  // Jalankan OTA
  server.handleClient();  // Jalankan server
}

// Halaman utama
void handleRoot() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    server.send(500, "text/plain", "Sensor error!");
    return;
  }

  String html = "<html><body>";
  html += "<h1>Monitoring Suhu</h1>";
  html += "<p>Suhu: " + String(temperature) + " &deg;C</p>";
  html += "<p>Kelembaban: " + String(humidity) + " %</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}
