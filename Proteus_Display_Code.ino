#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_COLS 20
#define LCD_ROWS 4

int Relay = 7;
int Pay_10 = 22;
int Pay_20 = 23;
int TurnOn = 0;
int TurnOn_2 = 0;

#define LCD_I2C_ADDRESS 0x20
LiquidCrystal_I2C lcd(LCD_I2C_ADDRESS, LCD_COLS, LCD_ROWS);


void setup() {
  pinMode(Relay, OUTPUT);
  pinMode(Pay_10, INPUT);
  pinMode(Pay_20, INPUT);

  digitalWrite(Relay, LOW);

  lcd.begin(LCD_COLS, LCD_ROWS);

  lcd.backlight();

  lcd.clear();
  lcd.setCursor(7, 1);
  lcd.print("SYSTEM");
  lcd.setCursor(3, 2);
  lcd.print("INITIALIZATION");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CHARGING POINTS");
  lcd.setCursor(0, 1);
  lcd.print("SOCKET STATUS: OFF");
  lcd.setCursor(3, 2);
  lcd.print("PAY ANY AMOUNT");
  lcd.setCursor(2, 3);
  lcd.print("TO USE THE SOCKET");
}
void loop() {
  if (digitalRead(Pay_10) == HIGH && TurnOn == 0 && digitalRead(Relay) == LOW) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("CHARGING POINTS");
    lcd.setCursor(0, 1);
    lcd.print("SOCKET STATUS: ON");
    lcd.setCursor(0, 2);
    lcd.print("AMOUNT PAID: 10");
    lcd.setCursor(0, 3);
    lcd.print("TIME:");
    digitalWrite(Relay, HIGH);
    delay(5000);
    digitalWrite(Relay, LOW);
    TurnOn = 1;
  } else if (digitalRead(Pay_10) == LOW && digitalRead(Relay) == LOW && TurnOn == 1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CHARGING POINTS");
    lcd.setCursor(0, 1);
    lcd.print("SOCKET STATUS: OFF");
    lcd.setCursor(3, 2);
    lcd.print("PAY ANY AMOUNT");
    lcd.setCursor(2, 3);
    lcd.print("TO USE THE SOCKET");
    delay(1000);
    TurnOn = 0;
  }
  if (digitalRead(Pay_20) == HIGH && TurnOn_2 == 0 && digitalRead(Relay) == LOW) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("CHARGING POINTS");
    lcd.setCursor(0, 1);
    lcd.print("SOCKET STATUS: ON");
    lcd.setCursor(0, 2);
    lcd.print("AMOUNT PAID: 20");
    lcd.setCursor(0, 3);
    lcd.print("TIME:");
    digitalWrite(Relay, HIGH);
    delay(10000);
    digitalWrite(Relay, LOW);
    TurnOn_2 = 1;
  } else if (digitalRead(Pay_20) == LOW && digitalRead(Relay) == LOW && TurnOn_2 == 1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CHARGING POINTS");
    lcd.setCursor(0, 1);
    lcd.print("SOCKET STATUS: OFF");
    lcd.setCursor(3, 2);
    lcd.print("PAY ANY AMOUNT");
    lcd.setCursor(2, 3);
    lcd.print("TO USE THE SOCKET");
    delay(1000);
    TurnOn_2 = 0;
  }
  
}