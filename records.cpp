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
        fp.open(record_name, std::ios::app);
    } else {
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
    fp << "+ $" << gain_in << " = $" << balance << std::endl;
}
void User::add_loss(std::string loss_in) {
    balance -= stoi(loss_in);
    fp << "- $" << loss_in << " = $" << balance << std::endl;
}
int User::get_balance() {
    return balance;
}
