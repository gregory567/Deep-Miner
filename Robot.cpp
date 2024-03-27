


Robot::Robot(int x, int y, std::string name){
    x_coord = x;
    y_coord = y;
    z_coord = 9;
    this->name = name;
    points = 0;
}

Robot::~Robot(){
    // destruction
}

void Robot::moveRobot(const char direction){
    switch(direction){
        case 'w':
            if(y_coord < 4){
                y_coord++;
            } else {
                y_coord = 0;
            }
            break;
        case 'a':
            if(x_coord > 0){
                x_coord--;
            } else {
                x_coord = 4;
            }
            break;
        case 's':
            if(y_coord > 0){
                y_coord--;
            } else {
                y_coord = 4;
            }
            break;
        case 'd':
            if(x_coord < 4){
                x_coord++;
            } else {
                x_coord = 0;
            }
            break;
        default:
            std::cout << "\nThe robot does not move in this round." << std::endl;
            break;
    }
}

int Robot::get_xCoord() const{
    return x_coord;
}

int Robot::get_yCoord() const{
    return y_coord;
}

std::string Robot::get_name() const{
    return name;
}

int Robot::get_points() const{
    return points;
}

void Robot::set_location(const int x, const int y){
    x_coord = x;
    y_coord = y;
}

void Robot::deduct_points(){
    points -= 3;
}











