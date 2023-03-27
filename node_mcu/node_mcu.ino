#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "circuit-breaker-a6f85-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "bhysAkLmibu0untyZcEQtftIko4L1Ts4cQ4IJrN4"
#define WIFI_SSID "TP-Link_732C"
#define WIFI_PASSWORD "82853433"

#define LINE_1 D1
#define LINE_2 D2
#define LINE_3 D3
#define LINE_4 D4
void setup() {
    pinMode(LINE_1, OUTPUT);
    pinMode(LINE_2, OUTPUT);
    pinMode(LINE_3, OUTPUT);
    pinMode(LINE_4, OUTPUT);
    Serial.begin(115200);
  
    // connect to wifi.
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("connecting");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".=");
      delay(500);
    }
    Serial.println();
    Serial.print("connected: ");
    Serial.println(WiFi.localIP());
    
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}


void loop() {
  // put your main code here, to run repeatedly:
    Serial.println(Firebase.getBool("Line1"));
    digitalWrite(LINE_1, Firebase.getBool("Line1"));
    digitalWrite(LINE_2, Firebase.getBool("Line2"));
    digitalWrite(LINE_3, Firebase.getBool("Line3"));
    digitalWrite(LINE_4, Firebase.getBool("Line4"));
    delay(500);
}
