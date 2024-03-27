
#include "Robot.cpp"

sortingBot::sortingBot(std::string name) : Robot(2, 2, name) {
    // construction
}

sortingBot::~sortingBot() {
    // destruction
}


void sortingBot::extract(Mine& m, const int x, const int y){

    // sort the array in descending order
    m.sort_tunnel(m.get_tunnel(x, y));

    // the highest number in the array is tunnel[9]
    // add the highest number to the points of sortingBot
    points += m.get_field(x, y, 9);
    // set the field of the mine equal to 0
    m.remove_field(x, y, 9);
}

