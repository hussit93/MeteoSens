


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:

  
    inputString += inChar;

 
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}



void uart_check(){
  if (stringComplete) {
    Serial.println(inputString);
    
    //rain_simulation = !rain_simulation;
    //fan_state_cover = !fan_state_cover;    
    //digitalWrite(25, fan_state_cover);
    //digitalWrite(39, fan_state_cover);
    
    //cas_behu_d++;
    //hod_flag_vane = 1;
    

    inputString = "";
    stringComplete = false;
  }
 
}


void receive(const MyMessage &message)
{
  if (message.type==V_VAR5) {
    value = message.getLong();
    Serial.print("Received value from gw:");
    Serial.println(value);
    pcReceived = true;
    rain_send();
  }
}


