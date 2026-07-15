#include <iostream>
using namespace std;

/*Write a program to calculate the compound interest on an amount of money at a given interest rate, for a
number of years. After inputting an amount of Rands, an interest rate and a number of years to invest the
money, the program must calculate and display the amount plus compound interest after each year*/

int main(){
    //variables decleared
    float intRate, amount, totalAmount;
    int years;

    //prompt the user for input.
    //get the amount in rands
    cout << "Enter an amount in rands: ";
    cin >> amount;

    //get the int rate
    cout << "Enter the interest rate: ";
    cin >> intRate;

    //get number of years
    cout << "Enter amount of years: ";
    cin >> years;

    //loop through the years while adding interest rate
    for(int i = 1; i <= years; i++){

        amount += amount * intRate/100;

        cout << "The total amount of compound interest after " << i << " years at a interest rate of " << intRate << " is: " << amount << endl;
        
    }

}