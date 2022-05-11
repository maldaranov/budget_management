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

    // Initialize the 'User' object.
    User user(user_name, user_year, user_month);
    #ifdef generate_file_name // Test if the correct file name was generated.
    cout << "This is the generated file path: " << user.get_record_name() << endl;
    #endif

    // User interface.
    char c;
    while (1) {
        cout << "\nPlease enter the desired operation to perform." << endl;
        cout << " '+' to record earnings." << endl;
        cout << " '-' to record spendings." << endl;
        cout << " '=' to see balance." << endl;
        cout << " 'x' to exit the program.\n" << endl;
        cin >> c;

        string sum;
        int total = user.get_balance();
        if (c == '+') {
            cout << "Please enter the amount to add to your account: " << endl;
            cin >> sum;
            user.add_gain(sum);
            cout << "'+ $" << sum << "' was successfully added to your file." << endl;
        } else if (c == '-') {
            cout << "Please enter the amount to subtract from your account: " << endl;
            cin >> sum;
            user.add_loss(sum);
            cout << "'- $" << sum << "' was successfully added to your file." << endl;
        } else if (c == '=') {
            cout << "Your total balance is $" << total << endl;
        } else if (c == 'x') {
            cout << "Exited." << endl;
            exit(0);
        } else {
            cout << "ERROR: invalid input." << endl;
        }
    }

    return 0;
}