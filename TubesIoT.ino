#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <DHT.h>

#define FIREBASE_HOST "iot4tubeskel2.firebaseio.com"
#define FIREBASE_AUTH "I8MCG0EJNoi4XM3gecdMdymBK8jaI7Bv8H5FqrUe"

#define WIFI_SSID "D-Link 114"
#define WIFI_PASSWORD "1sampai8"

#define DHT_PIN   D3
#define DHT_TYPE  DHT11
#define SOIL_PIN  A0
#define PUMP_PIN  D4

#define ACTIVE      HIGH
#define NON_ACTIVE  LOW

DHT dht(DHT_PIN, DHT_TYPE);  //setting pin yang dipilih dan tipe DHT

String MACAdd;
String DBHumiTanah;
String DBHumiLing;
String DBSuhuLIng;
String DBPump;

String DBUpdateTgl;
String DBUpdateWaktu;

String DBHumiRefMin;
String DBHumiRefMax;

String DBHumiTanahRecord;

String DBHumiLingRecord;
String DBSuhuLIngRecord;
String DBWaktuLIngRecord;

float refHumiTanahMax;
float refHumiTanahMin;
float refSend = 1;
float refhumiTanah, refhumiLing, reftempLing, refstsSiram;
float humiTanah, humiLing, tempLing;
float sendHumiTanah, sendHumiLing, sendTempLing;
int   stsSiram, SiramRef;

//===Config time===
int timezone = 7;
int dst = 0;

char ntp_server1[20] = "ntp.ku.ac.th";
char ntp_server2[20] = "fw.eng.ku.ac.th";
char ntp_server3[20] = "time.uni.net.th";

//milis
int period = 60000 * 60;
unsigned long time_now = 0;

void setup() {
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(50);
  }

  Serial.println();
  Serial.print("connected: ");
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  dht.begin();

  configTime(timezone * 3600, dst, ntp_server1, ntp_server2, ntp_server3);
  Serial.println("Waiting for time");
  while (!time(nullptr)) {
    Serial.print(".");
  }

  pinMode(PUMP_PIN, OUTPUT);
  //  pinMode(SOIL_PIN, INPUT);

  digitalWrite(D4, NON_ACTIVE);

  MACAdd        = WiFi.macAddress();
  InitDBRef();

  refhumiTanah  = Firebase.getFloat(DBHumiTanah);
  refhumiLing   = Firebase.getFloat(DBHumiLing);
  reftempLing   = Firebase.getFloat(DBSuhuLIng);
  refstsSiram   = Firebase.getFloat(DBPump);
}

void loop() {
  getDHT();
  getSoil();
  controlMotor();
  sendFirebase();
  debug();
  delay(1000);
}
