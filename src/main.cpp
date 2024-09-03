#include <Arduino.h>
#include <FastLED.h>

const int OB_PIN = 13;  // Onboard LED is connected to pin 13

#define LED_PIN     9     // The pin your LED data line is connected to
#define NUM_LEDS    3     // Number of LEDs in your array
#define BRIGHTNESS  255    // Set the brightness (0-255)
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

#define CLR_OFF CRGB::Black
#define CLR_ON CRGB::Red

CRGB::HTMLColorCode led_state_table[8][3] =
{
{CLR_OFF, CLR_OFF, CLR_OFF},
{CLR_ON, CLR_ON, CLR_ON},
{CLR_ON, CLR_OFF, CLR_OFF},
{CLR_OFF, CLR_ON, CLR_OFF},
{CLR_OFF, CLR_OFF, CLR_ON},
{CLR_ON, CLR_ON, CLR_OFF},
{CLR_OFF, CLR_ON, CLR_ON},
{CLR_ON, CLR_OFF, CLR_ON}
};

CRGB leds[NUM_LEDS];

void obled_setup() {
  pinMode(OB_PIN, OUTPUT);
}

void obled_loop() {
  digitalWrite(OB_PIN, HIGH); 
  delay(1000);                  
  digitalWrite(OB_PIN, LOW);   
  delay(1000);                  
}

void fled_setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void set_state(int s) {
  CRGB::HTMLColorCode *state = led_state_table[s];

  leds[0] = state[0];
  leds[1] = state[1];
  leds[2] = state[2];
}

void vader_7step() {
  set_state(1);
  FastLED.show();
  delay(1500);

  set_state(7);
  FastLED.show();
  delay(1500);

  set_state(4);
  FastLED.show();
  delay(1500);

  set_state(2);
  FastLED.show();
  delay(1500);

  set_state(5);
  FastLED.show();
  delay(1500);

  set_state(3);
  FastLED.show();
  delay(1500);

  set_state(6);
  FastLED.show();
  delay(1500);
}

void vader_8step() {
  set_state(1);
  FastLED.show();
  delay(1500);

  set_state(6);
  FastLED.show();
  delay(1500);

  set_state(2);
  FastLED.show();
  delay(1500);

  set_state(5);
  FastLED.show();
  delay(1500);

  set_state(3);
  FastLED.show();
  delay(1500);

  set_state(5);
  FastLED.show();
  delay(1500);

  set_state(6);
  FastLED.show();
  delay(1500);

  set_state(7);
  FastLED.show();
  delay(1500); 
}

void setup() {
 // obled_setup();
  fled_setup();
}

void loop() {
  vader_7step();
  vader_8step();
}