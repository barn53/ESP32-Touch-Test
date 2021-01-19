#include <Arduino.h>

#define TOUCH_PIN 4 //Für Touch: 2, 4, 12, 13, 14, 15, 27
#define LED 2

void setup()
{
  Serial.begin(115200);
  Serial.println("Touch Test");
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop()
{
  int touch_value(touchRead(TOUCH_PIN));
  int hall_value(hallRead());

  int last_touch_value(0);
  int last_hall_value(0);

  if (last_touch_value != touch_value || last_hall_value != hall_value)
  {
    Serial.printf("touch: %d, hall: %d\n", touch_value, hall_value);
    last_touch_value = touch_value;
    last_hall_value = hall_value;
  }

  if (touch_value < 50)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }

  delay(500);
}
