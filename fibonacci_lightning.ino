// stolen from https://github.com/fibonacci162

#include <FastLED.h>
 
#define LED_PIN 13                           // hardware SPI pin SCK
#define NUM_LEDS 60
#define COLOR_ORDER RGB
#define LED_TYPE WS2812B
#define MAX_BRIGHTNESS 255                  // watch the power!
#define FPS 50
#define FLASHES 8
#define FREQUENCY 1

struct CRGB leds[NUM_LEDS];

unsigned int dimmer = 1;

void setup() 
{
  delay(1000);
  LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(MAX_BRIGHTNESS);
}

// The first "flash" in a bolt of lightning is the "leader." The leader
// is usually duller and has a longer delay until the next flash. Subsequent
// flashes, the "strokes," are brighter and happen at shorter intervals.

void loop() 
{
  for (int flashCounter = 0; flashCounter < random8(3,FLASHES); flashCounter++)
  {
    if(flashCounter == 0) dimmer = 5;     // the brightness of the leader is scaled down by a factor of 5
    else dimmer = random8(1,3);           // return strokes are brighter than the leader
    
    FastLED.showColor(CHSV(255, 0, 255/dimmer));
    delay(random8(4,10));                 // each flash only lasts 4-10 milliseconds
    FastLED.showColor(CHSV(255, 0, 0));
    
    if (flashCounter == 0) delay (150);   // longer delay until next flash after the leader
    delay(50+random8(100));               // shorter delay between strokes  
  }
  delay(random8(FREQUENCY)*100);          // delay between strikes
}
