#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Функция для нахождения следующего слова в строке
char* getNextWord(char* str, int& start) {
    while (str[start] == ' ' && str[start] != '\0') start++;
    if (str[start] == '\0') return nullptr;

    int wordStart = start;
    while (str[start] != ' ' && str[start] != '\0') start++;

    int wordLength = start - wordStart;
    char* word = new char[wordLength + 1];
    for (int i = 0; i < wordLength; ++i) {
        word[i] = str[wordStart + i];
    }
    word[wordLength] = '\0';
    return word;
}

// Функция для изменения местами двух символов
void swapChars(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

// Функция для обмена четных и нечетных слов в строке
void swapOddEvenWords(char* text) {
    int start = 0;
    char* words[100]; // Хранилище для слов (до 100 слов)
    int wordCount = 0;

    // Извлекаем слова из строки
    char* word;
    while ((word = getNextWord(text, start)) != nullptr) {
        words[wordCount++] = word;
    }

    // Меняем местами четные и нечетные слова
    for (int i = 0; i < wordCount - 1; i += 2) {
        int len1 = strlen(words[i]);
        int len2 = strlen(words[i + 1]);
        int minLen = len1 < len2 ? len1 : len2;

        for (int j = 0; j < minLen; ++j) {
            swapChars(words[i][j], words[i + 1][j]);
        }
    }

    // Собираем строку обратно
    int currentIndex = 0;
    for (int i = 0; i < wordCount; ++i) {
        for (int j = 0; j < strlen(words[i]); ++j) {
            text[currentIndex++] = words[i][j];
        }
        if (i < wordCount - 1) {
            text[currentIndex++] = ' ';
        }
        delete[] words[i];
    }
    text[currentIndex] = '\0';
}

// Задание 3.6: Перестановка четных и нечетных слов
void task3_6() {
    cout << "\n=== Задание 3.6 ===\n";

    char text[101];
    cout << "Введите строку (максимум 100 символов): ";
    cin.getline(text, 101);

    // Проверяем наличие хотя бы двух слов
    int spaceCount = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] == ' ') spaceCount++;
    }
    if (spaceCount < 1) {
        cout << "Ошибка: строка должна содержать два или более слов." << endl;
        return;
    }

    // Меняем местами четные и нечетные слова
    swapOddEvenWords(text);

    cout << "Результат: " << text << endl;
}

int main() {
    task3_6();
    return 0;
}
