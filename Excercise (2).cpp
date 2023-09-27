#include <iostream>
#include <string.h>

using namespace std;

class BankAccount{
private:
    string account_number = "", holder_name = "";
    float balance = 0;
public:
    BankAccount(string a_num, string h_nam, float b){
        account_number = a_num;
        holder_name = h_nam;
        balance = b;
    }
    void deposit(float amount){
        balance += amount;
    }
    void withdrawMoney(float amount){
        balance -= amount;
    }
    float checkBalance(){
        return balance;
    }
};

int main()
{
    string acc_num = "", hold_name = "", dep = "";
    cout << "Create new account\n";
    while (true){
        bool fail = false;
        cout << "Please enter account number: ";
        cin >> acc_num;
        for (int i = 0; acc_num[i]; i++){
            if (acc_num[i] < '0' || acc_num[i] > '9'){
                cout << "Invalid input. Account number can only contain number.\n";
                fail = true;
                break;
            }
        }
        if (!fail){
            fail = false;
            break;
        }
    }

    cout << "Please enter holder name: ";
    cin >> hold_name;
    
    while (true){
        bool fail = false;
        cout << "Please enter your deposit: ";
        cin >> dep;
        for (int i = 0; dep[i]; i++){
            if (dep[i] < '0' || dep[i] > '9'){
                cout << "Invalid input. Deposit must be a number.\n";
                fail = true;
                break;
            }
        }
        if (!fail){
            fail = false;
            break;
        }
    }

    BankAccount acc(acc_num, hold_name, stof(dep));
    cout << "Bank account create! Welcome\n";
    
    while (true){
        string option = "";
        bool fail = false;
        cout << "What would you like to do (Press a number from 1 to 3)\n1: Deposit\n2: Withdraw money\n3: Check balance\n";
        cin >> option;
        if (option.length() != 1 || option[0] < '1' || option[0] > '3'){
            cout << "Invalid input. Please try again";
            fail = true;
        }
        if (!fail){
            if (option == "1"){
                string am = "";
                while (true){
                    bool fail1 = false;
                    cout << "How much? ";
                    cin >> am;
                    for (int i = 0; am[i]; i++){
                        if (am[i] < '0' || am[i] > '9'){
                            cout << "Invalid input. Deposit amount must be a number.\n";
                            fail1 = true;
                            break;
                        }
                    }
                    if (!fail1){
                        fail1 = false;
                        break;
                    }
                }
                if (stof(am) < 0){
                    cout << "Invalid amount. Deposit amount must be positive. \n";
                } else{
                    acc.deposit(stof(am));
                    cout << "Balance = " << acc.checkBalance() << "\n";
                }
            }else if (option == "2"){
                string am = "";
                while (true){
                    bool fail1 = false;
                    cout << "How much? ";
                    cin >> am;
                    for (int i = 0; am[i]; i++){
                        if (am[i] < '0' || am[i] > '9'){
                            cout << "Invalid input. Withdraw amount must be a number.\n";
                            fail1 = true;
                            break;
                        }
                    }
                    if (!fail1){
                        fail1 = false;
                        break;
                    }
                }
                if (stof(am) < 0){
                    cout << "Invalid amount. Withdraw amount must be positive. \n";
                }else if (stof(am) > acc.checkBalance()){
                    cout << "Insufficient balance." << "\n";
                } else{
                    acc.withdrawMoney(stof(am));
                    cout << "Balance =  " << acc.checkBalance() << "\n";
                }
            }else if (option == "3"){
                cout << "Balance: " << acc.checkBalance() << "\n";
            }
        } else {
            fail = false;
        }
    }
    return 0;
}
