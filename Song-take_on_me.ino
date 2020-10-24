//TAKE ON ME - A-HA. by Zoé Trejo

#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "pitches.h"

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
 
int melody[] = {

  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5,
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5,
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5,
  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5,
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5,
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_E5, 0,
  NOTE_D5, NOTE_D5, NOTE_CS5, NOTE_B4, 0,
  NOTE_CS5, NOTE_CS5, NOTE_A4,
  0, NOTE_FS5, NOTE_FS5, NOTE_E5,
  NOTE_D5, NOTE_D5, NOTE_CS5, NOTE_B4, 0,
  NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4,
  NOTE_B4, NOTE_CS5, NOTE_B4, NOTE_A4,
  0, NOTE_D5, NOTE_D5, NOTE_D5, 0,
  0, NOTE_A4, NOTE_A4, NOTE_A4, 
  NOTE_A4, NOTE_GS4, NOTE_GS4, NOTE_FS4,
  NOTE_A3, 0, NOTE_E4, 0, NOTE_FS4, 0,
  NOTE_E5, NOTE_FS5, NOTE_E5,
  NOTE_A4, 0, NOTE_E5, 0, NOTE_FS5, 0,
  NOTE_E5, NOTE_FS5, NOTE_E5,
  NOTE_CS5, 0, NOTE_GS5, 0, NOTE_A5, 0, NOTE_CS5,
  NOTE_CS5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_E5, 0,
  NOTE_GS5, 0, NOTE_FS5, 0, NOTE_GS5, 0, NOTE_A5, 0
  
};

float notesDurations[] = {   
        
  8, 8, 8, 4, 4, 4,
  4, 8, 8, 8, 8, 8,
  8, 8, 8, 4, 4, 4,
  4, 8, 8, 8, 8, 8,
  8, 8, 8, 4, 4, 4,
  4, 8, 8, 8, 8, 8,
  8, 8, 8, 4, 4, 4,
  4, 8, 8, 8, 8, 8,
  2.66, 4, 8, 1.33, 2,
  2.66, 4, 2.66,
  8, 2.66, 4, 4,
  2.66, 4, 8, 1.33, 2,
  4, 8, 4, 4, 4,
  4, 8, 4, 4,
  2, 4, 8, 1.6, 2,
  4, 4, 4, 4,
  4, 4, 4, 4,
  2, 2, 2, 2, 2, 2,
  2.66, 2.66, 4,
  2, 2, 2, 2, 2, 2,
  2.66, 2.66, 4,
  2, 2, 2, 2, 2, 2, 8,
  4, 8, 4, 4, 0.8, 2,
  1.14, 8, 1.14, 8, 1.14, 8,
  1.14, 8
  
};

int speaker = 3;
int button = 2;

int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
int led5 = 8;
int led6 = 9;

int leds[] = { 
  
  led1, led2, led3, led4, led5, led6
  
};

void setup() {

  pinMode(speaker, OUTPUT);
  pinMode(button, INPUT);
    
  for(int i = 0; i < 9; i++)
    pinMode(leds[i], OUTPUT);

  lcd.begin(16,2);
  lcd.clear();
  lcd.backlight();
  lcd.home();
  
  lcd.setCursor(0,0);
  lcd.print("** TAKE ON ME **");
  lcd.setCursor(0,1);
  lcd.print("-By: Zoe Trejo-/");
  delay(2000);
  
}
  
void loop() {

  for(int i = 0; i < 9; i++)
    digitalWrite(leds[i], HIGH);

  lcd.scrollDisplayRight();
  delay(100);
  
  int buttonstage = digitalRead(button);
  
  if (buttonstage == HIGH){

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("** TAKE ON ME **");
  lcd.setCursor(0,1);
  lcd.print("-By: Zoe Trejo-/");

    for(int i = 0; i < 2; i++){
      
      for(int thisNote = 0; thisNote < 24; thisNote++) {
      
        float noteDuration = 1062.5 / notesDurations[thisNote];

        ledShow(thisNote);

        tone(speaker, melody[thisNote], noteDuration);
      
        float pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(speaker);
        
      }
      
    }

    for(int thisNote = 24; thisNote < 48; thisNote++) {
      
      float noteDuration = 1062.5 / notesDurations[thisNote];

      ledShow(thisNote);

      tone(speaker, melody[thisNote], noteDuration);
      
      float pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(speaker);

    }
      
    for(int thisNote = 48; thisNote < 87; thisNote++) {
      
      float noteDuration = 1062.5 / notesDurations[thisNote];

      ledShow(thisNote);

      tone(speaker, melody[thisNote], noteDuration);
      
      float pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(speaker);
    
    }

    for(int thisNote = 87; thisNote < 118; thisNote++) {
      
      float noteDuration = 1062.5 / notesDurations[thisNote];

      ledShow(thisNote);

      tone(speaker, melody[thisNote], noteDuration);
      
      float pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(speaker);
      
    }

    for(int thisNote = 48; thisNote < 87; thisNote++) {
      
      float noteDuration = 1062.5 / notesDurations[thisNote];

      ledShow(thisNote);

      tone(speaker, melody[thisNote], noteDuration);
      
      float pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(speaker);
    
    }

    
    for(int i = 0; i < 2; i++) {
      
      for(int thisNote = 87; thisNote < 118; thisNote++) {
      
        float noteDuration = 1062.5 / notesDurations[thisNote];

        ledShow(thisNote);

        tone(speaker, melody[thisNote], noteDuration);
      
        float pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(speaker);
      
      }
      
    }

    for(int thisNote = 118; thisNote < 126; thisNote++) {
      
      float noteDuration = 1062.5 / notesDurations[thisNote];

      ledShow(thisNote);

      tone(speaker, melody[thisNote], noteDuration);
      
      float pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(speaker);
    
    }
    
  }

  lcd.noAutoscroll();
  delay(100);
  
}

void ledShow(int indicator) {

  if(melody[indicator] == NOTE_A3 || melody[indicator] == NOTE_A4 
     || melody[indicator] == NOTE_A5)
    digitalWrite(led1,HIGH);
  else
    digitalWrite(led1,LOW);

  if(melody[indicator] == NOTE_E4 || melody[indicator] == NOTE_E5)
    digitalWrite(led2,HIGH);
  else
    digitalWrite(led2,LOW);

  if(melody[indicator] == NOTE_FS4 || melody[indicator] == NOTE_FS5)
    digitalWrite(led3,HIGH);
  else
    digitalWrite(led3,LOW);

  if(melody[indicator] == NOTE_GS4 || melody[indicator] == NOTE_GS5 
     || melody[indicator] == NOTE_D5)
    digitalWrite(led4,HIGH);
  else
    digitalWrite(led4,LOW);

  if(melody[indicator] == NOTE_B4 || melody[indicator] == NOTE_B5)
    digitalWrite(led5,HIGH);
  else
    digitalWrite(led5,LOW);

  if(melody[indicator] == NOTE_CS5)
    digitalWrite(led6,HIGH);
  else
    digitalWrite(led6,LOW);

}
