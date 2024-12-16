#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

// Функция для удаления заданного символа из текста
void removeChar(char* text, char toRemove) {
    int length = strlen(text);
    int index = 0;

    for (int i = 0; i < length; ++i) {
        if (text[i] != toRemove) {
            text[index++] = text[i];
        }
    }

    text[index] = '\0'; // Завершаем новую строку
}

// Задание 2.6: Удаление указанного символа из текста
void task2_6() {
    cout << "\n=== Задание 2.6 ===\n";

    char text[101];
    cout << "Введите текст (максимум 100 символов): ";
    cin.getline(text, 101);

    char toRemove;
    cout << "Введите символ для удаления: ";
    cin >> toRemove;

    // Удаляем символ из текста
    removeChar(text, toRemove);

    cout << "Текст после удаления символа: " << text << endl;
}

int main() {
    task2_6();
    return 0;
}
