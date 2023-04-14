#include <TaskManagerIO.h>

int leds[] = {3, 5, 6, 9, 10, 11};
int ledsState[] = {LOW, LOW, LOW, LOW, LOW, LOW};

void setup() {
  /*назначем пины 1 (serial transmit) и 2..7 как Output,
  но оставляем пин 0 (serial receive) как Input
  (в противном случае serial port перестанет работать!) ...
  Регистр DDR - дописываем букву порта - DDRD, DDRB        
  DDRD = B11111110;  цифровые пины 7,6,5,4,3,2,1,0
  */
  DDRD = B01101000;  //цифровые пины 6,5,3 как OUTPUT
  //DDRB = B00111111;  цифровые пины -,-,13,12,11,10,9,8
  DDRB = B00001110; //цифровые пины 11,10,9 как OUTPUT
  
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
  if (ledState) {
    switch(led) {
      case 3:
        PORTD |= B00001000;
        break;
      case 5:
        PORTD |= B00100000;
        break;
      case 6:
        PORTD |= B01000000;
        break;
      case 9:
        PORTB |= B00000010;
        break;
      case 10:
        PORTB |= B00000100;
        break;
      case 11:
        PORTB |= B00001000;
        break;
    }
  }
  else {
    switch(led) {
      case 3:
        PORTD &= ~B00001000;
        break;
      case 5:
        PORTD &= ~B00100000;
        break;
      case 6:
        PORTD &= ~B01000000;
        break;
      case 9:
        PORTB &= ~B00000010;
        break;
      case 10:
        PORTB &= ~B00000100;
        break;
      case 11:
        PORTB &= ~B00001000;
        break;
    }
  }
}