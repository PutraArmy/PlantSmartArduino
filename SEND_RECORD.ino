void recordSend() {
    DBHumiTanahRecord  = MACAdd + "/record/" + getDateGrafik() + "/" + getHour() + "/humidityTanah";

    DBHumiLingRecord   = MACAdd + "/record/" + getDateGrafik() + "/" + getHour() + "/humidity";
    DBSuhuLIngRecord   = MACAdd + "/record/" + getDateGrafik() + "/" + getHour() + "/suhu";
    DBWaktuLIngRecord  = MACAdd + "/record/" + getDateGrafik() + "/" + getHour() + "/waktu";

    Firebase.setFloat (DBHumiTanahRecord, humiTanah);
    Firebase.setFloat (DBHumiLingRecord,  humiLing);
    Firebase.setFloat (DBSuhuLIngRecord,  tempLing);
    Firebase.setString (DBWaktuLIngRecord, getHour());
}
