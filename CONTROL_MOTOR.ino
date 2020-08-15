void controlMotor() {
  SiramRef        = Firebase.getInt(DBPump);
  refHumiTanahMin = Firebase.getFloat(DBHumiRefMin);
  refHumiTanahMax = Firebase.getFloat(DBHumiRefMax);

  controlMotorManual();
  contorlMotorOtomatis();

}

void controlMotorManual() {
  if (SiramRef == 1) {
    digitalWrite(PUMP_PIN, ACTIVE);
    stsSiram = 1;
  } else {
    digitalWrite(PUMP_PIN, NON_ACTIVE);
    stsSiram = 0;
  }
}

void contorlMotorOtomatis() {
  if (humiTanah <= refHumiTanahMin) {
    digitalWrite(PUMP_PIN, ACTIVE);
    stsSiram = 1;
  }
  if (humiTanah >= refHumiTanahMax) {
    digitalWrite(PUMP_PIN, NON_ACTIVE);
    stsSiram = 0;
  }

}
