#include <iostream>
#include <iomanip>
using namespace std;

/*Write a program that inputs and processes transactions on a banking account. The types of transactions are
deposit, balance enquiry and withdrawal. Every time a transaction is performed, a fee should be charged
(and subtracted from the balance) as follows: R1.00 per deposit, R0.50 per balance enquiry and R1.50
per withdrawal. However, if the balance is negative after a withdrawal (i.e. the account is overdrawn) the
withdrawal fee should be R5.00. At the end of the list of transactions (for a month, say), the program should
display all the transactions, the total of all the fees charged and the closing balance of the account.*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//create bank account class
class account{
        float balance = 0;
        float account[50];
        int noTransactions = 0;
        bool overdrawn = false;
        float withdrawFee = 1.50;
        float depositFee = 1.00;

    public:
    // getter for balance
    float getBalance(){ 
        balance -= 0.50;
        return balance;
    }
    //deposit method 
    float deposit(float deposit){
        //restrictions
        if(deposit < 0){
            cout << "please enter a positve amount, Transaction faild!";
            return balance;
        }else{
            //update deposit
            balance += deposit - depositFee;
            //update account log
            account[noTransactions] = deposit;
            noTransactions++;

            return balance;
        }
    }
    

    //withdrawl method

    float withdraw(float withdraw){
        //conditions for withdrawls

        if(withdraw < 0){
            //output error
            cout << "pleses enter a positive amount, transaction faild!";

            return balance;

        }else{
            //update 
            balance -= withdraw + withdrawFee;
            //update transaction log
            account[noTransactions] = -withdraw;
            noTransactions++;
            }
        //check if account is overdrawn
        if(balance < 0){
            overdrawn = true;
            withdrawFee = 5.00;
        }else{
            overdrawn == false;
        }
        return balance;
    }
    void getTotaltrans(){
        int size = sizeof(account)/sizeof(account[0]);
        int totaltrans = size - (size - noTransactions); 

        for(int i = 0; i < noTransactions; i++ ){
            cout << account[i] << "; ";

        }

    }

    //total fees method
    float getAccountTotal(){
        float total;
        for(int i = 0; i < noTransactions; i++){
            total += account[i];
        }
        return total;
    }
    

};
int main(){

    //variables
    float withdraw, deposit;
    //create an account
    account personal;
    //prompt the user for input
    cout << "Enter type of transaction (w)ithdrawl,  (d)eposit, (b)alance and e(x)it";
    char transaction;
   do{
    //get type of transaction
    cout << ": ";
    cin >> transaction;
    //check user input
    if(transaction != 'w' && transaction != 'b' && transaction != 'x' && transaction != 'd'){
        cout <<"Transaction faild! Please enter a vaild option 'w'= withdraws 'b' = to check balance 'd'= for deposits. " << endl;
        break;
    }

    //perform user request
    if(transaction == 'w'){
        cout << "W: ";
        cin >> withdraw;
        personal.withdraw(withdraw);
    }else if(transaction == 'd'){
        cout << "D: ";
        cin >> deposit;
        personal.deposit(deposit);
    }else{

        cout<<"B: Your balance is: " << personal.getBalance() << endl;
    }

   }while(transaction != 'x');
   
   // display the total transactions
   cout << "Total transactions: ";
   personal.getTotaltrans();
   //total balance
   cout << "Total balance: " << personal.getAccountTotal();
}