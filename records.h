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
    void update_balance();
    std::fstream fp;
public: 
    User(std::string, std::string, std::string);
    std::string get_name();
    std::string get_year();
    std::string get_month();
    std::string get_record_name();
    void add_gain(std::string);
    void add_loss(std::string);
    int get_balance();
};