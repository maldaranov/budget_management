#include "records.h"
using namespace std;
#define generate_file_name

int main () {
    // Greetings message.
    cout << "Hello, user! This program will help you track your earnings, spendings, and total balance." << endl;

    // Get user's full name.
    string user_name;
    cout << "Please enter your full name: ";
    getline(cin, user_name);
    
    // Initialize the 'User' object.
    User user(user_name);
    #ifdef generate_file_name // Test if the correct file name was generated.
    cout << "This is the generated file name: " << user.get_record_name() << endl;
    #endif

    // User interface.
    char c;
    while (1) {
        cout << "\nPlease enter the desired operation to perform." << endl;
        cout << " '+' to records earnings." << endl;
        cout << " '-' to records spendings." << endl;
        cout << " 'x' to exit the program." << endl;
        cin >> c;
        cout << endl;

        if (c == '+') {
            cout << "Earnings." << endl;
        } else if (c == '-') {
            cout << "Spendings." << endl;
        } else if (c == 'x') {
            cout << "Exited." << endl;
            exit(0);
        } else {
            cout << "ERROR: invalid input." << endl;
        }
    }

    return 0;
}