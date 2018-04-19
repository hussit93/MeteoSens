#define FAN_SHOW

void fan_control(){

  if(avg > 24 && lux > 10000){
    fan_state_cover = 1;
  }else{
    fan_state_cover = 0;
  }

    


    if(t_sht_raw_2 > 40){
    fan_state_case = 1;
    }else{
    fan_state_case = 0;
    }

    digitalWrite(25, fan_state_cover);
    digitalWrite(39, fan_state_cover);

    digitalWrite(36, fan_state_case);


    
    Serial.println(" ");
    Serial.println("      FAN_CONTROL:");  
    send(fan_msg.set(fan_state_cover,0));
    send(fan2_msg.set(fan_state_case,0));

  #ifdef FAN_SHOW
    

    Serial.print("fan_state_cover: ");
    Serial.println(fan_state_cover);

    Serial.print("fan_state_case: ");
    Serial.println(fan_state_case);

    Serial.print("inboard_temp: ");
    Serial.println(t_sht_raw_2);

    Serial.print("AVG: ");
    Serial.println(avg);

    Serial.print("LUX: ");
    Serial.println(lux);

#endif
    
    Serial.println(" ");
    
}

