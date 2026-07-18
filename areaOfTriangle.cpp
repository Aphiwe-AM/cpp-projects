#include <iostream>
#include <cmath>
using namespace std;

//Write a program that reads in the three sides of a triangle and then displays the area.

//function decleararions
float calTriArea(float sum, int a, int b, int c);

int main(){
    //variables
    int a, b, c; 
    float sumTri, area;

    //get input from the user.
    cout << "Input lenght a: ";
    cin >> a;

    cout << "Input lenght b: ";
    cin >> b;

    cout << "Input lenght c: ";
    cin >> c;

    //calculate the sum and area of triangle
    sumTri = (a + b + c) / 2;

    area = calTriArea(sumTri, a, b, c);

    //output the area of  the tri
    cout << "The area of a triangle with proportions " << a << " " << b << " "  << c << " is: " << area << " squared."; 

    return 0;
}

float calTriArea(float sum, int a, int b, int c){
    if( sum * (sum - a) * (sum - b) * (sum - c) <= 0){
        cout << "This is not a valid triangle :/." << endl;
        return 0;
    }
    return sqrt(sum * (sum - a) * (sum - b) * (sum - c));
    
}