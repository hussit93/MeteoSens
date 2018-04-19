//#define WIND_SHOW

void wind_speed_send(){

    Serial.println("      W:");

   // Wind Speed
  //float actual_gust = getGust_mps();
  float actual_gust2 = getGust_mps2();
  
  
  
  actual_gust_kph = actual_gust2*3.6;

  Serial.print("W_actual:");
  Serial.println(actual_gust_kph);
  send(wind_speed_msg.set(actual_gust_kph,2)); 
  
  Serial.println(" ");
  delay(delay_time);
  
  #ifdef WIND_SHOW

  Serial.println(" WIND SPEED -------");
  //  Serial.print("getUnitWind: ");
  //  Serial.println(getUnitWind());
  
  
 
  
  Serial.print("this-time: ");
  Serial.println(thisTime_w);

  Serial.print("anem_min: ");
  Serial.println(anem_min2);
  
  Serial.print("wind_cnt_imp: ");
  Serial.println(a);

  Serial.print("anem_count: ");
  Serial.println(anem_count);
 
  //Serial.print("getGust [m/s]: ");
  //Serial.println(actual_gust);

  Serial.print("getGust2 [m/s]: ");
  Serial.println(actual_gust2);

  Serial.print("getGust [km/h]: ");
  Serial.println(actual_gust_kph);
  Serial.println(" ");
  
  Serial.print("getWind [-]: ");
  Serial.println(wind_min);
  #endif /* MACRO */
  

// if ( thisTime_w > 100){
//    Serial.print("this-time: ");
//    Serial.println(thisTime_w);
//    unsigned long time_2 = thisTime_w*2;
//    Serial.print("this-time*2: ");
//    Serial.println(time_2);
//
//    Serial.print("this-time*2 in sec: ");
//    double time_s = time_2*0.000001;
//    Serial.println(time_s);
//
//    Serial.print("Speed [m/s]: ");
//    double speed = 0.43/time_s;
//    Serial.println(speed);
//    Serial.println(" ");
//    Serial.print("getGust [m/s]: ");
//    Serial.println(actual_gust);
//  }
  
  
}


void anem_click(void) { //anem
 //digitalWrite(A2, HIGH);
 thisTime_w=micros()-anem_last;
 anem_last=micros();
 if(thisTime_w > 500){
  anem_min=thisTime_w;
  anem_min2=thisTime_w;
 }
 


 
 a++;
 anem_count++;
 
 //digitalWrite(A2, LOW);
 }


// double getGust_mps(){
// 
//  unsigned long reading=anem_min;
//  anem_min=0xffffffff;
//  //double time=reading/1000000.0;
// 
//  return (1/(reading/1000000.0))*WIND_FACTOR;
//}

double getGust_mps2(){
 
  unsigned long reading=anem_min;
  anem_min=0xffffffff;
  
  unsigned long time_2 = reading*2;
  double time_s = time_2*0.000001;
  double speed = 0.44/time_s;
  
  return speed;
}



 double getUnitWind(){
  
  unsigned long reading2=anem_count;
  anem_count=0;
  return (0.22*reading2)/(TEST_PAUSE);
}


 

