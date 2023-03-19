#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "circuit-breaker-3fd42-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "gQWpQ2OpQMnZIWFvOhxNDJJp24dG8vhRRTbpwTs9"
#define WIFI_SSID "TP-Link_732C"
#define WIFI_PASSWORD "82853433"

void setup() {
    pinMode(5, OUTPUT);
    Serial.begin(115200);
  
    // connect to wifi.
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("connecting");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
    Serial.println();
    Serial.print("connected: ");
    Serial.println(WiFi.localIP());
    
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}


void loop() {
  // put your main code here, to run repeatedly:
    Serial.println(Firebase.getInt("Line1"));
    Firebase.setInt("Line2", 1);
    digitalWrite(5, Firebase.getInt("Line1"));
    delay(500);

}
