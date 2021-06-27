#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int create_number(){
    srand(time(0));
    int secret_number = rand() % 5 + 1;
    return secret_number;
}


int lucky_number(int balance){
    std::string welcome = "Welcome to the Lucky Number Game.  Here's the Rules:";
    slow_text(welcome, 50);
    std::cout << std::endl;
    std::string lucky_number_rules = "We are going to pick a random number between 1 & 5.  You have three attmepts to guess our number.  If you miss all three attempts you lose $10.  If you get it right, we start over with a different number.  The less attempts it takes for you to guess the number, the more you make.  Here's the rewards:\n 1st Attempt = $10\n 2nd Attempt = $7\n 3rd Attempt = $5\n\nYou can walk at any time.\n\n Let's Play.....:";
    slow_text(lucky_number_rules, 50);
    int attempts = 1;
    int secret = create_number();
    int guess;
    do{
        std::cout << "\nGuess:";
        std::cin >> guess;
        if(guess == secret){
            std::cout << "\nYou Got It!";
            if(attempts == 1){
                balance = balance + 10;
                std::cout << "You Won $10 Dollars";
            }
            else if(attempts == 2){
                balance = balance + 7;
                std::cout << "You Won $7 Dollars";
            }
            else if(attempts ==3){
                balance = balance + 5;
                std::cout << "\nYou Won $5 Dollars";
            }
            std::cout << "\nYour New Balance is:" << balance << std::endl;
            std::cout << "\n 1. Replay\n 2. Choose Another Game\n 3. Walk" << std::endl;
            int choice = 0;
            std::cin >> choice;
            while((choice == 0) || (choice > 3)){
                    std::cout << "Sorry buddy that's not a valid input, try again..." << std::endl;
                    std::cin >> choice;
            if(choice == 1){
                attempts = 1;
                lucky_number(balance);
            }
            else if(choice == 2){
                selector(balance);
            }
            else if(choice == 3){
                // Save to leaderboard and exit
            }
        }   }
        else if(guess != secret){
            attempts++;
            std::cout << "Wrong! Try Again:";
        }
    }while(attempts <= 3);
    if(attempts > 3){
        balance = balance - 10;
        std::cout << "You Lose! We will be taking $10 for the House, Thanks for Your Kindness!\n";
        std::cout << "Your New Balance is:" << balance << std::endl;
        std::cout << " 1. Replay\n 2. Choose Another Game\n 3. Walk" << std::endl;
            int choice = 0;
            std::cin >> choice;
            while((choice == 0) || (choice > 3)){
                    std::cout << "Sorry buddy that's not a valid input, try again..." << std::endl;
                    std::cin >> choice;
            if(choice == 1){
                attempts = 1;
                lucky_number(balance);
            }
            else if(choice == 2){
                selector(balance);
            }
            else if(choice == 3){
                // Save to leaderboard and exit
            }
    }}
    return 0;
}