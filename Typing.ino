#include <Keypad.h>
#include <LiquidCrystal.h>


const int rs = 12, e = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;


LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

const byte R = 4;
const byte C = 4;


byte rp[R] = {13, A0, A1, 10};
byte cp[C] = {9, 8, 7, 6};


char key[R][C] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


Keypad ukey = Keypad(makeKeymap(key), rp, cp, R, C);


void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);


}


void loop() {
  char keyPress = ukey.getKey();
  if (keyPress) {
    lcd.print(keyPress);
    delay(100);
  }
}
