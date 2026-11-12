#include <iostream>
using namespace std;

/*Write a program, using functions as appropriate, that reads in the number of chirps per minute and then
gives the approximate temperature in both Fahrenheit and Celsius.*/

//function declearations
double chirpsFahenheit(int chirps);
double chirpsCelsius(int chirps);


int main(){
    //variables 
    int numChirps;
    double degFahenheit, degCelsius;

    //prompt the user for input
    cout << "Please enter number of chirps in one minute: ";
    cin >> numChirps;

    //calculate and give the approximate degrees
    degFahenheit = chirpsFahenheit(numChirps);
    degCelsius = chirpsCelsius(numChirps);
    
    cout << "degree fahenheit at " << numChirps << " is: " << degFahenheit << endl;
    cout << "degrees celsius at " << numChirps << " is: " << degCelsius;
}

double chirpsFahenheit(int chirps){
    return (chirps + 160 ) / 4;
}

double chirpsCelsius(int chirps){
    
    return (chirpsFahenheit(chirps) + 32) * 5/9;

}