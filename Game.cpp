/*
 * Игра "Угадай число"
 * Автор: BristyWork
 * Лицензия: MIT
 * Версия: 2.0
 * Исправлены ошибки компиляции
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <windows.h> // Для цветного вывода в Windows

using namespace std;

// Коды цветов для Windows Console
enum ConsoleColor {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    YELLOW = 6,
    WHITE = 7,
    GRAY = 8,
    BRIGHT_BLUE = 9,
    BRIGHT_GREEN = 10,
    BRIGHT_CYAN = 11,
    BRIGHT_RED = 12,
    BRIGHT_MAGENTA = 13,
    BRIGHT_YELLOW = 14,
    BRIGHT_WHITE = 15
};

// Установка цвета текста
void setColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Сброс цвета
void resetColor() {
    setColor(WHITE);
}

// Вывод цветного текста
void printColored(const string& text, ConsoleColor color) {
    setColor(color);
    cout << text;
    resetColor();
}

// Структура для уровней сложности
struct DifficultyLevel {
    int min;
    int max;
    string name;
    ConsoleColor color;
};

const DifficultyLevel levels[] = {
    {1, 50, "Легкий", GREEN},
    {1, 100, "Средний", YELLOW},
    {1, 200, "Сложный", RED},
    {1, 500, "Эксперт", MAGENTA},
    {1, 1000, "Безумный", BRIGHT_RED}
};

const int LEVELS_COUNT = sizeof(levels) / sizeof(levels[0]);

void clearInputBuffer() {
    cin.clear();
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
}

bool askToPlayAgain() {
    char choice;
    while (true) {
        printColored("\nХотите сыграть еще раз? (y/n): ", CYAN);
        cin >> choice;
        clearInputBuffer();

        if (choice == 'y' || choice == 'Y') {
            return true;
        }
        else if (choice == 'n' || choice == 'N') {
            return false;
        }
        printColored("Неверный ввод. Пожалуйста, введите 'y' или 'n'.\n", RED);
    }
}

int selectDifficulty() {
    int choice;
    while (true) {
        printColored("\nВыберите уровень сложности:\n", BRIGHT_WHITE);
        for (int i = 0; i < LEVELS_COUNT; i++) {
            setColor(levels[i].color);
            cout << i + 1 << ". " << levels[i].name << " (" << levels[i].min << "-" << levels[i].max << ")\n";
        }
        resetColor();
        printColored("Ваш выбор: ", CYAN);

        cin >> choice;
        if (cin.fail() || choice < 1 || choice > LEVELS_COUNT) {
            clearInputBuffer();
            printColored("Неверный ввод. Пожалуйста, выберите уровень от 1 до " + to_string(LEVELS_COUNT) + ".\n", RED);
            continue;
        }
        break;
    }
    return choice - 1;
}

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int getUserGuess(int min, int max) {
    int guess;
    while (true) {
        printColored("Ваша догадка: ", CYAN);
        cin >> guess;

        if (cin.fail()) {
            clearInputBuffer();
            printColored("Ошибка! Вводите только числа.\n", RED);
            continue;
        }

        if (guess < min || guess > max) {
            printColored("Число должно быть в диапазоне от " + to_string(min) + " до " + to_string(max) + "!\n", YELLOW);
            continue;
        }

        return guess;
    }
}

bool checkGuess(int guess, int targetNumber) {
    if (guess < targetNumber) {
        printColored("Загаданное число больше.\n", BLUE);
        return false;
    }
    else if (guess > targetNumber) {
        printColored("Загаданное число меньше.\n", BLUE);
        return false;
    }
    return true;
}

void playGame() {
    int difficulty = selectDifficulty();
    int min = levels[difficulty].min;
    int max = levels[difficulty].max;

    srand(static_cast<unsigned int>(time(nullptr)));
    const int secretNumber = generateRandomNumber(min, max);
    int attempts = 0;
    int guess = 0;

    printColored("\nЯ загадал число от " + to_string(min) + " до " + to_string(max) + ". Попробуйте угадать!\n", levels[difficulty].color);

    while (guess != secretNumber) {
        guess = getUserGuess(min, max);
        attempts++;

        if (checkGuess(guess, secretNumber)) {
            break;
        }
    }

    printColored("\nПоздравляю! Вы угадали число " + to_string(secretNumber) + " за " + to_string(attempts) + " попыток.\n", BRIGHT_GREEN);
}

void printWelcomeMessage() {
    printColored("=== Игра Угадай число ===\n", BRIGHT_CYAN);
    printColored("Версия 2.0 с уровнями сложности\n\n", YELLOW);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    printWelcomeMessage();

    do {
        playGame();
    } while (askToPlayAgain());

    printColored("\nСпасибо за игру!\n", BRIGHT_WHITE);
    return 0;
}