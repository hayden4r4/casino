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
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$___/\\\\\\\\\______/\\\\\\\\\_________/\\\\\\\\\\\_____/\\\\\\\\\\\____/\\\\\\______//\\\__________/\\\\\\\\\\\\_________$
$_/\\\////////_____/\\\\\\\\\\\\\_____/\\\/////////\\\__\/////\\\///____\/\\\/\\\_____\/\\\_______/\\\////////////\\\_____$
$/\\\/_____________/\\\/////////\\\___\//\\\______\///_______\/\\\_______\/\\\_\/\\\___\/\\\_____/\\\/____________\/\\\___$
$/\\\______________\/\\\_______\/\\\____\////\\\______________\/\\\_______\/\\\__\/\\\__\/\\\____/\\\_______________\/\\\_$
$\/\\\______________\/\\\\\\\\\\\\\\\_______\////\\\___________\/\\\_______\/\\\___\/\\\_\/\\\___\/\\\______________ \/\\\$
$_\//\\\_____________\/\\\/////////\\\__________\////\\\________\/\\\_______\/\\\____\/\\\\/\\\___\//\\\___________  \/\\\$
$___\///\\\___________\/\\\_______\/\\\___/\\\______\//\\\_______\/\\\_______\/\\\_____\/\\\/\\\____\///\\\__________/\\\/$
$______\////\\\\\\\\\__\/\\\_______\/\\\__\///\\\\\\\\\\\/_____/\\\\\\\\\\\___\/\\\______\/\\\\\\______\////\\\\\\\\\\///_$
$__________\/////////___\///________\///_____\///////////______\///////////____\///_______\//////__________\//////////____$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
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
    std::cout << "                                                ";
    std::string credits = "Created by Hayden Rose  @  github.com/hayden4r4";
    slow_text(credits, 50);
    std::cout << "\n"
              << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    std::string balance_string = "Your Balance is: $";
    slow_text(balance_string, 50);
    std::cout << player.get_balance() << "\n"
              << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    return 0;
}