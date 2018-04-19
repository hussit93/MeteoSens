
void ts_send(){


        #ifdef TS_ENABLE
      Serial.print("TS_start");

      
      ts_field1 = String(avg_float);
      ThingSpeak.setField(1,ts_field1);

      ts_field2 = String(h_sht_raw);
      ThingSpeak.setField(2,ts_field2);

      
      ts_field4 = String(actual_gust_kph);
      ThingSpeak.setField(4,ts_field4);


      ts_field5 = String(t_sht_raw_2);
      ThingSpeak.setField(5,ts_field5);

      ts_field6 = String(lux);
      ThingSpeak.setField(6,ts_field6);


      
      float ts_rain = rain_imp_cnt*RAIN_FACTOR;
      ts_field7 = String(ts_rain);
      ThingSpeak.setField(7,ts_field7);


      
      ThingSpeak.setField(8,cas_behu_m);
      

  
      ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
      Serial.println("TS_stop");
      #endif

      
}

