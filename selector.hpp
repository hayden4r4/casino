int selector(int balance){std::string choice_text = "Choose Your Game:";
    slow_text(choice_text, 50);
    std::cout << "\n" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(700));

    std::string option_1 = "1. Lucky Number";
    slow_text(option_1, 50);
    std::cout << std::endl;
    return 0;
}