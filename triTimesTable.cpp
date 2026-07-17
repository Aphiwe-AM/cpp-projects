#include <iostream>
using namespace std;

int main(){
    //decleared variables
    int length = 9;

    for(int k = 1; k <= length; k++){
            cout << "  " << k;
         }

        cout << endl;

    //colums
  for (int i  = 1; i <= length; i++){

    cout << i << " ";
    
    
    for (int j = 1; j <= i; j++){
        cout << j * i << " ";
    
    }
    cout << endl;
  }
  
}