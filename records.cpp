#include "records.h"

User::User(std::string name_in, std::string year_in, std::string month_in) {
    name = name_in;
    year = year_in;
    month = month_in;
    generate_record_name();
    balance = 0;
    fp.open(record_name, std::ios::in);
    if (fp.is_open()) { // File already exists.
        fp.close();
        update_balance();
        fp.open(record_name, std::ios::app);
    } else { // File doesn't exist, create the file and add the appropriate header.
        fp.close();
        fp.open(record_name, std::ios::out);
        fp << "Transaction history of " << name << " for " << month << " " << year << std::endl;
    }
}
void User::generate_record_name() {
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
    result.push_back('_');
    result.append(year);
    result.append(".txt");
    record_name = result;
}
void User::update_balance() {
    char c;
    std::string result;

    // Open the file for writing at the end.
    fp.open(record_name, std::ios::in | std::ios::ate);

    // Get the length of the file.
    std::streampos size = fp.tellg();

    // Set the stream pointer to the end before the newline.
    fp.seekg(-2 ,std::ios::end);

    fp.get(c);
    std::cout << "TEST: " << c << std::endl;
    if (c == '.') {
        for (int i = 3; i <= size; i++) {
            fp.seekg(-i, std::ios::end);
            fp.get(c);
            if (c == '$') break;
            result = c + result;
        }
        std::cout << result << std::endl;
        balance = stoi(result);
    }
    fp.close();
}
std::string User::get_name() {
    return name;
}
std::string User::get_year() {
    return year;
}
std::string User::get_month() {
    return month;
}
std::string User::get_record_name() {
    return record_name;
}
void User::add_gain(std::string gain_in) {
    balance += stoi(gain_in);
    fp << "+ $" << gain_in << " = $" << balance << "." << std::endl;
}
void User::add_loss(std::string loss_in) {
    balance -= stoi(loss_in);
    fp << "- $" << loss_in << " = $" << balance << "." << std::endl;
}
int User::get_balance() {
    return balance;
}
