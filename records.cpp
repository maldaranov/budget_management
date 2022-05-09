#include "records.h"

User::User(std::string name_in) {
    name = name_in;
    generate_record_name();
    balance = 0;
    fp.open(record_name, std::ios::out | std::ios::out);
    if (!fp.is_open()) {
        std::cout << "ERROR: failed to open/create a file." << std::endl;
    } else {
        fp << "Transaction history of " << name << std::endl;
    }
}
void User::generate_record_name() {
    std::string result = "records/";
    // Convert all characters in the name to lowercase.
    // Convert all spaces to underscore.
    char c;
    for (int i = 0; i < name.length(); i++) {
        if (isspace(name[i])) {
            c = '_';
        } else if (isupper(name[i])) {
            c = tolower(name[i]);
        } else {
            c = name[i];
        }
        result.push_back(c);
    }
    result.append(".txt");
    record_name = result;

}
std::string User::get_name() {
    return name;
}
std::string User::get_record_name() {
    return record_name;
}