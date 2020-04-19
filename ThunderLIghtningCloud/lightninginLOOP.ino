/*************************************************** 
  This is an example for the Adafruit VS1053 Codec Breakout

  Designed specifically to work with the Adafruit VS1053 Codec Breakout 
  ----> https://www.adafruit.com/products/1381

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// include SPI, MP3 and SD libraries
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

// define the pins used
//#define CLK 13       // SPI Clock, shared with SD card
//#define MISO 12      // Input data, from VS1053/SD card
//#define MOSI 11      // Output data, to VS1053/SD card
// Connect CLK, MISO and MOSI to hardware SPI pins. 
// See http://arduino.cc/en/Reference/SPI "Connections"

// These are the pins used for the breakout example
#define BREAKOUT_RESET  9      // VS1053 reset pin (output)
#define BREAKOUT_CS     10     // VS1053 chip select pin (output)
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)
// These are the pins used for the music maker shield
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

Adafruit_VS1053_FilePlayer musicPlayer = 
  // create breakout-example object!
  //Adafruit_VS1053_FilePlayer(BREAKOUT_RESET, BREAKOUT_CS, BREAKOUT_DCS, DREQ, CARDCS);
  // create shield-example object!
  Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit VS1053 Simple Test");

  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  Serial.println(F("VS1053 found"));
  
   if (!SD.begin(CARDCS)) {
    Serial.println(F("SD failed, or not present"));
    while (1);  // don't do anything more
  }

  // list files
  
  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(05,05);

  // Timer interrupts are not suggested, better to use DREQ interrupt!
  //musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT); // timer int

  // If DREQ is on an interrupt pin (on uno, #2 or #3) we can do background
  // audio playing
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int
}

void loop() {
  
  Serial.println(F("Playing track 001"));
  musicPlayer.playFullFile("/track001.mp3");
  Serial.println(F("Now a delay"));
  delay(random(500, 3000));
  Serial.println(F("Playing track 002"));
  musicPlayer.playFullFile("/track002.mp3");
  Serial.println(F("Now a delay"));
  delay(random(100, 3000));
  Serial.println(F("Playing track 003"));
  musicPlayer.playFullFile("/track003.mp3");
  Serial.println(F("Now a delay"));
  delay(random(1000, 5000));
  Serial.println(F("Playing track 004"));
  musicPlayer.playFullFile("/track004.mp3");
  Serial.println(F("Now a delay"));
  delay(random(500, 9000));
  Serial.println(F("Playing track 005"));
  musicPlayer.playFullFile("/track005.mp3");
  Serial.println(F("Now a delay"));
  delay(random(1000, 10000));
  Serial.println(F("Playing track 006"));
  musicPlayer.playFullFile("/track006.mp3");
  Serial.println(F("Now a delay"));
  delay(random(1000, 10000));
  Serial.println(F("Playing track 007"));
  musicPlayer.playFullFile("/track007.mp3");
  Serial.println(F("Now a delay"));
  delay(random(1000, 10000));
  Serial.println(F("Playing track 008"));
  musicPlayer.playFullFile("/track008.mp3");
  Serial.println(F("Now a delay"));
  delay(random(50, 10000));
  Serial.println(F("Playing track 009"));
  musicPlayer.playFullFile("/track009.mp3");
  Serial.println(F("Now a delay"));
  delay(random(300, 10000));
  Serial.println(F("Playing track 010"));
  musicPlayer.playFullFile("/track010.mp3");
  Serial.println(F("Now a delay"));
  delay(random(2000, 10000));
  Serial.println(F("Playing track 011"));
  musicPlayer.playFullFile("/track011.mp3");
  Serial.println(F("Now a delay"));
  delay(random(2000, 10000));
  Serial.println(F("Playing track 012"));
  musicPlayer.playFullFile("/track012.mp3");
  Serial.println(F("Now a delay"));
  delay(random(400, 10000));
  Serial.println(F("Playing track 013"));
  musicPlayer.playFullFile("/track013.mp3");
  Serial.println(F("Now a delay"));
  delay(random(1000, 10000));
  return;
}
