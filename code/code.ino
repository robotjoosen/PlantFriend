#include <Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire  display(0x3c, SDA, SCL);

// timers
unsigned int blink_timer = 0;
unsigned int blink_speed = 6000;
unsigned int tweek_timer = 0;
unsigned int tweek_speed = 12500;
unsigned int sleep_timer = 0;

// Water soil
#define WATER_SOIL 15
#define WATER_SOIL_STATE_SIZE 3
int water_soil_value = 0;
int water_soil_state_values[WATER_SOIL_STATE_SIZE] = {
  600,    // Dry
  1500,   // Moist
  3000    // Wet
};
int water_soil_state = 0;
int water_soil_state_timer = 0;

// LDR
#define LDR 34
#define LDR_STATE_SIZE 3
int ldr_value = 0;
int ldr_state_values[LDR_STATE_SIZE] = {
  1000,   // Dark
  3000,   // Medium
  4095   // Light
};
int ldr_state = 0;
int ldr_state_timer = 0;

// Push button
#define PUSH_BUTTON 13
#define PUSH_BUTTON_STATE_SIZE 2
int push_button_value = 0;
int push_button_state_values[PUSH_BUTTON_STATE_SIZE] = {
  0,  // Off
  1   // On
};
int push_button_state = 0;
int push_button_state_timer = 0;

/**
 * Setup
 */
void setup() {
  Serial.begin(9600);
  pinMode(PUSH_BUTTON, INPUT);
  display.init();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
}

/**
 * Main program for(;;)
 */
void loop() {
  readSensorValues();
  setStates();

  if(ldr_state == 0) {

    /** Sleeping */
    draw_face(0,3,3);
    draw_snorring(250,2000);

  } else {

    /** Interactive */

    // Set face
    switch(water_soil_state) {
      case 2 :
        if(water_soil_state_timer < 1000) {
          display.clear();
          drawMouth(1);
          blinkEyes(3);
          display.display();
        } else {
          display.clear();
          drawMouth(3);
          blinkEyes(4);
          display.display();
        }
        break;
      case 1 :
        draw_face(0,1,1);
        break;
      case 0 :
        draw_face(1,2,2);
        break;
    }
  }
}

/**
 * Read all sensor values and set vars
 */
void readSensorValues()
{
  push_button_value = digitalRead(PUSH_BUTTON);
  water_soil_value = analogRead(WATER_SOIL);
  ldr_value = analogRead(LDR);
}

/**
 * Set states
 */
void setStates()
{
  setWaterSoilState();
  setLdrState();
  setPushButtonState();
}

/**
 * Set water soil state
 */
void setWaterSoilState()
{
  int water_soil_prev_state = water_soil_state;
  for(int i=0; i<WATER_SOIL_STATE_SIZE; i++) {
    if(water_soil_value < water_soil_state_values[i]) {
      water_soil_state = i;
      break;
    }
  }
  if(water_soil_prev_state == water_soil_state) {
    water_soil_state_timer++;
  } else {
    water_soil_state_timer = 0;
  }
}

/**
 * Set LDR state
 */
void setLdrState()
{
   int ldr_prev_state = ldr_state;
  for(int i=0; i<LDR_STATE_SIZE; i++) {
    if(ldr_value < ldr_state_values[i]) {
      ldr_state = i;
      break;
    }
  }
  if(ldr_prev_state == ldr_state) {
    ldr_state_timer++;
  } else {
    ldr_state_timer = 0;
  }
}

/**
 * Set Push Button State
 */
void setPushButtonState()
{
  int push_button_prev_state = push_button_state;
  for(int i=0; i<PUSH_BUTTON_STATE_SIZE; i++) {
    if(push_button_state_values[i] == push_button_value) {
      push_button_state = i;
    }
  }
  if(push_button_prev_state == push_button_state) {
    push_button_state_timer++;
  } else {
    push_button_state_timer = 0;
  }
}

/**
 * Sensor and OLED test
 */
void test()
{
  // Set mouth
  push_button_value = digitalRead(PUSH_BUTTON);
  int mouth_state = (push_button_value == HIGH) ? 3 : 0;

  // Set left eye
  int eye_left_state = 0;
  ldr_value = analogRead(LDR);
  if(ldr_value > 4000) {
    eye_left_state = 3;
  } else if(ldr_value > 3500) {
    eye_left_state = 2;
  } else if(ldr_value > 2000) {
    eye_left_state = 1;
  }

  // Set right eye
  int eye_right_state = 0;
  water_soil_value = analogRead(WATER_SOIL);
  if(water_soil_value > 3000) {
    eye_right_state = 3;
  } else if(water_soil_value > 2500) {
    eye_right_state = 2;
  } else if(water_soil_value > 1000) {
    eye_right_state = 1;
  }

  // Draw face
  draw_face(mouth_state,eye_left_state,eye_right_state);
}
