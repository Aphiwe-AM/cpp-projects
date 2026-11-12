#include <iostream>
using namespace std;

int main(){

    const float STORE_DISCOUNT = 0.10;
    float cost, total_discount;
    int discount, sp_discount;

    //prompt the user to input item amount
    cout << "Item amount: ";
    cin >> cost;
    //prompt for a special discount
    cout << "Enter special discount(%): ";
    cin >> sp_discount;

    cout << endl; // blank space 
    
    //calculate the total discount
    if(cost <= 200.00){
        total_discount = cost * sp_discount / 100;
         discount = sp_discount;
    }
    else{
        total_discount = cost * STORE_DISCOUNT;
        discount =  STORE_DISCOUNT * 100;
    }
    
    //print out the statement/recipt
    
    cout << "=========" << endl;
    cout << "was: " << cost << endl;
    cout << "discount: " << discount << '%'<< endl;
    cout << "Now: " << cost - total_discount << endl;
    cout << "==========";

    return 0;
}