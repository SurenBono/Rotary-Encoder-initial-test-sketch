#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#define CLK 7  // CLK 
#define DT 6   // DT
#define SW 5   // Switch

 int counter = 0; 
 int aState;
 int aLastState;  
 int lastButtonPress = 0;

void setup() {
  pinMode (CLK,INPUT);
  pinMode (DT,INPUT);
  pinMode (SW, INPUT_PULLUP);
  lcd.begin();
  Serial.begin(9600);
  //Serial.println(" Rotary Counter");
  aLastState = digitalRead(CLK); 
  lcd.setCursor(0,0);
  lcd.print("   Rotary Counter");
  lcd.setCursor(3,1);lcd.print("Value: ");
  lcd.setCursor(11,1);lcd.print(counter);
}

void loop() {
	
	aState = digitalRead(CLK);
   if (aState != aLastState){if (digitalRead(DT) != aState) { counter ++;} else { counter --;}
                             lcd.setCursor(11,1);lcd.print("     ");lcd.setCursor(11,1);lcd.print(counter);} 
                             aLastState = aState; 
							 
   int btnState = digitalRead(SW);
   if (btnState == LOW){if (millis() - lastButtonPress > 50){lcd.setCursor(3,2);lcd.print("Button pressed!");delay(1000);lcd.setCursor(3,2);lcd.print("                  ");}
                       lastButtonPress = millis();
                       }lcd.setCursor(0,2);
	
}
