//#define SHT31_SHOW


void sht31_send(){

  
   
  t_sht_raw = sht31.readTemperature();
  
  h_sht_raw = sht31.readHumidity();
 
  Serial.println("      SHT31_inboard:");
  t_sht_raw_2 = sht31_2.readTemperature();
  send(sht2_t_Msg.set(t_sht_raw_2,2));
  
  h_sht_raw_2 = sht31_2.readHumidity();
  send(sht2_h_Msg.set(h_sht_raw_2, 1));
  Serial.println(" ");
  delay(delay_time);

  if(t_sht_raw != 0){

    if(t_sht_raw < horni_t_limit && t_sht_raw > dolni_t_limit){

      t_sht = t_sht_raw;
      Serial.println("      SHT31:");
      send(sht_t_Msg.set(t_sht,2));
      
      delay(delay_time);
    }

  }
  
  


  if(h_sht_raw != 0){

    if(h_sht_raw < 99.9 && h_sht_raw > 4.5){
      h_sht = h_sht_raw;
      send(sht_h_Msg.set(h_sht, 1));
      h_sht = 0;
      delay(delay_time);
      
      }

  
  
}  
  
  
  
  if(t_sht_raw && h_sht_raw){
    dP=(dewPointFast(t_sht_raw, h_sht_raw));
    send(dp_msg.set(dP,1));
    delay(delay_time);
    Serial.println(" ");
  }
  
  
  







  
  
  
  #ifdef SHT31_SHOW
  
  
  Serial.print("Temp SHT31: ");
  Serial.println(t_sht_raw);
  
  Serial.print("Humidity SHT31: ");
  Serial.println(h_sht_raw); 

  Serial.print("Dew Point: ");
  Serial.println(dP);
  
  Serial.println(" ");

   Serial.print("Temp SHT31_2: ");
  Serial.println(t_sht_raw_2);
  
  Serial.print("Humidity SHT31_2: ");
  Serial.println(h_sht_raw_2); 
  #endif /* MACRO */

  

}


double dewPointFast(double celsius, double humidity)
{
 double a = 17.271;
 double b = 237.7;
 double temp = (a * celsius) / (b + celsius) + log(humidity*0.01);
 double Td = (b * temp) / (a - temp);
 return Td;
}
