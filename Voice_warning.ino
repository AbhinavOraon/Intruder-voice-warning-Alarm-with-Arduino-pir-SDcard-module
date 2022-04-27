/*
 **********************************0MeGa EleCtR0nIcs***********
//@Author= Abhinav Etwa oraon
27-April-2022_19:55
 
  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10 
*/

#include "SD.h" // need to include the SD library
#define SD_ChipSelectPin 10 //connect cs pin to digital pin 10
#include "TMRpcm.h" //  also need to include this library...
#include "SPI.h"
const int pirPin = 2; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc
int pirStatus;//used to store data of pipSensor
TMRpcm tmrpcm; // create an object for use in this sketch

void setup()
{
pinMode(pirPin, INPUT);//initialaizing pirpin as input
tmrpcm.speakerPin=9; //Complimentary Output or Dual Speakers:
Serial.begin(9600); // Open serial communications and wait for port to open:
if(!SD.begin(SD_ChipSelectPin))// see if the card is present and can be initialized:
{
  Serial.println("SD fail");//
  return;
}
tmrpcm.setVolume(2);
}

void loop() {
pirStatus = analogRead(ldrPin);
if (pirStatus==1) {//if pir sends high signals
tmrpcm.play("test.wav"); //the sound file "test" will play each time whenever anyone pass from it
}
Serial.println(pirStatus);//display data in seial moniter
} 
}
