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

    // Get the year for which user wants to records his/her transacations.
    string user_year;
    cout << "Please enter the year for which you want to records the transactions: ";
    cin >> user_year;

    // Get the month for which user wants to record his/her transactions.
    string user_month;
    cout << "Please enter the name of the month for which you want to record the transactions: ";
    cin >> user_month;          

    // Initialize the 'User' object and print out the total balance.
    User user(user_name, user_year, user_month);
    int total = user.get_balance();
    #ifdef generate_file_name // Test if the correct file name was generated.
    cout << "This is the generated file path: " << user.get_record_name() << endl;
    #endif
    cout << "\nYour total balance is $" << total << endl;

    // User interface.
    string user_input;
    string user_value;
    while (1) {
        cout << "\nPlease enter the desired operation to perform." << endl;
        cout << " '+[value]' to record earnings." << endl;
        cout << " '-[value]' to record spendings." << endl;
        cout << " 'x' to exit the program.\n" << endl;
        cin >> user_input;
        user_value = user_input.substr(1);
        
        if (user_input[0] == '+') {
            user.add_gain(user_value);
            cout << "'+ $" << stoi(user_value) << "' was successfully added to your file." << endl;
        } else if (user_input[0]  == '-') {
            user.add_loss(user_value);
            cout << "'- $" << stoi(user_value) << "' was successfully added to your file." << endl;
        } else if (user_input[0] == 'x') {
            cout << "Exited." << endl;
            exit(0);
        } else {
            cout << "ERROR: invalid input." << endl;
        }
        total = user.get_balance();
        cout << "\nYour total balance is $" << total << endl;
    }
    return 0;
}