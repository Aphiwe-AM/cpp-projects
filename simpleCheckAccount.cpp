#include <iostream>
using namespace std;
/*Write a program that maintains a simple cheque account. It first asks for a balance and then for a sequence
of transactions. Deposits are given as positive values and cheques written as negative values. After each
transaction, the program should display the new balance. The transactions end when the value 0 is entered.*/

int main(){
    //variables decleared
    double balance;
    double value;

    //set an while loop that will terminate when user inters 0
    do{
        cout << "Please input cheque(-) or deposit(+) value (to terminate the program enter 0): ";
        cin >> value;
        
        balance += value;

    }while(value != 0);

    cout << "The account balance is: " << balance;
    return 0;
   
}