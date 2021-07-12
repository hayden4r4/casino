class Player
{
private:
    int balance, game_choice;
    bool walk, game_status;
public:    
    void init()
    {
        balance = 10;
        game_choice = 0;
        walk = 0;
        game_status = 0;
    }
    void add_balance(int amount)
    {
        balance += amount;
    }
    int get_balance()
    {
        return balance;
    }
    void choose_game(int input_game_choice)
    {
        game_choice = input_game_choice;
    }
    int get_game_choice()
    {
        return game_choice;
    }
    void set_walk(bool input_walk)
    {
        walk = input_walk;
    }
    bool get_walk()
    {
        return walk;
    }
    void set_game_status(bool input_game_status)
    {
        game_status = input_game_status;
    }
    bool get_game_status()
    {
        return game_status;
    }
};