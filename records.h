#include <iostream>
#include <string>
#include <fstream>

class User {
private:
    std::string name;
    std::string year;
    std::string month;
    std::string record_name;
    int balance;
    void generate_record_name();
    std::fstream fp;
public: 
    User(std::string, std::string, std::string);
    std::string get_name();
    std::string get_record_name();
};