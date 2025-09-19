#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <vector>
#include <string>
#include "globals.hpp"

struct Point;
void move(Point* board[ROW][COL]);
void create_point_on_board(Point* board[ROW][COL]);

struct Point {
	Point() : m_row(0), m_col(0), m_symbol(2), m_direction('n') {};
	Point(int row, int col) : m_row(row), m_col(col), m_symbol(2), m_direction('n') {};
	char m_direction;
	int m_row;
	int m_col;
	int m_symbol;
	void assign();
	void assign(int row, int col);
	std::string to_string();
};

struct PointCollection {
	std::vector<Point> m_point_list;
	void collide_with_adjacent(Point* board[ROW][COL]);
	void set_direction(char direction, Point* board[ROW][COL]);
};

#endif
