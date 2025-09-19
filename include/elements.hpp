#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include "globals.hpp"

struct Point {
	Point(int row, int col) : m_row(row), m_col(col), m_symbol(2), m_direction(' '), m_collide(false) {};
	int m_row;
	int m_col;
	char m_direction;
	int m_symbol;
	bool m_collide;
};

void move_points(Point* board[ROW][COL]);
void create_point_on_board(Point* board[ROW][COL]);
void collide_with_adjacent_point(Point* board[ROW][COL]);
void set_direction(char direction, Point* board[ROW][COL]);

#endif
