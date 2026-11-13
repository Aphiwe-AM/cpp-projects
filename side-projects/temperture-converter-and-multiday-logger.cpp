/*
• The Goal: Build a tool that lets a user log temperatures over a user-defined number of days, 
converts them between Celsius and Fahrenheit, and flags extreme weather warnings.
• What it should do:
	• Ask the user how many days they want to record.
	• Run a loop to request the temperature for each day sequentially.
	• Convert the entered temperature to the alternative scale.
	• Use if/else statements to alert the user if a day's temperature crosses custom 
    "freezing" or "heatwave" thresholds.
*/

#include <iostream>
#include <string>

int main(){
    //variables used
    int days_recorded;

     
	std::cout << "How many days  do you want to record: ";
    std::cin >> days_recorded;

    for(int day = 0; day < days_recorded; day++){
        std::cout << day;
    }


	
}