const int ledPin = 13;
unsigned long previousMillis = 0;
long interval = 1000;  // Начальный интервал — 1 секунда

void setup() {
  pinMode(ledPin, OUTPUT);
  randomSeed(analogRead(0));  // Инициализируем генератор случайных чисел
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // Меняем состояние светодиода
    if (digitalRead(ledPin) == HIGH) {
      digitalWrite(ledPin, LOW);
    } else {
      digitalWrite(ledPin, HIGH);
    }
    
    // Генерируем новый случайный интервал (от 200 до 2000 мс)
    interval = random(200, 2000);
  }
}
