#include "robot.h"

#include <string>
#include <cstdlib>
using namespace std;


//Constructor with string argument to set up a robot's name n
//Origin set up by x, y 
//Robot set up as stationary when the game begins
robot::robot(const string &n) {		
	x = 0;
	y = 0;
	travel = 0;
	robotName = n;
}

//Incrementing the robot's position in the 2D space and the amount it has travelled
void robot::move_north() {
	++y;
	++travel;
}

void robot::move_east() {
	++x;
	++travel;
}

void robot::move_south() {
	--y;
	++travel;
}

void robot::move_west() {
	--x;
	++travel;
}

//Returning the robot's name, as defined in the constructor
const string & robot::name() const {
	return robotName;
}

//Returning robot's position in the correct direction
int robot::north() const {
	return y;
}

int robot::east() const {
	return x;
}

//Returning distance travelled since creation
int robot::travelled() const {
	return travel;
}

//External function using Manhattan metric to calculate smallest number of steps to return robot r to the origin
int distance(const robot &r) {
	return abs(r.east()) + abs(r.north());
}
