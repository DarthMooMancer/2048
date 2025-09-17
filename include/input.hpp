#ifndef INPUT_HPP
#define INPUT_HPP

#include "elements.hpp"
#include "globals.hpp"

struct Input {
	int _getch;
	void get_input(bool &running, PointCollection &collection, Point* board[ROW][COL]);
};

#endif
