#include <iostream>
#include <utility>
using namespace std;

/*Write a program that finds the greatest element in an array and swaps this element with the first element
of the array. Display the array before and after it has been changed.*/

int main(){
    //variables
    int highestNum = 0;
    int highestindex;

    //create the array
    int array[9] = {10, 3, 56, 0, 5, 44, 99, 76, 1};

    //fing the highest value in the array
    for(int i = 0; i <= sizeof(array)/sizeof(array[0]) - 1; i++){
    cout << array[i] << " " ;

    //find highest number.
    if(array[i] > highestNum){
        highestNum = array[i];
        highestindex = i;
    }
    }
     cout << endl;

    // replace the highest number with the  first indext
     swap(array[highestindex], array[0]);

    //print array
     for( int i = 0;i <= sizeof(array)/sizeof(array[0]) - 1; i++){
        cout << array[i] << " ";
     }
    
     return 0;
}