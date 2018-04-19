//#define VANE_SHOW


void wind_vane_send(){

  
  
  a0_value = analogRead(A15);
  input_voltage = (a0_value * 5.0) / 1024.0;
  smerWind();
  

 // ----------------------------MINUTE --------------------------------

  maxx_min = smer0_cnt_m;
  direction_min=0;

  if (maxx_min < smer45_cnt_m){
    maxx_min = smer45_cnt_m;
    direction_min=45;
  }

  if (maxx_min < smer90_cnt_m){
    maxx_min = smer90_cnt_m;
    direction_min=90;
  }

  if (maxx_min < smer135_cnt_m){
    maxx_min = smer135_cnt_m;
    direction_min=135;
  }

  if (maxx_min < smer180_cnt_m){
    maxx_min = smer180_cnt_m;
    direction_min=180;
  }

  if (maxx_min < smer225_cnt_m){
    maxx_min = smer225_cnt_m;
    direction_min=225;
  }

  if (maxx_min < smer270_cnt_m){
    maxx_min = smer270_cnt_m;
    direction_min=270;
  }

  if (maxx_min < smer315_cnt_m){
    maxx_min = smer315_cnt_m;
    direction_min=315;
  }
// ----------------------------MINUTE --------------------------------


// ----------------------------HOUR --------------------------------
  maxx_hod = smer0_cnt_h;
  direction_hod=0;

  if (maxx_hod < smer45_cnt_h){
    maxx_hod = smer45_cnt_h;
    direction_hod=45;
  }

  if (maxx_hod < smer90_cnt_h){
    maxx_hod = smer90_cnt_h;
    direction_hod=90;
  }

  if (maxx_hod < smer135_cnt_h){
    maxx_hod = smer135_cnt_h;
    direction_hod=135;
  }

  if (maxx_hod < smer180_cnt_h){
    maxx_hod = smer180_cnt_h;
    direction_hod=180;
  }

  if (maxx_hod < smer225_cnt_h){
    maxx_hod = smer225_cnt_h;
    direction_hod=225;
  }

  if (maxx_hod < smer270_cnt_h){
    maxx_hod = smer270_cnt_h;
    direction_hod=270;
  }

  if (maxx_hod < smer315_cnt_h){
    maxx_hod = smer315_cnt_h;
    direction_hod=315;
  }
// ----------------------------HOUR --------------------------------

    if(forward_value_min == 1){
    Serial.println("      W-VANE:");
    send(dir_m_msg.set(direction_min_out,0));
    Serial.println(" "); 
    }


  if(min_flag_vane == 1){
    forward_value_min = 1;

    direction_min_out = direction_min;

    if(forward_value_hod == 1){
      send(dir_h_msg.set(direction_hod_out,0));
    }
    
    
    
    smer0_cnt_m = 0;
    smer45_cnt_m = 0;
    smer90_cnt_m = 0;
    smer135_cnt_m = 0;
    smer180_cnt_m = 0;
    smer225_cnt_m = 0;
    smer270_cnt_m = 0;
    smer315_cnt_m = 0;

    min_flag_vane = 0;
    maxx_min = 0;
    direction_min=0;
    delay(delay_time);
  }
  

  if(hod_flag_vane == 1){
    forward_value_hod = 1;
    direction_hod_out = direction_hod;
    
    smer0_cnt_h = 0;
    smer45_cnt_h = 0;
    smer90_cnt_h = 0;
    smer135_cnt_h = 0;
    smer180_cnt_h = 0;
    smer225_cnt_h = 0;
    smer270_cnt_h = 0;
    smer315_cnt_h = 0;

    hod_flag_vane = 0;
    maxx_hod = smer0_cnt_h;
    direction_hod=0;
    
  }


        
  #ifdef VANE_SHOW
  Serial.println(" ");
 
  Serial.println(" WIND VANE -------");
  Serial.println(" ");
  Serial.print("Wind vane ADC value: ");
  Serial.println(a0_value);
  Serial.print("input_voltage: ");
  Serial.println(input_voltage);
  Serial.println(" ");
  Serial.println(" ");

  Serial.println(" --- COUNTER PER MIN ");
  Serial.print("0: ");
  Serial.println(smer0_cnt_m);
  Serial.print("45: ");
  Serial.println(smer45_cnt_m);
  Serial.print("90: ");
  Serial.println(smer90_cnt_m);
  Serial.print("135: ");
  Serial.println(smer135_cnt_m);
  Serial.print("180: ");
  Serial.println(smer180_cnt_m);
  Serial.print("225: ");
  Serial.println(smer225_cnt_m);
  Serial.print("270: ");
  Serial.println(smer270_cnt_m);
  Serial.print("315: ");
  Serial.println(smer315_cnt_m);
  
  Serial.println(" ");
  Serial.print("direction_min: ");
  Serial.println(direction_min);
  Serial.print("direction_min_out: ");
  Serial.println(direction_min_out);
  Serial.print("maxx_min: ");
  Serial.println(maxx_min);
  Serial.println(" ");
  Serial.println(" ");
  
  
  Serial.println(" --- COUNTER PER HOUR ");
  Serial.print("0: ");
  Serial.println(smer0_cnt_h);
  Serial.print("45: ");
  Serial.println(smer45_cnt_h);
  Serial.print("90: ");
  Serial.println(smer90_cnt_h);
  Serial.print("135: ");
  Serial.println(smer135_cnt_h);
  Serial.print("180: ");
  Serial.println(smer180_cnt_h);
  Serial.print("225: ");
  Serial.println(smer225_cnt_h);
  Serial.print("270: ");
  Serial.println(smer270_cnt_h);
  Serial.print("315: ");
  Serial.println(smer315_cnt_h);
  
  Serial.println(" ");
  Serial.print("direction_hod: ");
  Serial.println(direction_hod);
  Serial.print("direction_hod_out: ");
  Serial.println(direction_hod_out);
  Serial.print("maxx_hod: ");
  Serial.println(maxx_hod);
  Serial.println(" ");
  Serial.println(" ");
  #endif /* MACRO */
  
}







void smerWind(){
  
   int smer;
   
  if(input_voltage < 1.5 && input_voltage > 1.3){
      //Sever
      smer0_cnt_m++;
      smer0_cnt_h++;
   }
   
   if(input_voltage < 3.3 && input_voltage > 2.7){
    //Severo-Vychod
    smer45_cnt_m++;
    smer45_cnt_h++;
   }

  if(input_voltage < 4.7 && input_voltage > 4.5){
      //Vychod
      smer90_cnt_m++;
      smer90_cnt_h++;
   }
   
  if(input_voltage < 4.5 && input_voltage > 4.1){
      //Jiho-Vychod
      smer135_cnt_m++;
      smer135_cnt_h++;
   }

  if(input_voltage < 3.9 && input_voltage > 3.7){
        //Jih
        smer180_cnt_m++;
        smer180_cnt_h++;
   }      
   

  if(input_voltage < 2.6 && input_voltage > 2.0){
    //Jiho-Zapad
    smer225_cnt_m++;
    smer225_cnt_h++;
   }

  if(input_voltage < 0.5 && input_voltage > 0.3){
        //Zapad
        smer270_cnt_m++;
        smer270_cnt_h++;
   }  
  

   if(input_voltage < 1.1 && input_voltage > 0.8){
    //Severo-Zapad
    smer315_cnt_m++;
    smer315_cnt_h++;
   }

     
        
  
}
