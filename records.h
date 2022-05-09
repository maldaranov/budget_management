#include <iostream>
#include <string>
#include <fstream>

class User {
private:
    std::string name;
    std::string record_name;
    int balance;
    void generate_record_name();
    std::fstream fp;
public: 
    User(std::string name_in);
    std::string get_name();
    std::string get_record_name();
};