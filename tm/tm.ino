#include <TaskManagerIO.h>

int leds[] = {3, 5, 6, 9, 10, 11};
int ledsState[] = {LOW, LOW, LOW, LOW, LOW, LOW};

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
  }

  taskManager.scheduleFixedRate(15625, [] {
    led(ledsState[0], leds[0]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(31250, [] {
    led(ledsState[1], leds[1]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(62500, [] {
    led(ledsState[2], leds[2]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(125000, [] {
    led(ledsState[3], leds[3]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(250000, [] {
    led(ledsState[4], leds[4]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(500000, [] {
    led(ledsState[5], leds[5]);
  }, TIME_MICROS);
}

void loop() {
  taskManager.runLoop();
}

void led(int &ledState, int led)
{
  ledState = !ledState;
  digitalWrite(led, ledState);
}