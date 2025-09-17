#include "elements.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

void Point::assign() {
	std::srand(std::time(0));
	m_row = (rand() % (ROW));
	m_col = (rand() % (ROW));
}

void Point::assign(int row, int col) {
	m_row = row;
	m_col = col;
}

std::string Point::to_string() {
	return "(" + std::to_string(m_row) + ", " + std::to_string(m_col) + " )\n";
}

void PointCollection::set_direction(char direction) {
	for(int i = m_point_list.size() - 1; i >= 0; i--) {
		m_point_list[i].m_direction = direction; 
	}
}

void PointCollection::move(Point* m_board[ROW][COL]) {
	for(int i = m_point_list.size() - 1; i >= 0; i--) {
		Point &p = m_point_list[i];

		int cur_row = p.m_row;
		int cur_col = p.m_col;
		int new_row = cur_row;
		int new_col = cur_col;

		if(p.m_direction == 'u') {
			Point *target = m_board[p.m_row - 1][p.m_col];
			if(target == nullptr && p.m_row >= 0) {
				new_row--;
			}
			else if(target->m_symbol == m_board[cur_row][cur_col]->m_symbol
					&& !target->m_collide) {
				target->m_symbol *= 2;
				target->m_collide = true;
				m_board[cur_row][cur_col] = nullptr;
				continue;
			}
		}
		else if(p.m_direction == 'd') {
			Point *target = m_board[p.m_row + 1][p.m_col];

			if(target == nullptr && p.m_row < ROW) {
				new_row++;
			}
			else if(target->m_symbol == m_board[cur_row][cur_col]->m_symbol
					&& !target->m_collide) {
				target->m_symbol *= 2;
				target->m_collide = true;
				m_board[cur_row][cur_col] = nullptr;
				continue;
			}
		} else if(p.m_direction == 'l') {
			Point *target = m_board[p.m_row][p.m_col - 1];

			if(target == nullptr && p.m_col >= 0) {
				new_col--;
			}
			else if(target->m_symbol == m_board[cur_row][cur_col]->m_symbol
					&& !target->m_collide) {
				target->m_symbol *= 2;
				target->m_collide = true;
				m_board[cur_row][cur_col] = nullptr;
				continue;
			}
		} else if(p.m_direction == 'r') {
			Point *target = m_board[p.m_row][p.m_col + 1];

			if(target == nullptr && p.m_col < ROW) {
				new_col++;
			}
			else if(target->m_symbol == m_board[cur_row][cur_col]->m_symbol
					&& !target->m_collide) {
				target->m_symbol *= 2;
				target->m_collide = true;
				m_board[cur_row][cur_col] = nullptr;
				continue;
			}
		}
		m_board[p.m_row][p.m_col] = nullptr;
		p.assign(new_row, new_col);
		m_board[new_row][new_col] = &p;
	}
}
