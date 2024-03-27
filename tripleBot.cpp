

tripleBot::tripleBot(std::string name): Robot(2, 2, name){
    // construction
}

tripleBot::~tripleBot() {
    // destruction
}

void tripleBot::extract(Mine& m, const int x, const int y){

    // add the 3 fields to the points of tripleBot
    points += m.get_field(x, y, 9);
    points += m.get_field(x, y, 8);
    points += m.get_field(x, y, 7);
    // set the 3 fields of the mine equal to 0
    m.remove_field(x, y, 9);
    m.remove_field(x, y, 8);
    m.remove_field(x, y, 7);

}
