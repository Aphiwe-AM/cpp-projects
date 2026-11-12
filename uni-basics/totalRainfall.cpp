#include <iostream>
using namespace std;
/* Write a while loop that inputs the monthly rainfall figures for a year,and calculates andd is plays the total
rainfall (in millimetres)for the year. */
int main(){
    //declear variables used
    float totalRainfall, rainfall;
    int month = 1;
    
    while(month <= 12){
        //get amount of rainfall for that month
        cout << "Please input the total amount of rainfall for month " << month << " (in millimetres): ";
        cin >> rainfall;
        
        //add the total rainfall 
        totalRainfall += rainfall;

        //continue to the next month
        month++;

    }
    cout << "The total rainfall for the year is: " << totalRainfall << " millimetres.";
}