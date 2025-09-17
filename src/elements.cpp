#include "elements.hpp"
#include <cstdlib>
#include <ctime>

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

void PointCollection::move(Point* board[ROW][COL]) {
	for(int r = 0; r < ROW; r++) {
		for(int c = 0; c < COL; c++) {
			Point *p = board[r][c];
			if(p != nullptr) {
				if(p->m_direction == 'u') {
					if(p->m_row <= 0) continue;
					if(board[p->m_row - 1][p->m_col] != nullptr) continue;
					p->m_row--;
				}
				else if(p->m_direction == 'd') {
					if(p->m_row >= ROW - 1) continue;
					if(board[p->m_row + 1][p->m_col] != nullptr) continue;
					p->m_row++;
				}
				else if(p->m_direction == 'l') {
					if(p->m_col <= 0) continue;
					if(board[p->m_row][p->m_col - 1] != nullptr) continue;
					p->m_col--;
				}
				else if(p->m_direction == 'r') {
					if(p->m_col >= COL - 1) continue;
					if(board[p->m_row][p->m_col + 1] != nullptr) continue;
					p->m_col++;
				}
			}
		}
	}
}
