#include <fstream>
#include <filesystem>
#include <vector>
#include <iterator>
#include <algorithm>

void show_leaderboard()
{
    // Read in Leaderboard.txt File
    std::ifstream ldb("Leaderboard.txt");

    // Create Vector to Store Leaderboard In
    std::vector<int> data;

    // Iterate Through Contents of Leaderboard.txt File and Append to Vector
    int element;
    while (ldb >> element)
    {
        data.push_back(element);
    }
    // Sort Leaderboard Data Vector in Descending Order
    std::sort(data.begin(), data.end(), std::greater<int>());

    // Resize Leaderboard Data Vector to Length of 10
    if (data.size() > 10)
    {
        data.resize(10);
    }

    // Print Leaderboard
    for (int i = 0; i < data.size(); i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(70));
        std::cout << i + 1 << ". " << data.at(i);
        if (data.size() != i + 1)
        {
            std::cout << "  |  " << std::flush;
        }
        else
        {
            std::cout << std::flush;
        }
    }
}

void write_leaderboard()
{
    std::ofstream leaderboardtxt("Leaderboard.txt", std::ios::app);
    leaderboardtxt << "\n"
                   << player.balance;
}