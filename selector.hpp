void selector()
{
    std::string choice_text = "\nChoose Your Game:\n\n";
    slow_text(choice_text, 50);

    std::this_thread::sleep_for(std::chrono::milliseconds(700));

    std::string exit_option = "0. Save Score and Exit\n";
    slow_text(exit_option, 50);
    std::string option_1 = "1. Lucky Number  -  $10 Minimum\n";
    slow_text(option_1, 50);
    // Insert more game options here followed by the slow text function

    std::cout << std::endl;

    int game_choice;
    std::cin >> game_choice;

    while ((player.balance < 10) && (game_choice == 1))
    {
        std::cout << "\nSorry this game has a $10 Minimum... Please Choose Another:\n";
        std::cin >> game_choice;
    }

    if (game_choice == 0)
    {
        // Save to leaderboard and Exit
        write_leaderboard();
        exit(0);
    }

    player.game_choice = game_choice;
}
