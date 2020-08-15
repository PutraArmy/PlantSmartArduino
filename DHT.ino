void getDHT() {
  humiLing  = dht.readHumidity();
  tempLing  = dht.readTemperature();
}
