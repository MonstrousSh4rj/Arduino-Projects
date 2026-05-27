/*
 * ╔══════════════════════════════════════════════╗
 * ║           RoadWatcher — Arduino Uno          ║
 * ║    IR Sensor Based Vehicle Speed Monitor     ║
 * ╚══════════════════════════════════════════════╝
 *
 *  IR Sensor 1 OUT  →  Pin 2
 *  IR Sensor 2 OUT  →  Pin 3
 *  Buzzer (+)       →  Pin 11
 *  Place sensors exactly 20 cm apart.
 */

const int IR_S1  = 2;
const int IR_S2  = 3;
const int BUZZER = 11;

const float ACTUAL_DISTANCE    = 0.2;
const float SIMULATED_DISTANCE = 5.0;
const float SPEED_LIMIT        = 50.0;

float timer1 = 0, timer2 = 0, elapsedTime = 0;
int   flag1  = 0, flag2  = 0;
float speed  = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IR_S1,  INPUT);
  pinMode(IR_S2,  INPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
  Serial.println("READY");
}

void loop() {
  if (digitalRead(IR_S1) == LOW && flag1 == 0) {
    timer1 = millis();
    flag1  = 1;
    Serial.println("STATUS:Searching");
  }

  if (digitalRead(IR_S2) == LOW && flag2 == 0) {
    timer2 = millis();
    flag2  = 1;
  }

  if (flag1 == 1 && flag2 == 1) {
    elapsedTime = abs(timer1 - timer2) / 1000.0;

    if (elapsedTime < 0.01) {
      speed = 0;
    } else {
      speed = (ACTUAL_DISTANCE / elapsedTime);
      speed = speed * (SIMULATED_DISTANCE / ACTUAL_DISTANCE);
      speed = speed * 3.6;
    }

    if (speed > 0) {
      Serial.print("SPEED:");
      Serial.println(speed, 1);

      if (speed > SPEED_LIMIT) {
        Serial.println("ALERT:OverSpeed");
        tone(BUZZER, 2300);
      } else {
        Serial.println("ALERT:Normal");
      }
    }

    delay(3000);
    noTone(BUZZER);
    speed = 0;
    flag1 = 0;
    flag2 = 0;
  }

  if (flag1 == 0 && flag2 == 0) {
    Serial.println("STATUS:Waiting");
  }

  delay(300);
}
