#pragma once

#include "BookNode.h"
#include <string>

namespace Library {

class DoublyLinkedList {
private:
    BookNode* head;
    BookNode* tail;
    BookNode* current;

public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
    ~DoublyLinkedList();

    void InsertRight(int bookID, const std::string& title);
    void Next();
    void Previous();
    void InsertAfterCurrent(int bookID, const std::string& title);
    BookNode* RemoveCurrent();

    const BookNode* GetHead() const;
    const BookNode* GetTail() const;
    const BookNode* GetCurrent() const;
};

}
