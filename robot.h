#ifndef GUARD_robot_h
#define GUARD_robot_h

#include <string>

using namespace std;

class robot {

//Attributes
	string robotName;
	int x, y, travel;

//Member functions
public:
	explicit robot(const string &n);
	void move_north();
	void move_east();
	void move_south();
	void move_west();
	const string & name() const;
	int north() const;
	int east() const;
	int travelled() const;	
};

//External functions
int distance(const robot &r);

#endif


