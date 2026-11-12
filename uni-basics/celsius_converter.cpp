#include <iostream>
using namespace std;

int main(){
    int degFahren;
    cout << "Degrees in fahrenhiet: ";
    cin >> degFahren;
    cout << "Degrees in celsius: " <<  5*(degFahren - 32)/9;
}