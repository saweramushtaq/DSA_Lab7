#include "Input.h"

#include <iostream>
#include <limits>

namespace Library {
namespace Input {

bool ReadInteger(const std::string& prompt, int& value) {
    while (true) {
        std::cout << prompt;
        if (std::cin >> value)
            return true;

        if (std::cin.eof())
            return false;

        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
        std::cout << "Invalid input. Enter a whole number.\n";
    }
}

bool ReadBook(int& bookID, std::string& title) {
    if (!ReadInteger("Enter Book ID: ", bookID))
        return false;

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
    );
    std::cout << "Enter Book Title: ";
    return static_cast<bool>(std::getline(std::cin, title));
}

}
}
