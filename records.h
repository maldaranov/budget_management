#include <iostream>
#include <string>

class User {
private:
    std::string name;
    std::string record_name;
    void generate_record_name();
public: 
    User(std::string name_in);
    std::string get_name();
    std::string get_record_name();
};