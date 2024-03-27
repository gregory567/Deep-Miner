#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <functional>

#include "Robot.hpp"
#include "Mine.hpp"
#include "Mine.cpp"
#include "sortingBot.hpp"
#include "sortingBot.cpp"
#include "tripleBot.hpp"
#include "tripleBot.cpp"
#include "skilledBot.hpp"
#include "skilledBot.cpp"
#include "Game.hpp"
#include "Game.cpp"


int main(){

    // Setup:
    // call the game constructor
    Game my_game;
    // seed the random number generator with the current time
    srand(time(nullptr));
    // call the mine constructor
    Mine GameField;
    // initialize the mine
    GameField.init_mine();
    // print out the mine for the first time at the start of the game
    GameField.print_mine();

    // choose the type of the robot
    int robot_type = my_game.selectRobotType();

    // initialize the 3 different robots
    sortingBot sorting_miner("Novak");
    tripleBot triple_miner("Rafa");
    skilledBot skilled_miner("Roger");

    // run the game with the chosen robot
    switch(robot_type){
        case 1:
            // use sorting_miner
            my_game.runGame(sorting_miner, GameField, my_game);
            break;
        case 2:
            // use triple_miner
            my_game.runGame(triple_miner, GameField, my_game);
            break;
        case 3:
            // use skilled_miner
            my_game.runGame(skilled_miner, GameField, my_game);
            break;
        default:
            // this should never happen
            std::cout << "Invalid robot type." << std::endl;
            break;
    }


    return 0;
}








