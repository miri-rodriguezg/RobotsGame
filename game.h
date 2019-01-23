#ifndef GUARD_game_h
#define GUARD_game_h

#include "robot.h"
#include <vector>
#include <map>
#include <string>

class game {

//Create map of robots
	map<string, robot> robots;

//Member functions
public:
	int num_robots() const;
	void move(const string &name, int dir);
	int num_close() const;
	int max_distance() const;
	string furthest() const;
	vector<robot> robots_by_travelled() const;
};
#endif