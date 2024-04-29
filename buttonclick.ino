
const int LED = 9; //Подключаем светодиод
const int BUTTON = 2; //Подключаем кнопку
bool lastButton = LOW; //Сохраняем предыдущее состояние кнопки

bool currentButton = LOW; //Текущее состояние кнопки

bool ledOn = false; //Текущее состояние светодиода


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); //Седодиод выход
  pinMode(BUTTON, INPUT); // Кнопка вход
}

//Функция сглаживания дребезга кнопки, принимает предыдущее состояние кнопки и выдает фактическое
bool debounce(bool last){
  bool current = digitalRead(BUTTON); //Читаем состояние кнопки
  if (last != current){
    delay(5);
    current = digitalRead(BUTTON); //Считываю состояние кнопки
    return current; //Возвращаю состояние
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH){
    ledOn = !ledOn;
  }
  lastButton = currentButton;
  digitalWrite(LED, ledOn);

}
