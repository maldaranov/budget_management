#include "records.h"
using namespace std;
#define TEST1

int main () {
    // Greetings message.
    cout << "Hello, user! This program will help you track your earnings, spendings, and total balance." << endl;

    // Get user's full name.
    string user_name;
    cout << "Please enter your full name: ";
    getline(cin, user_name);
    
    // Initialize the 'User' object.
    User user(user_name);
    #ifdef TEST1
    cout << "This is the generated file name: " << user.get_record_name() << endl;
    #endif

    return 0;
}