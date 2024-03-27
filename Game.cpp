#ifndef GAME_CPP_INCLUDED
#define GAME_CPP_INCLUDED


Game::Game(){
    round_counter = 1;
    level_counter = 1;
}

Game::~Game(){
    // destruction
}

int Game::get_round_counter() const{
    return round_counter;
}

void Game::increment_round_counter(){
    round_counter++;
}

int Game::get_level_counter() const{
    return level_counter;
}

void Game::increment_level_counter(){
    level_counter++;
}

char Game::get_input(const std::string& validOptions) const{
    char input;
    bool valid_input = false;
    std::string options = validOptions;
    // converts the string to lowercase for case-insensitivity
    std::transform(options.begin(), options.end(), options.begin(), ::tolower);
    do{
        std::cout << "Please enter \"w\" for moving to the next tunnel, "
        << std::endl << "\"a\" for moving to the previous block, "
        << std::endl << "\"s\" for moving to the previous tunnel, "
        << std::endl << "\"d\" for moving to the next block, "
        << std::endl << "or \"e\" for staying at the same place: ";
        std::cin >> input;
        // converts the input character to lowercase for case-insensitivity
        input = std::tolower(input);
        if(options.find(input) == std::string::npos){
            std::cout << "Invalid input. Please enter one of [" << validOptions << "]." << std::endl;
        } else {
            valid_input = true;
        }
    }while(!valid_input);
    return input;
}


int Game::selectRobotType(){
    // placeholder for robot type
    int robot_type;
    // validity checker boolean
    bool valid_input = false;
    // array of valid options
    std::array<int, 3> options = {1, 2, 3};
    do {
        // ask the user for input
        std::cout << "Please enter: "
        << std::endl << options[0] << " for Sorting Bot, "
        << std::endl << options[1] << " for Triple Bot, "
        << std::endl << options[2] << " for Skilled Bot: ";
        // read in the input
        std::cin >> robot_type;
        // check if included in valid options array
        for(int i : options){
            if(robot_type == i){
                valid_input = true;
                break;
            }
        }
        // warning if the input is invalid
        if(!valid_input){
            std::cout << "Invalid input. Please enter one of [" << options[0] << ", " << options[1] << ", " << options[2] << "]." << std::endl;
        }
    }while(!valid_input); // repeat until the input is valid

    return robot_type;
}


void Game::runGame(Robot& robot, Mine& mine, Game& game){

    do{
        // print out the current round
        std::cout << "\nRound: " << game.get_round_counter() << std::endl;
        // print out the current points
        std::cout << "Points: " << robot.get_points() << std::endl;
        // move the robot with "wasde" ("e" for staying in place)
        robot.moveRobot(game.get_input("wasde"));
        // print out new location of the robot
        std::cout << "\nnew location: Block: " << robot.get_xCoord() << " Tunnel: " << robot.get_yCoord() << std::endl;
        // as the first step, check the tunnel for special effects
        if(mine.special_effect(robot.get_xCoord(), robot.get_yCoord()) != 0){
            // when special effect is found, warn the user
            std::cout << "Special mineral found at position: " << mine.special_effect_index(robot.get_xCoord(), robot.get_yCoord()) << std::endl;
            // switch to different cases depending on the nature of the special effect
            switch(mine.special_effect(robot.get_xCoord(), robot.get_yCoord())){
                case -1:
                    // the robot is not allowed to extract in this round
                    mine.remove_field(robot.get_xCoord(), robot.get_yCoord(), mine.special_effect_index(robot.get_xCoord(), robot.get_yCoord()));
                    game.increment_round_counter();
                    std::cout << "You have to skip one round." << std::endl;
                    // print the new mine
                    //mine.print_mine();
                    continue;
                    break;
                case -2:
                    // the robot will be placed at the x and y coordinates with the lowest value at z=9
                    mine.remove_field(robot.get_xCoord(), robot.get_yCoord(), mine.special_effect_index(robot.get_xCoord(), robot.get_yCoord()));
                    robot.set_location(mine.find_lowest_tunnel().first, mine.find_lowest_tunnel().second);
                    std::cout << "You will be transported to a new tunnel." << std::endl;
                    // print out new location of the robot
                    std::cout << "\nnew location: Block: " << robot.get_xCoord() << " Tunnel: " << robot.get_yCoord() << std::endl;
                    // we continue with the extraction here and do not skip it with "continue"
                    break;
                case -3:
                    // the robot will get 3 points deducted and not allowed to extract in this round
                    mine.remove_field(robot.get_xCoord(), robot.get_yCoord(), mine.special_effect_index(robot.get_xCoord(), robot.get_yCoord()));
                    robot.deduct_points();
                    game.increment_round_counter();
                    std::cout << "3 points will be deducted for violating the mining regulations." << std::endl;
                    // print the new mine
                    //mine.print_mine();
                    continue;
                    break;
                default:
                    // this should never happen
                    std::cerr << "Error: unknown special effect detected." << std::endl;
                    break;
            }
        }
        // use the overriden extraction function of each robot
        robot.extract(mine, robot.get_xCoord(), robot.get_yCoord());
        // print the new mine
        mine.print_mine();
        // increment round
        game.increment_round_counter();

        // every time the points of the robot are divisible by 50, increment the level counter and rearrange the mine
        if(robot.get_points() % 50 == 0 /*robot.get_points() % 10 == 0 || robot.get_points() % 5 == 0*/){
            game.increment_level_counter();
            std::cout << "Congrats, you have reached a new level!" << std::endl;
            std::cout << "Level: " << game.get_level_counter() << std::endl;
            // rearrange the mine randomly based on 3 different rearranging techniques
            mine.rearrange_mine();
            mine.print_mine();
        }

    }while(robot.get_points() < 100); // repeat the rounds until the robot reaches 150 points

    std::cout << "Congrats, you have reached the end of the game!" << std::endl;

}



#endif // GAME_CPP_INCLUDED
