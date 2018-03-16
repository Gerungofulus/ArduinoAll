#include <FastLED.h>
#define DATA_PIN 11
#define MAT_ROWS 10
#define MAT_COLS 10
#define NUM_LEDS (MAT_ROWS * MAT_COLS)
CRGB leds[NUM_LEDS];
int delayTime = 20;
struct Point {
  int x;
  int y;
};
int pointToIndex(Point& point ) {

  int index = point.x + point.y * MAT_ROWS;
  return index;
}

//take the heart from bitlove.org
//margin: one col in front and two in the end free,
//        two bottom and two top
/* 0000000000
 * 0000000000
 * 00##0##000
 * 0#######00
 * 0#######00
 * 00#####000
 * 000###0000
 * 0000#00000
 * 0000000000
 * 0000000000
 */
/* 0000000000
* 00#000#000
* 0###0###00
* #########0
* #########0
* 0#######00
* 00#####000
* 000###0000
* 0000#00000
* 0000000000
*/
void paintHeart() {

}

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:

}
