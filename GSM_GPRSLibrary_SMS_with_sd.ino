#include "SIM900.h"
#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>

#include "sms.h"


File myFile;


 SMSGSM sms;


void setup() 
{
  
  boolean started=false;
  //Serial connection.
  Serial.begin(9600);
  Serial.println("GSM Shield testing.");
  //Start configuration of shield with baudrate.
  //For http uses is raccomanded to use 4800 or slower.
  if (gsm.begin(2400)){
    Serial.println("\nstatus=READY");
    started=true;  
  }
  else Serial.println("\nstatus=IDLE");
  
  
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
       myFile.read();
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  if(started){
    //Enable this two lines if you want to send an SMS.
    if (sms.SendSMS("9900188301",myFile))
      Serial.println("\nSMS sent OK");
  }

};

//void loop() 
//{
//  boolean started=true;
//  String received; 
//
//char n[15];
//  char smsbuffer[20];
//  if(started){
//    //Read if there are messages on SIM card and print them.
//    
//    if(gsm.readSMS(smsbuffer, 160 , n, 20))
//    {
//      Serial.println(n);
//      Serial.println(smsbuffer);
//      received=String(smsbuffer);
//
//      
//      if(received!="SEND"){
//        Serial.println("send antha banthu");
//        sendi(); 
//      }  
//      
//      else
//      {
//        Serial.println("send bandilla");
//        
//        }
//        
//      }
//      delay(1000);
//  }
//};
void loop()
{
//  boolean started=false;
//  char msgtemp[100];
//  
//  
//  Serial.println("sendi ge banthu");
////  myFile = SD.open("test.txt");
//// 
//// //Serial.write(msgtemp,1,sizeof(msgtemp),myFile)
////  if (myFile) {
////    Serial.println("test.txt:");
////    Serial.println("if loop ge going");
////
////    // read from the file until there's nothing else in it:
////    while (myFile.available()) {
////     msgtemp[100]=myFile.read();
////     Serial.println(msgtemp);
////       //msgtemp[100]=myFile.read();
////    }
////    // close the file:
////    myFile.close();
////  } else {
////    // if the file didn't open, print an error:
////    Serial.println("error opening test.txt");
////  }
//
//
// 
////  if(started){
////    //Enable this two lines if you want to send an SMS.
////   // sprintf(msgtemp,"%c",msg)
////    if (sms.SendSMS("9900188301", msgtemp))
////      Serial.println("\nSMS sent OK");
////      delay(1000);
////  }


};


