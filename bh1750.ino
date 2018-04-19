//#define BH1750_SHOW

void bh1750_send(){
  
  Serial.println("      BH1750:");
  

  lux = lightSensor.readLightLevel();// Get Lux value
  lux2 = lux;
  send(luxMsg.set(lux));
  delay(delay_time);
  #ifdef BH1750_SHOW
  
  
  Serial.print("LUX:");
  Serial.println(lux);
  Serial.println(" ");
  Serial.println(" ");
  //  Serial.print("d");
  //  Serial.println(lux);
  #endif /* MACRO */
  Serial.println(" ");


}


