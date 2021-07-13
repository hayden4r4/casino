#include "Player.hpp"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "title.hpp"
// #include "leaderboard.hpp"
#include "selector.hpp"
#include "luckynumber.hpp"

void begin(Player &player)
{
    bool first_run = 0;
    show_title(player);
    while (player.get_game_status() == 0)
    {
        while (player.get_balance() > 0 && player.get_walk() == 0)
        {
            selector(player);
            // Game Choice 0 (Exit) - Saves to Leaderboard and Exits
            while (player.get_game_choice() == 0)
            {
                // Save to leaderboard
                exit(0);
            }

            // Game Choice 1 (Lucky Number) - Requires $10
            while ((player.get_game_choice() == 1) && (player.get_balance() >= 10))
            {
                lucky_number(player, first_run);
            }
            // Game Choice 1 with < $10
            while ((player.get_game_choice() == 1) && (player.get_balance() < 10))
            {
                std::cout << "Sorry this game requires at least $10 to play!\nPlease choose another game." << std::endl;
                selector(player);
            }
        };
        if (player.get_balance() > 0 && player.get_walk() == 1)
        {
            // Save to leaderboard
            exit(0);
        }

        else
        {
            std::cout << "Uh-oh Looks Like Your Current Balance is $0, Sorry But We Don't Run a Charity, Come Back When You Aren't Broke!!\n Restart?    Y/n" << std::endl;
            player.set_game_status(1);
        }
    };
}

int end_game_menu(Player &player)
{
    std::string restart_string;
    std::cin >> restart_string;
    if (restart_string == "Y" || "y" || "yes" || "Yes")
    {
        begin(player);
    }
    else if (restart_string == "N" || "n" || "no" || "No")
    {
        exit(0);
    }
    else
    {
        std::cout << "Sorry that's not a valid option buddy, please enter Y/n..." << std::endl;
        end_game_menu(player);
    }
    return 0;
}

int main()
{
    Player player;
    player.init();
    while (player.get_game_status() == 0)
    {
        begin(player);
    }
    while (player.get_game_status() == 1)
    {
        end_game_menu(player);
    }
    return 0;
}