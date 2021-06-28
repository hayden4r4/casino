int selector(){
    std::string choice_text = "Choose Your Game:\n\n";
    slow_text(choice_text, 50);

    std::this_thread::sleep_for(std::chrono::milliseconds(700));

    std::string option_1 = "1. Lucky Number\n";
    slow_text(option_1, 50);

    return 0;
}

