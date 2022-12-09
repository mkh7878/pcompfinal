#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 10
#define PIN 11
//neopixels are pins 10 and 11 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, 10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(20, 11, NEO_GRB + NEO_KHZ800);
//breathing sensor
int sensorPin = A0;   
//variable coming from breathing sensor
int sensorValue = 0;  
//microphone sensor
int micsensorpin=3; 
//set up a variable to hold info from D0 (HIGH or LOW)
int micState;
//nitinol wire
const int heatPin1 =  5;  

void setup() {
  strip.begin();
  strip.setBrightness(50);
  // Initialize all pixels to 'off'
  strip.show();
  //microphone is an INPUT
  pinMode(micsensorpin,INPUT);
   //start with the sensor pin off
  digitalWrite(micsensorpin,LOW);
  //heat pin is an output, starts off 
  pinMode(heatPin1, OUTPUT);    
  
}

void loop() {

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // Serial.println(sensorValue);


  if (sensorValue > 810){
    // Serial.println("breathing out");

    //pink colour for breathing out
    colorWipe(strip.Color(99, 18, 96), 50);
  }
  else{
    // // digitalWrite(heatPin1, LOW);
    // Serial.println("breathing in");

    //blue colour for breathing out
    colorWipeTop(strip.Color(18, 47, 180), 50);

  }
  micState=digitalRead(micsensorpin);//check if the mic sensor is on or off

  if(micState==HIGH){
        colorWipeTop(strip.Color(255, 0, 0), 50);
  }
  else{
    colorWipeTop(strip.Color(0, 0, 255), 50);
  }
  }

  void colorWipe(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i<12; i++) {
      strip.setPixelColor(i, c);
      strip.show();
    }
  }
  }

  void colorWipeTop(uint32_t c, uint8_t wait) {
    for(uint16_t i=12; i<20; i++) {
      strip.setPixelColor(i, c);
      strip.show();
      // i = i+2;
      // delay(wait);
    }
  }

  //controls nitinol wire. Originally this was connected to breathing rate, but it could easily overheat if the 
  //user held their breath too long... haha... will experiment more with this in the future though!!! 
    digitalWrite(heatPin1, HIGH);
    delay(1000);
    digitalWrite(heatPin1, LOW);
    delay(2000);

}



