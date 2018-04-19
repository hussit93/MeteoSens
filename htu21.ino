
//#define HTU21_SHOW

void htu21_send(){

  
   
  
 
  t_htu_raw = htu.readTemperature();
  
  h_htu_raw = htu.readHumidity();



  if(t_htu_raw != 0){

    if(t_htu_raw < horni_t_limit && t_htu_raw > dolni_t_limit){
      t_htu = t_htu_raw+0.15;
      Serial.println("      HTU21: ");
      send(htu_t_Msg.set(t_htu,2));
      
      delay(delay_time);
      }

  }


if(t_htu){
  if(h_htu_raw != 0){

    if(h_htu_raw < 99.9 && h_htu_raw > 4.5){
      h_htu = h_htu_raw;
      send(htu_h_Msg.set(h_htu,1));
      h_htu = 0;
      delay(delay_time);
      Serial.println(" ");
      }

  }
}
  
  
  
  
  #ifdef HTU21_SHOW
  
  
  Serial.print("read: ");
  Serial.println(htu.readTemperature());
  
  Serial.print("Temp HTU21: ");
  Serial.println(t_htu);
  
  Serial.print("Humidity HTU21: ");
  Serial.println(h_htu);
  Serial.println(" ");
  #endif /* MACRO */
  
}
