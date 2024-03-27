#ifndef ROBOT_HPP_INCLUDED
#define ROBOT_HPP_INCLUDED

// forward declaration of the Mine class (to avoid circular dependency)
class Mine;

class Robot{
    public:
        Robot(int x, int y, std::string name);
        virtual ~Robot();

        // functions to move the robot one field at a time and to teleport from one place to another
        void moveRobot(const char direction);
        void set_location(const int x, const int y);

        // pure virtual function for extraction (will be initialized in each specific robot class)
        virtual void extract(Mine& mine, const int x, const int y) = 0;

        // getter functions for x- and y-coordinates, name, and points
        int get_xCoord() const;
        int get_yCoord() const;
        std::string get_name() const;
        int get_points() const;

        // function for deducting 3 points (special effect -3)
        void deduct_points();

    protected:
        int x_coord;
        int y_coord;
        int z_coord;
        std::string name;
        int points;

    private:

};

#endif // ROBOT_HPP_INCLUDED
