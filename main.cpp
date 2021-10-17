#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "player.hpp"
#include "leaderboard.hpp"
#include "title.hpp"
#include "selector.hpp"
#include "luckynumber.hpp"

struct Player player = {
    .balance = 10,
    .game_choice = -1,
    .walk = false,
    .game_over = false,
    .first_run = true};

void begin()
{
    player.first_run = false;
    show_title();
    while (player.balance > 0 && player.walk == false)
    {
        selector();

        // Game Choice 1 (Lucky Number) - Requires $10
        while ((player.game_choice == 1) && (player.balance >= 10))
        {
            lucky_number(true);
        }
    };
    if (player.balance > 0 && player.walk == true)
    {
        // Save to leaderboard and exit
        write_leaderboard();
        exit(0);
    }

    else
    {
        std::cout << "Uh-oh Looks Like Your Current Balance is $0, Sorry But We Don't Run a Charity, Come Back When You Aren't Broke!!\n Restart?    Y/n" << std::endl;
        player.game_over = true;
    }
};

int end_game_menu()
{
    std::string restart_string;
    std::cin >> restart_string;
    if (restart_string == "Y" || "y" || "yes" || "Yes")
    {
        begin();
    }
    else if (restart_string == "N" || "n" || "no" || "No")
    {
        exit(0);
    }
    else
    {
        std::cout << "Sorry that's not a valid option buddy, please enter Y/n..." << std::endl;
        end_game_menu();
    }
    return 0;
}

int main()
{
    while (player.game_over == false)
    {
        begin();
    }
    while (player.game_over == true)
    {
        end_game_menu();
    }
    return 0;
}