#include <string>
#include "../../include/utility.h"
#include "../../../model/include/playerModel.h"

std::string utility::operator+(std::string a, id b) {
    return a + std::to_string(int(b));
}