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
    //constant custom temperatures
    const int freezing_c = 0;
    const int freezing_f = 32;
    const int heatwave_c = 32;
    const int heatwave_f = 90;
    //variables used
    int days_recorded;
    float temp{}, temp_converted{};
    char temp_type;

     
	std::cout << "How many days  do you want to record: ";
    std::cin >> days_recorded;
    std::cout << "Enter measurement type fahrenheit (f) or celcius (c): ";
    std::cin >> temp_type;

    for(int day = 1; day < days_recorded + 1; ++day){
    
        std::cout << "Enter temperature for day " << day << ": ";
        std::cin >> temp;

         if(temp_type == 'f'){
             temp_converted = (temp * 1.8) + 32;
             if(temp <= freezing_f){
                std::cout <<"Wear a jacket to day it's freezing." << temp << ".F " << temp_converted << ".C" << std::endl;
             }
             else if (temp >= heatwave_f)
             {
                std::cout << "Stay hydrated and cool today is  a heatwave: " << temp << ".F " << temp_converted << ".C" << std::endl;
             }
             else{
                std::cout << "It's a normal day today: " << temp << ".F " << temp_converted << ".C" << std::endl;
             }
             
         }
         else{

            temp_converted = (temp - 32) * 1.8;
             if(temp <= freezing_c){
                std::cout <<"Wear a jacket to day it's freezing: " << temp_converted << ".F " << temp << ".C" << std::endl;
             }
             else if (temp >= heatwave_c)
             {
                std::cout << "Stay hydrated and cool today is  a heatwave: " << temp_converted << ".F " << temp << ".C" << std::endl;
             }
             else{
                std::cout << "It's a normal day today: " << temp_converted << ".F " << temp << ".C" << std::endl;
             } 
         }

        
    }


	
}