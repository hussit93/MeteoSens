
//#define AVG_SHOW

void avg_get(){

  
  #ifdef AVG_SHOW
  Serial.println(" ");
  Serial.println(" AVG -------");
  Serial.print("31: ");
  Serial.println(t_sht);
  //Serial.print("30: ");
  //Serial.println(t_sht30);
  Serial.print("21: ");
  Serial.println(t_htu);
  //Serial.print("DL: ");
  //Serial.println(t_dallas);
  Serial.print("280: ");
  Serial.println(t_bmp);
  Serial.print("1750: ");
  Serial.println(lux);
  Serial.print("W: ");
  Serial.println(getGust_mps2());
  Serial.print("D: ");
  Serial.println(direction_min);
  Serial.println(" ");

  
  #endif /* MACRO */
  
  float t_sht30_out;  
  int delitel = 0;

  if (t_sht){
    delitel = delitel+2;
  }
  if (t_htu){
    delitel++;
  }

  //if (t_dallas){
  //  delitel++;
  //}

  if (t_bmp){
    delitel++;
  }
  



 
  
  
  avg=((t_sht+t_sht+t_htu+t_bmp+t_sht30_out)/delitel);
  avg_int = avg*10;
  avg_float = avg_int*0.1;
  
  
  #ifdef AVG_SHOW
  Serial.print("delitel: ");
  Serial.println(delitel);
  
  Serial.print("avg: ");
  Serial.println(avg);
  #endif /* MACRO */

  if(avg < horni_t_limit && avg > dolni_t_limit){
      Serial.println("      AVG:");
      send(avg_msg.set(avg,1));
      t_sht=0;
      t_htu=0;
      t_bmp=0;
      Serial.println(" ");
      delay(delay_time);
  }
  
  
}
