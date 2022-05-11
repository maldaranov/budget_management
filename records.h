#include <iostream>
#include <string>
#include <fstream>

class User {
private:
    std::string name;
    std::string record_name;
    int num_transactions;
    int balance;
    void generate_record_name(std::string);
    std::fstream fp;
public: 
    User(std::string, std::string);
    std::string get_name();
    std::string get_record_name();
};