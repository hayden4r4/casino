class Player{
    public:
        int balance;
        bool walk, game_over;
};

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "title.hpp"
#include "leaderboard.hpp"
#include "selector.hpp"
#include "luckynumber.hpp"


void begin(){
    Player player;
    player.balance = 10;
    player.walk = 0;
    player.game_over = 0;
    do{
        do{
            show_title(player.balance);
            selector();
            int game_choice;
            std::cin >> game_choice;

            if(game_choice==1){
                player.balance = lucky_number(player.balance);
            }
        }while(player.balance > 0 && player.walk == 0);
        if(player.balance > 0 && player.walk == 1){
            // Save to leaderboard and exit
        }

        else{
            std::cout << "Uh-oh Looks Like Your Current Balance is $0, Sorry But We Don't Run a Charity, Come Back When You Aren't Broke!!\n Restart?    Y/n" << std::endl;
            player.game_over = 1;
        }
    } while(player.game_over == 0);
}

int end_game_menu(){
    std::string restart_string;
    std::cin >> restart_string;
    if(restart_string == "Y" || "y" || "yes" || "Yes"){
        begin();
    }
    else if(restart_string == "N" || "n" || "no" || "No"){
        return 0;
    }
    else{
        std::cout << "Sorry that's not a valid option buddy, please enter Y/n..." << std::endl;
        end_game_menu();
    }
    return 0;
}

int main(){
    Player player;
    player.balance = 10;
    player.walk = 0;
    player.game_over = 0;
    if(player.game_over == 0){
        begin();
    }
    else if(player.game_over == 1){
        end_game_menu();
    }
    return 0;
}