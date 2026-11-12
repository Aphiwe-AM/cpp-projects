#include <iostream>
using namespace std;
 
// Write a program that displays a times table for any number.

int main(){
    //variables 
    int number, answer;

    //prompt the user for a number
    cout << "Enter a number: ";
    cin >> number;

    //create a loop to eterate and create the times table
    for(int i = 1; i <= 12; i++){
        answer = number * i;
        cout << number << "x" << i << " = " << answer << endl;
    }
    return 0;
}