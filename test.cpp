#include <iostream>
using namespace std;

int main(){ 
    int x;
    cin >> x;
    while(x != 1){
        if(x % 2 == 1){
            x = x * 3 + 1;
        }
        else{
            x = x / 2;
            cout << x << endl;
        }
    }
}