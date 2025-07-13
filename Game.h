#ifndef GUESS_THE_NUMBER_GAME_H  // ������ �� ���������� ���������
#define GUESS_THE_NUMBER_GAME_H

#include <string>

// ���������
const int MIN_NUMBER = 1;    // ����������� ������������ �����
const int MAX_NUMBER = 100;  // ������������ ������������ �����

// ���������� �������

/// ���������� ��������� ����� � ��������� [min, max]
int generateRandomNumber(int min, int max);

/// ��������� ���� ���� (���������� �����) � ���������� ���������� �������
int playGame(int targetNumber);

/// ������� ����������� � ������� ����
void printWelcomeMessage();

/// ����������� � ������������ ������� � ���������� �
int getUserGuess();

/// ��������� ������� ������������ � ��� ��������� (������/������)
/// ���������� true, ���� ����� �������
bool checkGuess(int guess, int targetNumber);

/// ���������� � ������������, ����� �� �� ������� ��� ���
/// ���������� true, ���� ����� 'y' ��� 'Y'
bool askToPlayAgain();

#endif // GUESS_THE_NUMBER_GAME_H