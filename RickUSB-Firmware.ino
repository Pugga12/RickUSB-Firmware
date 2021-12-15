/* 
  RickUSB-Firmware 1.1

  USB RickRolling as fast as clicking a link
  99.9% success rate so far
  Code built for Adafruit Neo Trinkey M0
  Should work on any SAMD21 or 32u4 Board

  Copyright 2021 NotAddyPug

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/
#include <Adafruit_NeoPixel.h>
#include "Keyboard.h"

#define SetupDelay 3000
// Create the neopixel strip with the built in definitions NUM_NEOPIXEL and PIN_NEOPIXEL
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_NEOPIXEL, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800); 
void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(20);
  strip.fill(strip.Color(255, 0, 0));
  strip.show();
  Keyboard.begin();
  delay(SetupDelay);
  Serial.println("Rolling...");
  strip.fill(strip.Color(0, 255, 0));
  strip.show();
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('r');
  Keyboard.releaseAll();
  delay(100);
  Keyboard.write(KEY_BACKSPACE);
  delay(100);
  Keyboard.println("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  Serial.println("Rolling Complete");
}
void loop() {
  // put your main code here, to run repeatedly:

}
