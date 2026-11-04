#include "Display.h"

#include "BookNode.h"
#include "DoublyLinkedList.h"

#include <iostream>

namespace Library {
namespace Display {

void ShowMenu() {
    std::cout << "\n========================================\n";
    std::cout << "LIBRARY BORROWING SESSION\n";
    std::cout << "========================================\n";
    std::cout << "1. Display Current Book\n";
    std::cout << "2. Move to Next Book\n";
    std::cout << "3. Move to Previous Book\n";
    std::cout << "4. Insert Book at the End\n";
    std::cout << "5. Insert Book After Current Book\n";
    std::cout << "6. Remove Current Book\n";
    std::cout << "7. Display Session from First to Last\n";
    std::cout << "8. Display Session from Last to First\n";
    std::cout << "9. Exit\n";
}

void PrintMessage(const std::string& message) {
    std::cout << message << '\n';
}

void PrintCurrent(const DoublyLinkedList& session) {
    const BookNode* current = session.GetCurrent();
    if (current == nullptr) {
        PrintMessage("The borrowing session is empty.");
        return;
    }

    std::cout << "Current Book: " << current->bookID
              << " - " << current->title << '\n';
}

void PrintForward(const DoublyLinkedList& session) {
    const BookNode* currentBook = session.GetCurrent();
    const BookNode* node = session.GetHead();
    if (node == nullptr) {
        PrintMessage("The borrowing session is empty.");
        return;
    }

    std::cout << "\nBorrowing Session (First to Last):\n";
    while (node != nullptr) {
        std::cout << node->bookID << " - " << node->title;
        if (node == currentBook)
            std::cout << " [CURRENT]";
        std::cout << '\n';
        node = node->right;
    }
}

void PrintBackward(const DoublyLinkedList& session) {
    const BookNode* currentBook = session.GetCurrent();
    const BookNode* node = session.GetTail();
    if (node == nullptr) {
        PrintMessage("The borrowing session is empty.");
        return;
    }

    std::cout << "\nBorrowing Session (Last to First):\n";
    while (node != nullptr) {
        std::cout << node->bookID << " - " << node->title;
        if (node == currentBook)
            std::cout << " [CURRENT]";
        std::cout << '\n';
        node = node->left;
    }
}

}
}
