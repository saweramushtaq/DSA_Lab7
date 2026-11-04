#include "DoublyLinkedList.h"

namespace Library {

DoublyLinkedList::DoublyLinkedList()
    : head(nullptr), tail(nullptr), current(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    BookNode* node = head;
    while (node != nullptr) {
        BookNode* next = node->right;
        delete node;
        node = next;
    }
}

void DoublyLinkedList::InsertRight(int bookID, const std::string& title) {
    BookNode* node = new BookNode(bookID, title);
    node->left = tail;

    if (tail != nullptr)
        tail->right = node;
    else
        head = node;

    tail = node;
    if (current == nullptr)
        current = node;
}

void DoublyLinkedList::Next() {
    if (current != nullptr && current->right != nullptr)
        current = current->right;
}

void DoublyLinkedList::Previous() {
    if (current != nullptr && current->left != nullptr)
        current = current->left;
}

void DoublyLinkedList::InsertAfterCurrent(
    int bookID,
    const std::string& title
) {
    if (current == nullptr) {
        InsertRight(bookID, title);
        return;
    }

    BookNode* node = new BookNode(bookID, title);
    node->left = current;
    node->right = current->right;

    if (current->right != nullptr)
        current->right->left = node;
    else
        tail = node;

    current->right = node;
}

BookNode* DoublyLinkedList::RemoveCurrent() {
    if (current == nullptr)
        return nullptr;

    BookNode* removed = current;
    BookNode* previous = current->left;
    BookNode* next = current->right;

    if (previous != nullptr)
        previous->right = next;
    else
        head = next;

    if (next != nullptr)
        next->left = previous;
    else
        tail = previous;

    current = (next != nullptr) ? next : previous;
    removed->left = nullptr;
    removed->right = nullptr;
    return removed;
}

const BookNode* DoublyLinkedList::GetHead() const {
    return head;
}

const BookNode* DoublyLinkedList::GetTail() const {
    return tail;
}

const BookNode* DoublyLinkedList::GetCurrent() const {
    return current;
}

}
