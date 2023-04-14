int leds[] = {3, 5, 6, 9, 10, 11};
int ledsState[] = {LOW, LOW, LOW, LOW, LOW, LOW};

unsigned long intervals[] = {15625, 31250, 62500, 125000, 250000, 500000};
unsigned long previousIntervals[] = {0, 0, 0, 0, 0, 0};
unsigned long currentTime;

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
}

void loop() {
  for (int ledN = 0; ledN < 6; ledN++)
  {
    /*Возвращает количество микросекунд с момента начала выполнения текущей программы на плате Arduino.
    Значение переполняется и сбрасывается на ноль, приблизительно через 70 минут.
    На 16MHz платах Ардуино (Duemilanove и Nano)
    функция micros() имеет разрешение 4 микросекунды
    (возвращаемое значение всегда кратно 4)*/
    currentTime = micros();
    if (currentTime - previousIntervals[ledN] >= intervals[ledN]) {
      previousIntervals[ledN] = currentTime;

      ledsState[ledN] = !ledsState[ledN];
      if (ledsState[ledN]) {
        switch(leds[ledN]) {
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
        switch(leds[ledN]) {
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
  }
}