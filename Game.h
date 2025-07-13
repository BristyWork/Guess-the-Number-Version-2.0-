#ifndef GUESS_THE_NUMBER_GAME_H  // Защита от повторного включения
#define GUESS_THE_NUMBER_GAME_H

#include <string>

// Константы
const int MIN_NUMBER = 1;    // Минимальное загадываемое число
const int MAX_NUMBER = 100;  // Максимальное загадываемое число

// Объявления функций

/// Генерирует случайное число в диапазоне [min, max]
int generateRandomNumber(int min, int max);

/// Запускает одну игру (угадывание числа) и возвращает количество попыток
int playGame(int targetNumber);

/// Выводит приветствие и правила игры
void printWelcomeMessage();

/// Запрашивает у пользователя догадку и возвращает её
int getUserGuess();

/// Проверяет догадку пользователя и даёт подсказку (больше/меньше)
/// Возвращает true, если число угадано
bool checkGuess(int guess, int targetNumber);

/// Спрашивает у пользователя, хочет ли он сыграть ещё раз
/// Возвращает true, если ответ 'y' или 'Y'
bool askToPlayAgain();

#endif // GUESS_THE_NUMBER_GAME_H