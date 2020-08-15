void sendFirebase() {

  bool stsSend = false;
  
  if ((humiTanah >= refhumiTanah + 2) || (humiTanah <= refhumiTanah - 2)) {
    Firebase.setFloat (DBHumiTanah, humiTanah);
    refhumiTanah = humiTanah;
    stsSend = true;
  }
  if ((humiLing >= refhumiLing + refSend) || (humiLing <= refhumiLing - refSend)) {
    Firebase.setFloat (DBHumiLing,  humiLing);
    refhumiLing = humiLing;
    stsSend = true;
  }
  if ((tempLing >= reftempLing + refSend) || (tempLing <= reftempLing - refSend)) {
    Firebase.setFloat (DBSuhuLIng,  tempLing);
    reftempLing = tempLing;
    stsSend = true;
  }
  
  if (stsSiram != refstsSiram) {
    Firebase.setInt   (DBPump, stsSiram);
    refstsSiram = stsSiram;
  }
  if (stsSend == true) {
    Firebase.setString(DBUpdateTgl, getDate()); // Kirim data Tanggal
    Firebase.setString(DBUpdateWaktu, getTime());
    
    recordSend();
    
    stsSend = false;
    
  }

}
