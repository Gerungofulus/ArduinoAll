#include <FastLED.h>
#define NUM_LEDS 100
#define DATA_PIN 11

int delayTime = 20;
CRGB leds[NUM_LEDS];
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
  
}

void loop() {
      // Turn the first led red for 1 second
      for(int i = 0; i < NUM_LEDS; i++){
          leds[i] = CRGB::Red;
          FastLED.show();
          delay(delayTime);
          if(i > 0){
            leds[i-1] = CRGB::Black;
            FastLED.show();
          }
        }
        for(int i = NUM_LEDS; i > 0; i--){
          leds[i] = CRGB::Black;
          FastLED.show();
          delay(delayTime);
          if(i > 0){
            leds[i-1] = CRGB::Green;
            FastLED.show();
          }  
        }
      
    }
