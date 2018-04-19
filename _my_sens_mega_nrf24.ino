
#define NODE_ID 6
#define MY_DEBUG 
#define VALUE_DEBUG

//#define MY_RS485
//#define MY_RS485_DE_PIN 6
//#define MY_RS485_BAUD_RATE 9600
//#define MY_RS485_HWSERIAL Serial1
//#define MY_GATEWAY_SERIAL




//#define MY_RADIO_NRF24
//#define MY_RF24_PA_LEVEL RF24_PA_LOW
//#define MY_RF24_CE_PIN 49
//#define MY_RF24_CS_PIN 53



// -------------------- ETH ------------------------


#define MY_GATEWAY_MQTT_CLIENT
#define MY_MQTT_PUBLISH_TOPIC_PREFIX "mygateway1-out"
#define MY_MQTT_SUBSCRIBE_TOPIC_PREFIX "mygateway1-in"
#define MY_MQTT_CLIENT_ID "mysensors-1"
#ifndef MY_RF24_CE_PIN
#define MY_RF24_CE_PIN 5
#endif
#ifndef MY_RF24_CS_PIN
#define MY_RF24_CS_PIN 6
#endif
#define MY_IP_ADDRESS 192,168,3,43
#define MY_IP_GATEWAY_ADDRESS 192,168,3,1
#define MY_IP_SUBNET_ADDRESS 255,255,255,0
#define MY_CONTROLLER_IP_ADDRESS 192, 168, 3, 195
#define MY_PORT 1883
#include <Ethernet.h>



// -------------------- ETH  end------------------------


// -------------------- THINGSPEAK ------------------------


#define TS_ENABLE
#include "ThingSpeak.h"
byte mac[] = { 0xDE, 0xBB, 0xBE, 0xEF, 0xFE, 0xED};
EthernetClient client;
unsigned long myChannelNumber = 403763;
const char * myWriteAPIKey = "J9YTJYUC2O3VCYUN";


// -------------------- THINGSPEAK end ------------------------

// Includes
//#include <OneWire.h>
//#include <DallasTemperature.h>
#include <Arduino.h>
#include <SPI.h>
#include <MySensors.h>  
#include <BH1750.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include "Adafruit_SHT31.h"
#include <Wire.h>
#include "Adafruit_HTU21DF.h"
//#include "Adafruit_VEML6070.h"



// SHT31
#define SHT31_CHILD 1
#define SHT31_INBOARD 29
Adafruit_SHT31 sht31 = Adafruit_SHT31();
Adafruit_SHT31 sht31_2 = Adafruit_SHT31();
MyMessage sht_t_Msg(SHT31_CHILD, V_TEMP);
MyMessage sht_h_Msg(SHT31_CHILD, V_HUM);
MyMessage sht2_t_Msg(SHT31_INBOARD, V_TEMP);
MyMessage sht2_h_Msg(SHT31_INBOARD, V_HUM);
MyMessage dp_msg(SHT31_CHILD, V_LEVEL);
float t_sht;
float h_sht;
float t_sht_raw;
float h_sht_raw;
float dP;
float t_sht_raw_2;
float h_sht_raw_2;




// HTU21
#define HTU21_CHILD 2
Adafruit_HTU21DF htu = Adafruit_HTU21DF();
MyMessage htu_t_Msg(HTU21_CHILD, V_TEMP);
MyMessage htu_h_Msg(HTU21_CHILD, V_HUM);
float t_htu;
float h_htu;
float t_htu_raw;
float h_htu_raw;





// BMP280
#define BMP280_ADRESA (0x76)
#define BMP280_CHILD 3
Adafruit_BMP280 bmp;
MyMessage bmp_pMsg(BMP280_CHILD, V_PRESSURE); 
MyMessage bmp_tMsg(BMP280_CHILD, V_TEMP); 
const int korekce = 32;
float t_bmp;
float tlak;
float tlak_raw;





// BH1750
#define BH1750_CHILD 11
BH1750 lightSensor;
MyMessage luxMsg(BH1750_CHILD, V_LEVEL); 
unsigned int lux;
int lux2;




//// Dallas
//#define DALLAS_CHILD 6
//#define ONE_WIRE_BUS 3
//OneWire oneWire(ONE_WIRE_BUS);
//DallasTemperature sensors(&oneWire);
//MyMessage dallas_msg(DALLAS_CHILD, V_TEMP);
//float t_dallas;




// AVG
#define CHILD_ID_AVG 4
MyMessage avg_msg(CHILD_ID_AVG, V_TEMP);
float const horni_t_limit = 40.5; //rekord v CR 40.4
float const dolni_t_limit = -39.99; //rekord v CR - 42.2
float avg;
int avg_int;
float avg_float;


// Wind speed
#define WIND_FACTOR 0.2222 // metr za sekundu
#define TEST_PAUSE 60
#define WIND_CHILD 12
MyMessage wind_speed_msg(WIND_CHILD, V_WIND);
volatile unsigned long anem_count=0;
volatile unsigned long anem_last=0;
volatile unsigned long anem_min=0xffffffff;
volatile unsigned long anem_min2;
double wind_min;
long thisTime_w;
unsigned int a;
float actual_gust_kph;



// Wind vane
float input_voltage;
MyMessage dir_m_msg(WIND_CHILD, V_DIRECTION);
MyMessage dir_h_msg(WIND_CHILD, V_LEVEL);
int a0_value = 0;
int min_flag_vane = 0;
int hod_flag_vane = 0;

//per one minute
int smer0_cnt_m = 0;
int smer45_cnt_m = 0;
int smer90_cnt_m = 0;
int smer135_cnt_m = 0;
int smer180_cnt_m = 0;
int smer225_cnt_m = 0;
int smer270_cnt_m = 0;
int smer315_cnt_m = 0;
int maxx_min;
int direction_min;
int direction_min_out;


//per 1 hour
int smer0_cnt_h = 0;
int smer45_cnt_h = 0;
int smer90_cnt_h = 0;
int smer135_cnt_h = 0;
int smer180_cnt_h = 0;
int smer225_cnt_h = 0;
int smer270_cnt_h = 0;
int smer315_cnt_h = 0;

int maxx_hod;
int direction_hod;

int direction_hod_out;

int forward_value_min = 0;
int forward_value_hod = 0;






// Rain
#define RAIN_FACTOR 0.2794
#define RAIN_CHILD 13
MyMessage rain_per_min_msg(RAIN_CHILD, V_RAIN);
MyMessage rain_per_h_msg(RAIN_CHILD, V_RAINRATE);

MyMessage rain_per_d_msg(RAIN_CHILD, V_VAR4);

MyMessage rain_imp_cnt_msg(RAIN_CHILD, V_VAR5);
MyMessage rain_real_cnt_msg(RAIN_CHILD, V_VOLUME);

int hod_flag_rain;
int day_flag_rain;
int min_flag_rain = 0;

long rain_imp_per_h;
long rain_imp_per_d;
long rain_imp_per_m;

float rain_imp_cnt;

boolean pcReceived;
long value;

float rain_imp_day;
float rain_imp_day_out;

float rain_imp_hod;
float rain_imp_min;

int rain_simulation = 0;





// Uptime
MyMessage days_msg(0, V_LEVEL);
MyMessage hod_msg(0, V_PH);
MyMessage min_msg(0, V_ORP);
uint8_t         cas_behu_s = 0;
uint8_t         cas_behu_m = 0;
uint8_t         cas_behu_h = 0;
uint8_t         cas_behu_d = 0;





//Timers
unsigned long previousMillis_sec;
long interval_sec = 300; 

unsigned long previousMillis_hod;
const long interval_hod = 3600000;    //1h
//const long interval_hod = 600000;       //10min

unsigned long previousMillis_min;
const long interval_min = 60000; 
unsigned long currentMillis;




// Custom variables
//MyMessage var1_msg(20, V_VAR1);
//MyMessage var2_msg(20, V_LEVEL);
//MyMessage var4_msg(20, V_VAR4);
//MyMessage var5_msg(20, V_VAR5);



// Other variables
String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int fan_state_cover = LOW;
int fan_state_case = LOW;    

#define FAN_CHILD 19
MyMessage fan_msg(FAN_CHILD, V_LEVEL);
MyMessage fan2_msg(FAN_CHILD, V_PH);


int boot_led_state = LOW;

int id = -12;
int id0, id1,id2,id3,id4,id5,id6,id7,id8;

int request_need = 1;

#define delay_time 50


int day_value_now = 0;
int day_value_last = 0;
int test_cnt = 0;


String ts_field1 = "";
String ts_field2 = "";
String ts_field3 = "";
String ts_field4 = "";
String ts_field5 = "";
String ts_field6 = "";
String ts_field7 = "";
String ts_field8 = "";




void loop()      
{  
  timer_min();
  timer_hod();



  
  currentMillis = millis();
  if (currentMillis - previousMillis_sec >= interval_sec) {
      previousMillis_sec = currentMillis;
      id++;
      Serial.println(" ");
      Serial.println(" ");
      Serial.print("id: ");
      Serial.print(id);
      Serial.println("  ------------------------------------------------------------------");

      if(id < -1){
        boot_led_state = !boot_led_state;    
        digitalWrite(40, boot_led_state);
      }


      if(id > 0){
          digitalWrite(41, HIGH);
          digitalWrite(38, LOW); //Stby LED
          
          wind_speed_send();
          wind_vane_send();
          uart_check(); 
          timer_day();
          //fan_control();
          //rain_send();
          
          
      }

      
      if(id == -9){
          if(request_need == 1){
          if(rain_imp_cnt == 0){
          Serial.print("request:");
          request(RAIN_CHILD, V_VAR5);
          }
      request_need = 0;
        }
      }



      if(id == -7){
            sht31_send();
          }
    
      if(id == -4){
            htu21_send();
          }
    
      if(id == -3){
            bmp280_send();
          }
    
       if(id == -2){
            bh1750_send();
            

            
          }
       if(id == -1){
            avg_get();
            
            digitalWrite(40, LOW); // Boot LED
            digitalWrite(38, HIGH); //Stby LED
            interval_sec = 3000;
          }
    


      
      if(id == 1){
          fan_control();
          
          if (rain_simulation == 1){
              rain_click();
          }
      }

    
   
      if(id == 2){
        sht31_send();
      }
      
      if(id == 4){
        htu21_send();
      }
     
      if(id == 5){
        bmp280_send();
        
      }
      if(id == 6){
         avg_get();
      }
      
      if(id == 7){
        bh1750_send();
      }        

      if(id == 8){
         uptime_send();
      }
      
    
      if(id == 9){
      rain_send();
       }
       
      if(id == 10){
      ts_send();
      id = 0;
       } 
     
      
      

   digitalWrite(41, LOW);
   digitalWrite(38, HIGH);    
 } 



}











