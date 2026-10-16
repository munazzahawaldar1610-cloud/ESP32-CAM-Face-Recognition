/*
 * ESP32-CAM firmware: camera initialisation + Wi-Fi camera web server
 * Board: AI Thinker ESP32-CAM  (Arduino IDE, ESP32 board support installed)
 *
 * Requires, in the same sketch folder (as in the ESP32 CameraWebServer example):
 *   - camera_pins.h        (pin map for CAMERA_MODEL_AI_THINKER)
 *   - an implementation of startCameraServer()  (e.g. app_httpd.cpp)
 *
 * Upload tip: tie GPIO0 to GND, press the upload button, press RESET when
 * dots appear; after upload remove the GPIO0-GND link and press RESET again.
 * Open the Serial Monitor at 115200 baud to see the board's IP address.
 */
#include "esp_camera.h"
#include <WiFi.h>

// Camera model: AI Thinker
#define CAMERA_MODEL_AI_THINKER
#include "camera_pins.h"

// Wi-Fi credentials: replace with your own and never commit real ones
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

void startCameraServer();

void setup() {
  Serial.begin(115200);

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  // Lower resolution to reduce lag
  if (psramFound()) {
    config.frame_size = FRAMESIZE_QVGA;   // 320x240 (fastest for web)
    config.jpeg_quality = 15;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_QVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed!");
    return;
  }

  // Wi-Fi connect
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  startCameraServer();
  Serial.println("\nWiFi Connected!");
  Serial.print("Use this IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  delay(10000);
}
