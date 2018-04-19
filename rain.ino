//#define RAIN_SHOW

void rain_send(){


  if(pcReceived == true){
    if(value != 0){
      rain_imp_cnt = value;
      pcReceived = false;
     
    }
  }

      #ifdef RAIN_SHOW
  Serial.print("rain_imp_day: ");
  Serial.println(rain_imp_day);

  Serial.print("rain_imp_day_out: ");
  Serial.println(rain_imp_day_out);

  Serial.print("rain_imp_per_d: ");
  Serial.println(rain_imp_per_d);  
     #endif /* MACRO */
    
   if(day_flag_rain == 1){
      day_flag_rain = 0;
      rain_imp_day_out = rain_imp_day;
      
      rain_imp_per_d = 0;
   }


  if(rain_imp_cnt == 0){
    Serial.println(" ");
    Serial.println("rain_imp_cnt = 0, so need request:");
    Serial.println(" ");
    request(RAIN_CHILD, V_VAR5);
  }else{
    Serial.println("      RAIN:");
    send(rain_imp_cnt_msg.set(rain_imp_cnt,0));
    delay(delay_time);
    
    send(rain_real_cnt_msg.set(rain_imp_cnt*RAIN_FACTOR,1));
    delay(delay_time);

    send(rain_per_d_msg.set(rain_imp_day_out,2));
    delay(delay_time);
  }
  


   
  //
  

  
  
 
  
   if(hod_flag_rain == 1){
      
      
      send(rain_per_h_msg.set(rain_imp_hod,2));
      hod_flag_rain = 0;
      rain_imp_per_h = 0;
      
      delay(delay_time);
      
      
  }
  
  

    if(min_flag_rain == 1){
      
      
      send(rain_per_min_msg.set(rain_imp_min,2));
      min_flag_rain = 0;
      rain_imp_per_m = 0;
      Serial.println(" ");
      delay(delay_time);
      
      
  }
  







 
  
  


}


 void rain_click(void) {  //rain
 
    rain_imp_per_m++;
    rain_imp_per_h++;
    rain_imp_per_d++;
    //rain_count++;
    rain_imp_cnt++;  
 
 }





//double getUnitRain(){
// 
//  unsigned long reading=rain_count;
//  rain_count=0;
//  double unit_rain=reading*RAIN_FACTOR;
// 
//  return unit_rain;
//}

