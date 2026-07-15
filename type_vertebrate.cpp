#include <iostream>
using namespace std;

int main(){
    // declear variables 
    char answer;
    string type_vertebrate;

    //ask user questions to determine type of in vertebrates
    cout << "Is the animal warm-blooded (y/n)? ";
    cin >> answer;
    //mammals and birds 
    if(answer == 'y'){
        cout << "Does the animal suckel its young (y/n)? ";
        cin >> answer;
        if(answer == 'y'){
            type_vertebrate = "Mammal";
        }else{
            type_vertebrate = "Bird";
        }
    }
    //cold-blooded reptiles, amphibians and fish
    else{
        cout << "Does the animal use lungs to breath (y/n)? ";
        cin >> answer;
        //reptiles 
        if(answer == 'y'){
            type_vertebrate = "Reptile";
        } 
        else {
            cout << "Can the animal survive on land and water (y/n)? ";
            cin >> answer;
            //amphibians
            if( answer == 'y'){
                type_vertebrate = "Amphibian";
            }
            else {
                type_vertebrate = "Fish";
            }
            
        }

    }
    cout << "Processing........." << endl;
    cout << "***********************" << endl;
    cout << "Your verbrate is a " << type_vertebrate << '.' << endl;
}