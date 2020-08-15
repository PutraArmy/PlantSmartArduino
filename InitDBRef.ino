void InitDBRef() {
  DBHumiTanah  = MACAdd + "/monitoring/tanah/humidity";

  DBHumiLing   = MACAdd + "/monitoring/lingkungan/humidity";
  DBSuhuLIng   = MACAdd + "/monitoring/lingkungan/suhu";

  DBPump       = MACAdd + "/controlling/pump";

  DBUpdateTgl  = MACAdd + "/updateTgl";
  DBUpdateWaktu= MACAdd + "/updateWaktu";

  DBHumiRefMin = MACAdd + "/setting/humiMin";
  DBHumiRefMax = MACAdd + "/setting/humiMax";
}
