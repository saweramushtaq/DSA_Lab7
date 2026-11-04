#pragma once

#include <string>

namespace Library {

struct BookNode {
    int bookID;
    std::string title;
    BookNode* left;
    BookNode* right;

    BookNode(int id, const std::string& name)
        : bookID(id), title(name), left(nullptr), right(nullptr) {}
};

}
