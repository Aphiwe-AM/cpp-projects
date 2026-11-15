/*
• The Goal: Create a classic game where the program picks a target number (or uses a hardcoded configuration variable) and the user has to guess it, receiving guided feedback along the way.
• What it should do:
	• Prompt the player to guess the hidden number using std::cin.
	• Use a while or do-while loop to keep the game active until the player guesses correctly.
	• Use conditional checks to print "Too High!" or "Too Low!" after each incorrect attempt.
	• Track and print the total number of attempts once the user successfully guesses the number.
*/ 

#include <iostream>
#include <string>

int main(){
    const int hidden_num{7};
    int guess{}, count{};

    do{
        std::cout << "Input your guess: ";
        std::cin >> guess;

        // set conditional for guessing game high low
        if(guess > hidden_num){
            std::cout << "Go lower!" << std::endl;
        }else if (guess < hidden_num){
            std::cout << "Go higher!" << std::endl;
        }
        count++;
    }while(guess != hidden_num);

    std::cout << "Well done you guessed correctly! "<< std::endl << "Number of tries: "<< count;

    
}