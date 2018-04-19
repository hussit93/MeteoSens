

void timer_min(){
  currentMillis = millis();
  if (currentMillis - previousMillis_min >= interval_min) {
      previousMillis_min = currentMillis;
      
      
      cas_behu_m++;

      rain_imp_min = rain_imp_per_m*RAIN_FACTOR;
      min_flag_rain = 1;
      
      min_flag_vane = 1;    
      

      
      wind_min = getUnitWind();
      

   
//      
    Serial.println(" ");
    Serial.println("--------------- min_flag --------------- ");
    Serial.println(" ");
  }
  
}


void timer_hod(){
  
  currentMillis = millis();
  if (currentMillis - previousMillis_hod >= interval_hod) {
      previousMillis_hod = currentMillis;
      
      rain_imp_hod = rain_imp_per_h*RAIN_FACTOR;
      hod_flag_rain = 1;
      hod_flag_vane = 1;
     
//      Serial.println(" ");
//      Serial.println("--------------- hod_flag --------------- ");
//      Serial.println(" ");
  }
}



void timer_day(){
  


      
      day_value_now = cas_behu_d;

      if(day_value_now != day_value_last){

          
          day_flag_rain = 1;

          
          rain_imp_day = rain_imp_per_d*RAIN_FACTOR;
          
          test_cnt++;
          day_value_last = day_value_now;
      }
      
      
        
     day_value_last = day_value_now;
      
      
//    Serial.println(" ");
//    Serial.println("Timer-Day:");
//    
//    Serial.print("test_cnt: ");
//    Serial.println(test_cnt);
//
//      
//    Serial.print("day_value_now: ");
//    Serial.println(day_value_now);     
//  
//     
//
//      
//    Serial.print("day_flag_rain: ");
//    Serial.println(day_flag_rain);     
//    Serial.println(" ");

     
  }

  
