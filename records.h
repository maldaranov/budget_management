#include <iostream>
#include <string>

class User {
private:
    std::string name;
public: 
    User(std::string name_in);
    std::string get_name();
};