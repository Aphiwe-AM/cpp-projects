#include <iostream>
using namespace std;

int main(){
    //get the time periods
    int time1Sec, time1Min, time2Sec, time2Min;
    cout << "First time period: ";
    cin >> time1Min >> time1Sec;
    
    cout << "Second time period: ";
    cin >> time2Min >> time2Sec;

// calculate the time with out the convertion 
    int rawMin = time1Min + time2Min;
    int rawSec = time1Sec + time2Sec;

// convert the seconds into actual time

    int realSec = rawSec % 60;
    // calculate number of seconds elapsed into min
    int secLapsed = (rawSec - realSec)/60;

// convert the seconds into actual time
    int realMin = (rawMin % 12) + secLapsed;

    cout << "The current time: " << realMin  << " minutes " << realSec  << " seconds "  << endl;
    return 0;

}