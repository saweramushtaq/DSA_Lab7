#include "Display.h"
#include "DoublyLinkedList.h"
#include "Input.h"

#include <iostream>
#include <string>

int main() {
    Library::DoublyLinkedList session;
    session.InsertRight(101, "Data Structures");
    session.InsertRight(102, "Database Systems");
    session.InsertRight(103, "Operating Systems");

    int choice;
    do {
        Library::Display::ShowMenu();
        if (!Library::Input::ReadInteger("Enter your choice: ", choice))
            break;

        int bookID;
        std::string title;

        switch (choice) {
        case 1:
            Library::Display::PrintCurrent(session);
            break;

        case 2:
            session.Next();
            Library::Display::PrintCurrent(session);
            break;

        case 3:
            session.Previous();
            Library::Display::PrintCurrent(session);
            break;

        case 4:
            if (!Library::Input::ReadBook(bookID, title))
                return 0;
            session.InsertRight(bookID, title);
            Library::Display::PrintMessage(
                "Book inserted at the end of the session."
            );
            break;

        case 5:
            if (!Library::Input::ReadBook(bookID, title))
                return 0;
            session.InsertAfterCurrent(bookID, title);
            Library::Display::PrintMessage(
                "Book inserted after the current book."
            );
            break;

        case 6: {
            Library::BookNode* removed = session.RemoveCurrent();
            if (removed != nullptr) {
                std::cout << "Removed book: " << removed->bookID
                          << " - " << removed->title << '\n';
                delete removed;
            } else {
                Library::Display::PrintMessage(
                    "The borrowing session is empty."
                );
            }
            break;
        }

        case 7:
            Library::Display::PrintForward(session);
            break;

        case 8:
            Library::Display::PrintBackward(session);
            break;

        case 9:
            Library::Display::PrintMessage("Exiting program.");
            break;

        default:
            Library::Display::PrintMessage(
                "Invalid choice. Enter a number from 1 to 9."
            );
        }
    } while (choice != 9);

    return 0;
}
