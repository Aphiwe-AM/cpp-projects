#include <iostream>
using namespace std;
/*The number of people that live in a city increases by 10% every year. Write a program that inputs a value
for the current population, and then uses a while loop to determine how many years it will take before the
population exceeds 1 000 000.*/
int main(){
    // variable declearation
    const double INCREASE_RATE = 0.10;
    int totalPopulation;
    int years = 1;

    //get current information from the user.
    cout << "Please enter the current population of the city: ";
    cin >> totalPopulation;
    //set totaPopulation to current population;
    while(totalPopulation <= 1000000){
        totalPopulation += totalPopulation * INCREASE_RATE;
        years++;
        cout << totalPopulation << endl;
    }
    cout << "It will take the city " << years << " years to exceed 1000000";
}