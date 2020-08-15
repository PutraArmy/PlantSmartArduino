void getSoil() {
  int value = analogRead(SOIL_PIN);
  if (value > 1023) {
    value = 1023;
  }
  humiTanah = convertToPercent(value);
}

int convertToPercent(int value) {
  int percentValue = 0;
  percentValue = map(value, 1023, 465, 0, 100);
  return percentValue;
}
