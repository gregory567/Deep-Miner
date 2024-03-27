

skilledBot::skilledBot(std::string name): Robot(2, 2, name){
    // construction
}

skilledBot::~skilledBot() {
    // destruction
}


void skilledBot::extract(Mine& m, const int x, const int y){

    // add the field's value times 2 to the points of skilledBot
    points += m.get_field(x, y, 9) * 2;
    // set the field of the mine equal to 0
    m.remove_field(x, y, 9);

}




