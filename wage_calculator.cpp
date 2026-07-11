#include <iostream>
using  namespace std;

int main() {
    //variable declearations
    const double AFTERNOON_RATE = 32.40;
    const int EVENING_RATE = 44;
    int starting_time, finishing_time;
    double wage;

    // get inputs from the user
    cout << "Enter your starting time: ";
    cin >> starting_time;

    cout << "Enter your finishing time: ";
    cin >> finishing_time;

    //calculate wages for the afternoon
    if(finishing_time <= 6){
        wage = (finishing_time - starting_time) * AFTERNOON_RATE;
    }
    if(starting_time < 6 && finishing_time > 6){
        wage = (6 - starting_time) * AFTERNOON_RATE + (finishing_time - 6) * EVENING_RATE;
    }
    if(finishing_time >= 6){
        wage = (finishing_time - starting_time) * EVENING_RATE;
    }

    cout << "The payment is " << wage << endl;
    
}