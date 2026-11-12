#include <iostream>
using namespace std;

int main(){
     
    const int TAX_RATE = 0.40;

    float salary, tax;
    
    //prompt the user for  there salary
    cout << "please input your salary: ";
    cin >> salary;
    
    cout << endl; // add line for readability
    
    //cout << "the amount of tax owed is ";

    // check if salary is above 70000
    if(salary > 70000.00){
        tax = salary * 0.40;
    }
    else
    {
        tax = salary * 0.30;
    }
    
    //ouput the amount of income tax owed by the user
cout << "the amount of tax owed is ";
cout << tax;

  return 0;
}