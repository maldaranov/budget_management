#include "records.h"

User::User(std::string name_in, std::string month_in) {
    name = name_in;
    generate_record_name(month_in);
    balance = 0;
    num_transactions = 0;
    fp.open(record_name, std::ios::out | std::ios::out);
    if (!fp.is_open()) {
        std::cout << "ERROR: failed to open/create a file." << std::endl;
    } else {
        fp << "Transaction history of " << name << "." << std::endl;
        fp << "Number of transactions: " << num_transactions << "." << std::endl;
    }
}
void User::generate_record_name(std::string month) {
    std::string result = "records/";

    // Convert any uppercase characters in the name to lowercase and all spaces to underscore.
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
    result.push_back('_');
    // Convert any uppercase characters in the month to lowercase.
    for (int i = 0; i < month.length(); i++) {
        if (isupper(month[i])) {
            c = tolower(month[i]);
        } else {
            c = month[i];
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
