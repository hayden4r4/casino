#include <fstream>
#include <filesystem>

void create_leaderboard()
{
    // Must be compiled with --std=c++17 -lstdc++fs as filesystem is a C++17 feature.

    // Create Leaderboard.txt file if it doesn't already exist in working directory.
    if (std::filesystem::exists("leaderboard.txt") == false)
    {
        std::ofstream file { "Leaderboard.txt" };
    };
}

void write_leaderboard(Player &player)
{
    std::ofstream leaderboardtxt("Leaderboard.txt");
    leaderboardtxt << player.balance;
    leaderboardtxt.close();
}