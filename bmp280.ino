//#define BMP280_SHOW


void bmp280_send(){
  

  
 
  
  float t_bmp_raw = bmp.readTemperature();
  
  if(t_bmp_raw != 0){

    if(t_bmp_raw < horni_t_limit && t_bmp_raw > dolni_t_limit){
        t_bmp = t_bmp_raw-1.73;
        Serial.println("      BMP280:");
        send(bmp_tMsg.set(t_bmp,2));
        
        delay(delay_time);
        }
    
  }
  
  
  
  tlak_raw = (bmp.readPressure()/100.00)+45;

  if(tlak_raw != 0){
    if(tlak_raw < 1050 && tlak_raw > 970){
        tlak = tlak_raw;
    
        send(bmp_pMsg.set(tlak,1));
        #ifdef TS_ENABLE
        
        ts_field3 = String(tlak);
        ThingSpeak.setField(3,ts_field3);
        #endif
        tlak = 0;
        Serial.println(" ");
        delay(delay_time);
        }
    
    
  }
  
  
  
  
  
  #ifdef BMP280_SHOW

  
  
  Serial.print("t_bmp_raw: ");
  Serial.println(t_bmp_raw);
  
  Serial.print("tlak_raw:");
  Serial.println(tlak_raw);
  Serial.println(" ");
  //  Serial.print("c");
  //  Serial.println(tlak);
  
  #endif /* MACRO */



}
