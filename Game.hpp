#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

class Game{
    public:
        Game();
        ~Game();
        // function for getting input from the user
        char get_input(const std::string& validOptions) const;
        // function for selecting robot type
        int selectRobotType();
        // function for running the game
        void runGame(Robot& robot, Mine& mine, Game& game);

        // functions for displaying and incrementing the round and level counters
        int get_round_counter() const;
        void increment_round_counter();
        int get_level_counter() const;
        void increment_level_counter();

    private:
        int round_counter;
        int level_counter;

};

#endif // GAME_HPP_INCLUDED
