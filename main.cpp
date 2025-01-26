#include <iostream>
#include <vector> // Для использования std::vector
#include <cstdlib> // Для ANSI escape-кодов

void printBanner() {
    // ANSI escape-коды для цвета
    const char* GREEN = "\033[1;32m";
    const char* RED = "\033[1;31m";
    const char* RESET = "\033[0m";

    // Логотип ASCII-арт
    std::vector<std::string> LOGO = {
        "\n\n\n",
"      |\\      _,,,---,,_",
"ZZZzz /,`.-'`'    -.  ;-;;,_",
"     |,4-  ) )-,_. ,\\ (  `'-'",
"    '---''(_/--'  `-'\\_)\033[1;31m meowk1r1 software\n\033[0m",
"\033[33mMEOWRT"
    };

    // Вывод логотипа
    std::cout << GREEN;
    for (const auto& line : LOGO) {
        std::cout << line << std::endl;
    }
    std::cout << RESET;

    // Текст
    std::cout << GREEN << "meow, good day!" << RESET << std::endl;
}

int main() {
    printBanner();
    return 0;
}
