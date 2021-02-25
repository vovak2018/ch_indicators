// Пример для библиотеки hc_indicators по подключению семисегментного одноразрядного индикатора.
// Написан 25.02.2021 
// @lava_frai

#include <hc_indicators.h> // Импортируем библиотеку

Seven_segment indicator(2, 3, 4); // Пины 11, 12 и 14 сдвигового регистра (Распиновка есть в папке с примерами)
// Схему подключения вы можете найти в папке с примером
// Заранее простите за ее ужасный вид. 
// Кто знает, как и в чем можно рисовать нормальные схемы, пожалуйстна напишите мне vladimirkurdiukov@gmail.com или https://vk.com/lava_frai

void setup() {
  Serial.begin(9600);
}

void loop() {
  indicator.fill(); // Заполняет индикатор
  delay(2000);
  indicator.clear(); // Очищает индикатор (Убирая точку)
  delay(2000);
  indicator.write("5"); // Вывод текста, как числа
  delay(2000);
  for (int i = 0;i < 10;i++){
    indicator.removeDot(); // Убираем точку
    indicator.write(i); // Печатаем число
    delay(200);
    indicator.addDot(); // Включаем точку
    // indicator.write(i); // Было необходимо в старых версиях
    delay(200);
    Serial.println(indicator.get()); // get возвращает текущий байт на индикаторе (Если вдруг понадобится)
  }
}
