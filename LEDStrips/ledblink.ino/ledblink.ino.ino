const int redPin = 6;
const int bluePin = 3;
const int greenPin = 5;

const int max_red = 255;
const int max_green = 255;
const int max_blue = 255;

byte colors[3] = {0, 0, 0};

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i <= max_red; i++){
    colors[0] = i;
    delay(10);
    for(int j=0; j <= max_green; j++){
      colors[1] = j;
      delay(10);
      for(int k=0; k <= max_blue; k++){
          colors[2] = k;
          writeColors();
          delay(10);
          
        }
        for(int k=max_blue; k >= 0; k--){
          colors[2] = k;
          writeColors();
          delay(10);
          
        }
      }
    }
}

void writeColors(){
  //set the three PWM pins according to the data read from the Serial port
  //we also scale the values with map() so that the R, G, and B brightnesses are balanced.
  analogWrite(redPin, map(colors[0], 0, 255, 0, max_red));
  analogWrite(greenPin, map(colors[1], 0, 255, 0, max_green));
  analogWrite(bluePin, map(colors[2], 0, 255, 0, max_blue));
  }
