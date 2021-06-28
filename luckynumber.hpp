#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int create_number(){
    srand(time(0));
    int secret_number = rand() % 5 + 1;
    return secret_number;
}

class Lucky_number_attrs{
    public:
        int attempts, secret, guess, choice;
        bool instructions;
};

int lucky_number(int balance){
    Lucky_number_attrs attrs;
    std::string welcome = "Welcome to the Lucky Number Game.  Here's the Rules:";
    slow_text(welcome, 50);
    std::cout << std::endl;
    std::string lucky_number_rules = "We are going to pick a random number between 1 & 5.\nYou have three attmepts to guess our number.\nIf you miss all three attempts you lose $10.\nIf you get it right, we start over with a different number.\nThe less attempts it takes for you to guess the number, the more you make.\n\nHere's the rewards:\n\n 1st Attempt = $10\n 2nd Attempt = $7\n 3rd Attempt = $5\n\nYou can walk at any time.\n\nLet's Play.....:\n";
    slow_text(lucky_number_rules, 50);
    attrs.attempts = 1;
    attrs.choice = 0;
    attrs.secret = create_number();
    do{
        std::cout << "\nGuess: ";
        std::cin >> attrs.guess;
        if(attrs.guess == attrs.secret){
            std::cout << "\nYou Got It!\n";
            if(attrs.attempts == 1){
                balance = balance + 10;
                std::cout << "You Won $10 Dollars\n";
            }
            else if(attrs.attempts == 2){
                balance = balance + 7;
                std::cout << "You Won $7 Dollars\n";
            }
            else if(attrs.attempts == 3){
                balance = balance + 5;
                std::cout << "You Won $5 Dollars\n";
            }
            std::cout << "\nYour New Balance is: $" << balance << std::endl;
            std::cout << "\n 1. Replay\n 2. Choose Another Game\n 3. Walk" << std::endl;
            std::cin >> attrs.choice;
            do{
                if(attrs.choice == 1){
                    lucky_number(balance);
                }
                else if(attrs.choice == 2){
                    selector();
                    return balance;
                }
                else if(attrs.choice == 3){
                    // Save to leaderboard and exit
                }  
            }while((attrs.choice != 0) && (attrs.choice <= 3));
            do{
                    std::cout << "Sorry buddy that's not a valid input, try again..." << std::endl;
                    std::cin >> attrs.choice;
            } while((attrs.choice == 0) || (attrs.choice > 3));
        }
        else if(attrs.guess != attrs.secret){
            attrs.attempts++;
            if((attrs.attempts == 1) || (attrs.attempts == 2)){
                std::cout << "Wrong! Try Again:";
            }
            else if(attrs.attempts == 4){
                std::cout << "Wrong!\n";
            }
        }
    }while((attrs.attempts <= 3) || (attrs.choice == 0) || (attrs.guess != attrs.secret));
    if(attrs.attempts > 3){
        balance = balance - 10;
        std::cout << "You Lose! We will be taking $10 for the House, Thanks for Your Kindness!\n";
        std::cout << "Your New Balance is: $" << balance << std::endl;
        std::cout << " 1. Replay\n 2. Choose Another Game\n 3. Walk" << std::endl;
        attrs.choice = 0;
        std::cin >> attrs.choice;
        do{
                std::cout << "Sorry buddy that's not a valid input, try again..." << std::endl;
                std::cin >> attrs.choice;
        }while((attrs.choice == 0) || (attrs.choice > 3));
        if(attrs.choice == 1){
            lucky_number(balance);
        }
        else if(attrs.choice == 2){
            selector();
            return balance;
        }
        else if(attrs.choice == 3){
            // Save to leaderboard and exit
        }
    }
    return 0;
}
    
