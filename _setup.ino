


void setup()  
{ 
  
  #ifdef TS_ENABLE
  Ethernet.begin(mac);
  ThingSpeak.begin(client);
  #endif

  
  pinMode(25, OUTPUT); //FAN Enable
  digitalWrite(25, LOW);


  pinMode(36, OUTPUT);  //FAN incase
  digitalWrite(36, LOW);


  
  pinMode(38, OUTPUT);  //STBY LED
  digitalWrite(38, LOW);

  pinMode(39, OUTPUT); // FAN LED
  digitalWrite(39, LOW);

  pinMode(40, OUTPUT); // Boot LED
  digitalWrite(40, HIGH);

  pinMode(41, OUTPUT); //ACT LED
  digitalWrite(41, LOW);

  attachInterrupt(digitalPinToInterrupt(18), anem_click, FALLING);
  attachInterrupt(digitalPinToInterrupt(19), rain_click, FALLING);

  inputString.reserve(200);
  
  //uv.begin(VEML6070_1_T);
  
  sht31.begin(0x44);
  sht31_2.begin(0x45);
  bmp.begin(BMP280_ADRESA);
  htu.begin();
  lightSensor.begin();
  //sensors.begin();
  Serial.println(" ");
  Serial.println(" --- meteo_sens 1.1 ---");
  #ifdef TS_ENABLE
  Serial.println(" --- thingspeak version ---");
  #endif
  Serial.println(" --- build date: 17.4.2018 ---");
  Serial.println(" --- by R.Habartik ---");
  Serial.println(" ");


  
}


void start_flag(){

  #ifdef VALUE_DEBUG  
  Serial.println(" ");
  Serial.println(" ------- START -------- ");
  #endif
}


void stop_flag(){
  #ifdef VALUE_DEBUG  
  Serial.println(" ------- STOP --------- "); 
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  #endif

}


void uptime_send(){


  //if(cas_behu_s > 59){
  //      cas_behu_s = 0;
  //      cas_behu_m++;
        if(cas_behu_m > 59){
          cas_behu_m = 0;
          cas_behu_h++;
          if(cas_behu_h > 23){
            cas_behu_h = 0;
            cas_behu_d++;
          }

        }

      //}
      
  Serial.print("UPTIME: ");

  
  Serial.print(cas_behu_d);
  Serial.print("d ");
  
  Serial.print(cas_behu_h);
  Serial.print("h ");
  
  Serial.print(cas_behu_m);
  Serial.println("m ");

  
  
  send(min_msg.set(cas_behu_m,0));
  delay(delay_time);
  
  send(hod_msg.set(cas_behu_h,0));
  delay(delay_time);
  
  send(days_msg.set(cas_behu_d,0));
  delay(delay_time);

  Serial.println(" ");
  
}




