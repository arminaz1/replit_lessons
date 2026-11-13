#include <iostream>
#include <string>
#include "get_rating_rank.h"

int get_rating_rank(const std::string& rating) {
    if (rating == "G")     return 1;
    if (rating == "PG")    return 2;
    if (rating == "PG-13") return 3;
    if (rating == "R")     return 4;

    return 0; // Invalid rating
}