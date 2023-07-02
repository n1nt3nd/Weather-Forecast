Прогноз погоды. Внешние библиотеки.

## Задача

Реализовать консольное приложение, отображающие прогноз погоды для выбранного списка городов, используя сторонние библиотеки.

## Источник данных

- [Open-Meteo](https://open-meteo.com/en/docs#latitude=59.94&longitude=30.31&hourly=temperature_2m&forecast_days=16) для прогноза
- [Api-Ninjas](https://api-ninjas.com/api/city) для определения координат по названию города

## Функциональные требования

 - Отображать прогноз погоды на несколько дней вперед (значение по умолчанию задается конфигом)
 - Обновлять с некоторой частотой (задается конфигом)
 - Переключаться между городами с помощью клавиш "n", "p"
 - Заканчивать работу программы по Esc
 - Увеличивать\уменьшать количество дней прогноза по нажатие клавиш "+", "-"

Список городов, частота обновления, количество дней прогноза должны быть определены в конфиге(например в формате OMFL)

## Отображение

В качестве образца для визуализации предлагается взять следующий:

![image](interface.png) Скриншот взят с  https://wttr.in

## Реализация

В качестве библиотеки для запросов требуется воспользоваться [C++ Requests](https://github.com/libcpr/cpr)





