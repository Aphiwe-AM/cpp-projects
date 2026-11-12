#include <iostream>
using namespace std;

int main( )
{
float amount, rate;
//Input the amount and the interest rate
cout << "Enter an amount in Rands: ";
cin >> amount;
cout << "Enter the interest rate: ";
cin >> rate;
//Set the output format
cout.setf(ios::fixed);
cout.precision(4);
//Calculate and add interest
amount = amount + amount * rate / 100;
cout << "After 1 year the amount will be " << amount << endl;
return 0;
}