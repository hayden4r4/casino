void selector(Player& player){
    std::string choice_text = "Choose Your Game:\n\n";
    slow_text(choice_text, 50);

    std::this_thread::sleep_for(std::chrono::milliseconds(700));

    std::string exit_option = "0. Save Score and Exit\n";
    slow_text(exit_option, 50);
    std::string option_1 = "1. Lucky Number  -  $10 Minimum\n";
    slow_text(option_1, 50);



    int game_choice;
    std::cin >> game_choice;
    player.choose_game(game_choice);
}

