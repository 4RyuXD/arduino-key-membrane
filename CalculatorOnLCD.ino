// Include libraries

#include <Keypad.h>
#include <LiquidCrystal.h>

// Set up LiquidCrystal class and variables
const int rs = 50, e = 51, d4 = 2, d5 = 3, d6 = 4, d7 = 5;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

// Initialize Keypad Membrane
const byte R = 4;
const byte C = 4;

byte rp[R] = {13, 12, 11, 10};
byte cp[C] = {9, 8, 7, 6};

char key[R][C] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {';', '0', '=', '/'}
};

Keypad ukey = Keypad(makeKeymap(key), rp, cp, R, C);

// Assign starter values to calculating variables and other
bool n1b = false;
long num1 = 0;
long num = 0;
char op = '0';

long tot = 0;

double ans = 0;

void setup() {
  // Initialize LCD screen
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);

}

void loop() {
  // Record Key presses
  char keyPress = ukey.getKey();

  // If the answer is requested
  if (keyPress == '=') {
    lcd.clear();
    num = tot;

    // Check which operator was used and calculate accordingly
    switch (op) {
      case '+':
        ans = num1 + num;
        break;
      case '-':
        ans = num1 - num;
        break;
      case '*':
        ans = num1 * num;
        break;
      case '/':
        ans = float(num1) / float(num);
        break;
    }

    // Print answer
    lcd.setCursor(0, 0);
    lcd.print(ans);

  // If answer is not requested (to log num1 and num)
  } else {
    // Check whether the key pressed is a number
    if (keyPress >= '0' && keyPress <= '9') {

      // Check whether the first number has been inputted or not
      if (n1b == false) {

        // Read and print first number
        tot = (tot * 10) + (keyPress - '0');
        lcd.setCursor(0, 0);
        lcd.print(tot);

        // If first number was inputted
      } else {

        // Read and print second number
        tot = (tot * 10) + (keyPress - '0');
        lcd.setCursor(0, 0);
        lcd.print(" ");
        lcd.print(tot);
      }
    }

    // Check if any operator was pressed
    if (keyPress == '+' || keyPress == '-' || keyPress == '*' || keyPress == '/') {
      // Allows for second number input
      n1b == true;

      // Clear lcd and print operator
      lcd.clear();
      lcd.print(keyPress);
      op = keyPress;

      // Assign num1 input to num1
      num1 = tot;

      // Reset temporary num input
      tot = 0;

      // Delay for accuracy
      delay(100);
    }
    // If screen is requested to be cleared
    if (keyPress == ';') {
      // Clear and reset cursor position
      lcd.clear();
      lcd.setCursor(0, 0);

      // Assign starter values back to variables
      op = 0;
      ans = 0;
      num1 = 0;
      num = 0;
      tot = 0;
      n1b = false;
    }
  }
}








































































































































































// Code by Hamdan Naseer (4RyuXD on Github)
