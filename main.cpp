#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "title.hpp"
#include "selector.hpp"
#include "leaderboard.hpp"
#include "luckynumber.hpp"



int begin(int balance, bool walk, bool game_over){
    balance = 10;
    walk = 0;
    game_over = 0;
    while(game_over == 0){
        if(balance > 0 && walk == 0){
            show_title(balance);
            selector(balance);
            int game_choice;
            std::cin >> game_choice;

            if(game_choice==1){
                lucky_number(balance);
            }
        }
        else if(balance > 0 && walk == 1){
            // Save to leaderboard and exit
        }

        else{
            std::cout << "Uh-oh Looks Like Your Current Balance is $0, Sorry But We Don't Run a Charity, Come Back When You Aren't Broke!!\n Restart?    Y/n" << std::endl;
            game_over = 1;
        }
    }
    return 0;
}

int end_game_menu(int balance, bool walk, bool game_over){
    std::string restart_string;
    std::cin >> restart_string;
    if(restart_string == "Y" || "y" || "yes" || "Yes"){
        begin(balance, walk, game_over);
    }
    else if(restart_string == "N" || "n" || "no" || "No"){
        return 0;
    }
    else{
        std::cout << "Sorry that's not a valid option buddy, please enter Y/n..." << std::endl;
        end_game_menu(balance, walk, game_over);
    }
    return 0;
}

int main(){
    int balance = 10;
    bool walk = 0;
    bool game_over = 0;
    while(game_over == 0){
        begin(balance, walk, game_over);
    if(game_over == 1){
        end_game_menu(balance, walk, game_over);
    }
    }
    return 0;
}