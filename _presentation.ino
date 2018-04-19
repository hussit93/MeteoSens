void presentation()  {


  sendSketchInfo("meteo_sens_mega", "1.3");
  
  // SHT31
  present(SHT31_CHILD, S_TEMP);
  present(SHT31_INBOARD, S_TEMP);
  
  // HTU21
  present(HTU21_CHILD, S_TEMP);

  // BMP280
  present(BMP280_CHILD, S_BARO);
  
  // BH1750
  present(BH1750_CHILD, S_LIGHT_LEVEL);

  // AVG
  present(CHILD_ID_AVG, S_TEMP);

  //Wind speed, Wind Vane
  present(WIND_CHILD, S_WIND);

  //Rain
  present(RAIN_CHILD, S_RAIN);

  // Dallas
  //present(DALLAS_CHILD, S_TEMP);  

  //Fan Control
  present(FAN_CHILD, S_BINARY);
  
}
