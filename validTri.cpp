#include <iostream>
using namespace std;

/*For every triangle, the sum of (the lengths of) any two sides is greater than the third side. This fact can be
used to test whether three numbers represent the valid sides of a triangle. write a program that inputs three 
numbers and calls a function to check whether they represent the sides of a triangle. Hint: You’ll find it useful 
to write an additional boolean function to test whether the sum of two values is greater than a third.*/

// Function declearations
bool isValid(int value1, int value2, int value3);

int main(){
    //variables used
    int value1, value2, value3;

    //prompt the user for input.
    cout << "Enter first value: ";
    cin >> value1;

    cout << "Enter second value: ";
    cin >> value2;
    
    cout << "Enter thrid value: ";
    cin >> value3;

    //use fuction to check if values form a true triangle.
    if(isValid(value1, value2, value3) == true){
        cout << "This is a valid triangle.";
    }else{
        cout << "This is not a valid trianglr :/.";
    }
    return 0;
}

bool isValid(int value1, int value2, int value3){
    if(value1 + value2 > value3){
        return 1;
    }else{
        return 0;
    }
}