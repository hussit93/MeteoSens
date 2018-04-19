
//#define DALLAS_SHOW
//
//void dallas_send(){
//
//  #ifdef DALLAS_SHOW
//  Serial.println(" DALLAS -------");
//  #endif /* MACRO */
// 
//  sensors.requestTemperatures();
//  delay(500);
//  t_dallas = sensors.getTempCByIndex(0);
//  
//  if (t_dallas =! -127.00){
//
//   //send(dallas_msg.set(t_dallas,2));  
//  }
//  
//  
//  #ifdef DALLAS_SHOW
//  
//  Serial.print("Dallas: ");
//  Serial.println(t_dallas);
//  Serial.println(" ");
//
//  #endif /* MACRO */
//
//
//}
