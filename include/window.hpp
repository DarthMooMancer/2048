#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "globals.hpp"
#include "elements.hpp"

struct Window {
	Point* m_board[ROW][COL] = { nullptr };
	void draw_window();
	void tick(int milliseconds);
};

#endif
