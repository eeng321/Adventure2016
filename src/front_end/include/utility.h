/*
 * Utility namespace for overloaded operations, central location for future utility methods
 */


#ifndef ADVENTURE2016_UTILITY_H
#define ADVENTURE2016_UTILITY_H

#include <string>

typedef int id;

namespace utility {
    std::string operator+(std::string a, id b);
};


#endif //ADVENTURE2016_UTILITY_H
