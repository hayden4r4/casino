void slow_text(std::string string_arg, int sleep)
{
    for (char c : string_arg)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
        std::cout << c << std::flush;
    }
}

int show_title(Player &player)
{
    std::cout << "                                                 " << std::flush;
    std::string welcome_text = "Welcome to the";
    slow_text(welcome_text, 50);

    for (int i = 1; i < 7; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        std::cout << "." << std::flush;
    }
    std::string logo = R"(
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$___/\\\\\\\\\_____/\\\\\\\\\________/\\\\\\\\\\\____/\\\\\\\\\\\__/\\\\\\______//\\\________/\\\\\\\\\\\\_________$
$_/\\\////////____/\\\\\\\\\\\\\____/\\\/////////\\\_\/////\\\///__\/\\\/\\\_____\/\\\_____/\\\////////////\\\_____$
$/\\\/____________/\\\/////////\\\__\//\\\______\///______\/\\\_____\/\\\_\/\\\___\/\\\___/\\\/____________\/\\\___$
$/\\\_____________\/\\\_______\/\\\___\////\\\_____________\/\\\_____\/\\\__\/\\\__\/\\\__/\\\_______________\/\\\_$
$\/\\\_____________\/\\\\\\\\\\\\\\\______\////\\\__________\/\\\_____\/\\\___\/\\\_\/\\\_\/\\\______________ \/\\\$
$_\//\\\____________\/\\\/////////\\\_________\////\\\_______\/\\\_____\/\\\____\/\\\\/\\\_\//\\\___________  \/\\\$
$___\///\\\__________\/\\\_______\/\\\__/\\\______\//\\\______\/\\\_____\/\\\_____\/\\\/\\\__\///\\\__________/\\\/$
$______\////\\\\\\\\\_\/\\\_______\/\\\_\///\\\\\\\\\\\/____/\\\\\\\\\\\_\/\\\______\/\\\\\\____\////\\\\\\\\\\///_$
$__________\/////////__\///________\///____\///////////_____\///////////__\///_______\//////________\//////////____$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
)";
    slow_text(logo, 2);

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::string under_text = "Your Pain is Our Pleasure";
    slow_text(under_text, 50);
    for (int i = 1; i < 4; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        std::cout << "." << std::flush;
    }
    std::cout << "                                         ";
    std::string credits = "Created by Hayden Rose  @  github.com/hayden4r4";
    slow_text(credits, 50);
    std::cout << "\n"
              << std::endl;
    
    std::string leaderboard_title = "\nTop 10 Leaderboard:\n\n";
    slow_text(leaderboard_title, 50);
    show_leaderboard();

    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    std::string balance_string = "\n\nYour Balance is: $";
    slow_text(balance_string, 50);
    std::cout << player.get_balance() << "\n"
              << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    return 0;
}