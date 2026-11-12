#include <iostream>
using namespace std;

int main(){
    int momsAge, yourAge;
    cout << "enter your moms and your age:  ";
    cin >>  momsAge >> yourAge;
    cout << "Your mom was "  << (momsAge - yourAge) << " years old when you were born.";
    return 0;
}
