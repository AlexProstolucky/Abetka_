#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <vector>
#include <windows.h>

std::vector<char> ukrainianAlphabet = {
    'А', 'Б', 'В', 'Г', 'Ґ', 'Д', 'Е', 'Є', 'Ж', 'З',
    'И', 'І', 'Ї', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П',
    'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ',
    'Ь', 'Ю', 'Я'
};

void printToScreen() {
    std::cout << "Українська абетка: ";
    for (char letter : ukrainianAlphabet) {
        std::cout << letter;
        if (letter != ukrainianAlphabet.back()) {
            std::cout << ',';
        }
    }
    std::cout << std::endl;
}

void writeToFile() {
    std::ofstream file("ukrainian_alphabet.txt");
    if (file.is_open()) {
        file << "Українська абетка: ";
        for (char letter : ukrainianAlphabet) {
            file << letter;
            if (letter != ukrainianAlphabet.back()) {
                file << ',';
            }
        }
        file << std::endl;
        file.close();
        std::cout << "\nУкраїнська абетка була записана в файл 'ukrainian_alphabet.txt'" << std::endl;
    }
    else {
        std::cerr << "Помилка при відкритті файлу для запису." << std::endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    std::thread screenThread(printToScreen);
    std::thread fileThread(writeToFile);

    screenThread.join();
    fileThread.join();

    return 0;
}
