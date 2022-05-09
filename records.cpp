#include "records.h"

User::User(std::string name_in) {
    name = name_in;
}

std::string User::get_name() {
    return name;
}