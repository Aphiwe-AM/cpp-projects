#include <iostream>
using namespace std;

/*Write a program that calculates and displays the sums of all the odd numbers up to a number n. The user
must supply a value for n, and the program must display all the partial sums up to n (including n if n is
odd).*/

int main(){
// variables used 
    int n; 
    int oddSum = 0;
    

    //get number n from the user
    cout << "please enter any number: ";
    cin >> n;

    //loop through n numbers
    for(int i = 1; i <= n; i++){
        //find all odd numbers
        if(i % 2 != 0){
            //display the sum of all odd numbers
            cout << oddSum << '+' << i << endl;

            //sum the  odd numbers
            oddSum += i; 
            
        }
        
    }
     
        cout << "The total sum of odd numbers is: "<< oddSum;
}