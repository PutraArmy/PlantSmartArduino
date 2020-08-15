String getDate() {
  String bulan;
  String tanggal;
  
  time_t now = time(nullptr);
  struct tm* newtime = localtime(&now);

  String tmpNow = "";

  if (newtime->tm_mday < 10) {
    tanggal = "0" + String(newtime->tm_mday);
  } else {
    tanggal = String(newtime->tm_mday);
  }
  tmpNow += tanggal;

  tmpNow += "-";

  if (newtime->tm_mon + 1 < 10) {
    bulan = "0" + String(newtime->tm_mon + 1);
  } else {
    bulan = String(newtime->tm_mon + 1);
  }
  tmpNow += bulan;

  tmpNow += "-";

  tmpNow += String(newtime->tm_year + 1900);
  return tmpNow;
}

String getTime() {
  String jam;
  String menit;
  
  time_t now = time(nullptr);
  struct tm* newtime = localtime(&now);

  String tmpNow = "";

  if (newtime->tm_hour < 10) {
    jam = "0" + String(newtime->tm_hour);
  } else {
    jam = String(newtime->tm_hour);
  }
  tmpNow += jam;

  tmpNow += ":";

  if (newtime->tm_min < 10) {
    menit = "0" + String(newtime->tm_min);
  } else {
    menit = String(newtime->tm_min);
  }
  tmpNow += menit;

  return tmpNow;
}

String getHour() {
  String jam;
  String menit;
  
  time_t now = time(nullptr);
  struct tm* newtime = localtime(&now);

  String tmpNow = "";

  if (newtime->tm_hour < 10) {
    jam = "0" + String(newtime->tm_hour);
  } else {
    jam = String(newtime->tm_hour);
  }
  tmpNow += jam;
  tmpNow += ":00";

  return tmpNow;
}

String getDateNow() {
  time_t now = time(nullptr);
  struct tm* newtime = localtime(&now);

  String tmpNow = "";
  tmpNow += String(newtime->tm_mday);
  tmpNow += "-";
  tmpNow += String(newtime->tm_mon + 1);
  tmpNow += "-";
  tmpNow += String(newtime->tm_year + 1900);
  return tmpNow;
}

String getDateGrafik() {
  String bulan;
  String tanggal;

  time_t now = time(nullptr);
  struct tm* newtime = localtime(&now);

  String tmpNow = "";
  tmpNow += String(newtime->tm_year + 1900);
  tmpNow += "-";

  if (newtime->tm_mon + 1 < 10) {
    bulan = "0" + String(newtime->tm_mon + 1);
  } else {
    bulan = String(newtime->tm_mon + 1);
  }
  tmpNow += bulan;

  tmpNow += "-";

  if (newtime->tm_mday < 10) {
    tanggal = "0" + String(newtime->tm_mday);
  } else {
    tanggal = String(newtime->tm_mday);
  }
  tmpNow += tanggal;

  return tmpNow;
}
