#include <iostream>
using namespace std;
/*Write a program that does the following:
Inputs 10 integers into an array.
Inputs an integer and reports whether it appears in the array or not.
Determines what the smallest element in the array is and displays it.
Reverses the order of the elements in the array (the first element will be in the last position, the second
element in the penultimate position, etc.) and displays the resulting array.*/

//function declearation
int isSmallest(int array[]);
void reverseArray(int array[], int size);

int main(){
    //variables
    int array[10], valueCheck, smallestNum;

    //prompt the user
    cout << "please input 10 integers: " << endl;

    //Get 10 integers from the user
    for(int i = 0; i < 10; i++){
        cout << i + 1 << ": ";
        cin >> array[i];
    }
    //check if int is in the array
    cout << "Enter an integer to check: ";
    cin >> valueCheck;

    for( int i = 0; i < 10; i++){
        //loop through and check if its in the array
        if(array[i] == valueCheck){
            cout << "Number is in the array." << endl;
            break;
        }else{
            cout << "Number is not in the array" << endl;
            break;
        }


    }
    //check for the smallest value in the array.
        smallestNum = isSmallest(array); 
        cout << "The smallest number in the array is: " << smallestNum << endl;
}
// function to find the smallest number
int isSmallest(int array[]){
    int smallest_num = array[0];
    for(int i = 0; i < 10; i++){
        if(array[i] < smallest_num){
            return smallest_num = array[i];
        }

    }
    //print reversed array
    reverseArray(array, 10);
}

void reverseArray(int array[], int size){
    int reversedArray[10];
    int index = 0;
    for (int i = size - 1; i > size; i--){
        reversedArray[index] = array[i];

        cout << reversedArray[index];
        index++;
    }
    
}