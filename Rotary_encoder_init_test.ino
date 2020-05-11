//A basic Rotary Encoder test sketch

 #define CLK 7  // CLK 
 #define DT 6   // DT
 #define SW 5   // Switch
 //VCC
 //GND
 
 int counter = 0; 
 int aState;
 int aLastState;  
 int lastButtonPress = 0;
 
 void setup() { 
 
   pinMode (CLK,INPUT);
   pinMode (DT,INPUT);
   pinMode (SW, INPUT_PULLUP);
   
   Serial.begin (9600);
   
   aLastState = digitalRead(CLK); 
   Serial.println("**Rotary Encoder & Switch test**");  
 } 
 
 void loop()  { 
 
   aState = digitalRead(CLK);
   if (aState != aLastState){if (digitalRead(DT) != aState) { counter ++;} else { counter --;}
                             Serial.print("Current Value: "); Serial.println(counter);} 
                             aLastState = aState; 
							 
   int btnState = digitalRead(SW);
   if (btnState == LOW){if (millis() - lastButtonPress > 50){Serial.println("Button pressed!");}
                       lastButtonPress = millis();
                       }
 }
