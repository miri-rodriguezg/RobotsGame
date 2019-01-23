#include "game.h"

#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

//Casting the number of robots in the map, to return an int number 
int game::num_robots() const {
	return (int) robots.size();
}

//First if statement checks if there is an existing robot, if not, it creates a new entry on the map of robots
//Other if statements set the direction the robot can move in
void game::move(const string &name, int dir) {
	if (robots.count(name) == 0) {
		const robot newRobot = robot(name);
		robots.emplace(make_pair(name, newRobot));	
	}
	if (dir == 0) {
		robots.at(name).move_north();
	}
	else if (dir == 1){
		robots.at(name).move_east();
	} 
	else if (dir == 2) {
		robots.at(name).move_south();
	}
	else if (dir == 3){
		robots.at(name).move_west();
	}	
}

//Looping throuugh the whole map of robots to count how many robots are within 10 steps of the origin
int game::num_close() const {
	int countClose = 0;
	for (map<string, robot>::const_iterator iter = robots.begin(); iter != robots.end(); ++iter) {
		if ((abs(iter->second.north() <= 10)) or (abs(iter->second.east() <= 10))) {
			++countClose;
		}
	}
	return countClose;
}

//Looping throuugh the whole map of robots to store its distance. 
//If the distance of the next robot is bigger, furtherDistance is updated.
//Distance calculated from external function in the robot class.
int game::max_distance() const {
	int furthestDistance = 0;
	for (map<string, robot>::const_iterator iter = robots.begin(); iter != robots.end(); ++iter) {
		if (distance(iter->second) > furthestDistance) {
			furthestDistance = distance(iter-> second);
		}
	}
	return furthestDistance;
}

//Looping throuugh the whole map of robots to store the name of the robot at the furthest distance.
//If the distance of the next robot is bigger, furthestRobot is updated.
//Distance calculated from external function in the robot class.
string game::furthest() const {
	string furthestRobot = robots.begin()->first;
	for (map<string, robot>::const_iterator iter = robots.begin(); iter != robots.end(); ++iter) {
		if (distance(iter->second) > distance(robots.at(furthestRobot))) {
			furthestRobot = iter->first;
		}
	}
	return furthestRobot;
}

//Sorting the robots in the map by distance travelled, not by map key
////Distance calculated from member function travelled, in the robot class.
bool distanceOrder(robot r1, robot r2) {
	return (r1.travelled()) < (r2.travelled());
}

//Looping through the whole map of robots to create vector's size 
//Once the vector is created, use sort built-in function to order the names of the robots according to the distances they travelled
vector<robot> game::robots_by_travelled() const {
	vector<robot> vec;
	for (map<string, robot>::const_iterator iter = robots.begin(); iter != robots.end(); ++iter) {
		vec.push_back(iter->second);
	}

	sort(vec.begin(), vec.end(), distanceOrder);
	return vec;
}

