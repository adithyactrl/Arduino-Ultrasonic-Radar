#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Pins
#define TrigPIN 7
#define EchoPIN 6
#define ServoPIN 9
#define LedRed 5
#define LedGreen 4
#define Buzzer 3

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;

int angle;
int distance;

void setup() {
  Serial.begin(9600);  // <-- ADDED: open serial at 9600 baud

  pinMode(TrigPIN, OUTPUT);
  pinMode(EchoPIN, INPUT);
  pinMode(LedRed, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  myServo.attach(ServoPIN);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Angle:");
  lcd.setCursor(0, 1);
  lcd.print("Dist:");

  delay(1000);
}

int getDistance() {
  digitalWrite(TrigPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPIN, LOW);

  long duration = pulseIn(EchoPIN, HIGH, 10000);
  if (duration == 0) return -1;
  return duration / 58;
}

void displayData(int dist) {
  lcd.setCursor(7, 0);
  lcd.print("    ");
  lcd.setCursor(7, 0);
  lcd.print(angle);
  lcd.print((char)223);

  lcd.setCursor(6, 1);
  lcd.print("       ");
  lcd.setCursor(6, 1);
  if (dist == -1) {
    lcd.print("---");
  } else {
    lcd.print(dist);
    lcd.print("cm");
  }
}

void alertSystem(int dist) {
  if (dist == -1 || dist > 50) {
    digitalWrite(LedGreen, HIGH);
    digitalWrite(LedRed, LOW);
    digitalWrite(Buzzer, LOW);
  } else if (dist > 30) {
    digitalWrite(LedGreen, LOW);
    digitalWrite(LedRed, HIGH);
    digitalWrite(Buzzer, HIGH);
    delay(150);
    digitalWrite(LedRed, LOW);
    digitalWrite(Buzzer, LOW);
    delay(150);
  } else {
    digitalWrite(LedGreen, LOW);
    digitalWrite(LedRed, HIGH);
    digitalWrite(Buzzer, HIGH);
    delay(40);
    digitalWrite(LedRed, LOW);
    digitalWrite(Buzzer, LOW);
    delay(40);
  }
}

void scan() {
  distance = getDistance();
  displayData(distance);
  alertSystem(distance);

  // ADDED: send CSV line over Serial → "ANGLE,DISTANCE\n"
  Serial.print(angle);
  Serial.print(",");
  Serial.println(distance);
}

void loop() {
  for (angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    delay(305);
    scan();
  }
  for (angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(305);
    scan();
  }
}
