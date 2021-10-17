#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int create_number()
{
    srand(time(0));
    int secret_number = rand() % 5 + 1;
    return secret_number;
}

class Lucky_number_attrs
{
private:
    int attempts, secret, guess, choice;
    bool first_run;

public:
    void init()
    {
        attempts = 0;
        secret = create_number();
        choice = 0;
        guess = 0;
    }
    void add_attempt()
    {
        attempts++;
    }
    int get_attempts()
    {
        return attempts;
    }
    int get_secret()
    {
        return secret;
    }
    void set_guess(int user_guess)
    {
        guess = user_guess;
    }
    int get_guess()
    {
        return guess;
    }
    void set_choice(int user_choice)
    {
        choice = user_choice;
    }
    int get_choice()
    {
        return choice;
    }
    void set_first_run(bool first_run_bool)
    {
        first_run = first_run_bool;
    }
    bool get_first_run()
    {
        return first_run;
    }
};

void lucky_number(bool first_run_bool)
{
    Lucky_number_attrs attrs;
    attrs.init();
    attrs.set_first_run(first_run_bool);
    if (attrs.get_first_run() == true)
    {
        std::string welcome = "\nWelcome to the Lucky Number Game.  Here's the Rules:";
        slow_text(welcome, 50);
        std::cout << std::endl;
        std::string lucky_number_rules = "We are going to pick a random number between 1 & 5.\nYou have three attempts to guess our number.\nIf you miss all three attempts you lose $10.\nIf you get it right, we start over with a different number.\nThe less attempts it takes for you to guess the number, the more you make.\n\nHere are the rewards:\n\n 1st Attempt = $10\n 2nd Attempt = $7\n 3rd Attempt = $5\n\nLet's Play.....:\n";
        slow_text(lucky_number_rules, 50);
        attrs.set_first_run(false);
    }
    while ((player.balance >= 10) && (attrs.get_choice() == 0))
    {
        while (attrs.get_attempts() < 3)
        {
            attrs.add_attempt();
            std::cout << "\nGuess: ";
            int guess;
            std::cin >> guess;
            while ((guess == 0) || (guess > 5))
            {
                std::cout << "Sorry buddy that's not a valid input, choose a number between 1 & 5\n";
                std::cin >> guess;
            }
            attrs.set_guess(guess);

            if (attrs.get_guess() == attrs.get_secret())
            {
                std::cout << "\nYou Got It!\n";
                if (attrs.get_attempts() == 1)
                {
                    player.balance += 10;
                    std::cout << "You Won $10 Dollars\n";
                }
                else if (attrs.get_attempts() == 2)
                {
                    player.balance += 7;
                    std::cout << "You Won $7 Dollars\n";
                }
                else if (attrs.get_attempts() == 3)
                {
                    player.balance += 5;
                    std::cout << "You Won $5 Dollars\n";
                }
                std::cout << "\nYour New Balance is: $" << player.balance << std::endl;
                std::cout << "\n 1. Replay\n 2. Choose Another Game\n 3. Walk" << std::endl;
                int choice;
                std::cin >> choice;
                attrs.set_choice(choice);
                while ((attrs.get_choice() == 0) || (attrs.get_choice() > 3))
                {
                    std::cout << "Sorry buddy that's not a valid input, try again..." << std::endl;
                    std::cin >> choice;
                    attrs.set_choice(choice);
                }
                if ((attrs.get_choice() != 0) && (attrs.get_choice() <= 3))
                {
                    if (attrs.get_choice() == 1)
                    {
                        lucky_number(false);
                    }
                    else if (attrs.get_choice() == 2)
                    {
                        attrs.init();
                        selector();
                    }
                    else if (attrs.get_choice() == 3)
                    {
                        player.walk = true;
                    }
                }
            }
            else if (attrs.get_guess() != attrs.get_secret())
            {
                if ((attrs.get_attempts() == 1) || (attrs.get_attempts() == 2))
                {
                    std::cout << "Wrong! Try Again:";
                }
                else if (attrs.get_attempts() == 3)
                {
                    std::cout << "Wrong!\n";
                }
            }
        }
        player.balance -= 10;
        std::cout << "You Lose! We will be taking $10, Thanks for Your Donation to the House!\n";
        std::cout << "Your New Balance is: $\n" << player.balance << std::endl;
        if (player.balance > 10)
        {
            std::cout << " 1. Replay\n";
        }
        std::cout << " 2. Choose Another Game\n 3. Walk" << std::endl;
        int choice;
        std::cin >> choice;
        attrs.set_choice(choice);
        while ((attrs.get_choice() == 0) || (attrs.get_choice() > 3))
        {
            std::cout << "Sorry buddy that's not a valid input, try again..." << std::endl;
            std::cin >> choice;
            attrs.set_choice(choice);
        }
        if ((attrs.get_choice() != 0) && (attrs.get_choice() <= 3))
        {
            if (attrs.get_choice() == 1)
            {
                while ((player.balance < 10) && (attrs.get_choice() == 1))
                {
                    std::cout << "Sorry buddy, you're too poor for that, come back when you have $10...\nChoose again:\n";
                    std::cin >> choice;
                    attrs.set_choice(choice);
                }
                lucky_number(false);
            }
            else if (attrs.get_choice() == 2)
            {
                attrs.init();
                selector();
            }
            else if (attrs.get_choice() == 3)
            {
                player.walk = true;
            }
        }
    }
    attrs.init();
    selector();
}