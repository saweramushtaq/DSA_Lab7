#pragma once

#include <string>

namespace Library {
class DoublyLinkedList;

namespace Display {

void ShowMenu();
void PrintMessage(const std::string& message);
void PrintCurrent(const DoublyLinkedList& session);
void PrintForward(const DoublyLinkedList& session);
void PrintBackward(const DoublyLinkedList& session);

}
}
