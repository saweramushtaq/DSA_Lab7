#pragma once

#include <string>

namespace Library {
namespace Input {

bool ReadInteger(const std::string& prompt, int& value);
bool ReadBook(int& bookID, std::string& title);

}
}
