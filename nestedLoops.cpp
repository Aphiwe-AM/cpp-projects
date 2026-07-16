#include <iostream>
using namespace std;
#include <cmath>

/*Write a program that calculates the value of y in the equation y = x3 − 3x + 1, for various series of values
of x. The program must input a list of start and end values for x, and for each value of x from the start to
the end value, it must calculate the values of y. For example, if the start value is 10 and the end value is 20,
it should calculate y for each value of x from 10 to 20. For each value of x, the calculated value of y should
be displayed together with x on a separate line.
Pairs of start and end values should be input until both are 0.*/

int main(){
    // declear veriables 
    int x, y, start, end;

    //prompt the user for input
    cout << "Please enter starting (x): ";
    cin >> start;

    cout << "Please enter end (x): ";
    cin >> end;

    //start looping and inputing each value of x
        while(start != 0 && end != 0)
        {
            for(start; start <= end; start++){
                y = pow(start,3) - 3 * 1 + 1;
                
                //print pairs on screen
                cout << "x: " << start << " y: " << y << endl;
                
            }
            cout << "Please enter starting (x): ";
            cin >> start;

            cout << "Please enter end (x): ";
            cin >> end;
        }
        return 0
    
}