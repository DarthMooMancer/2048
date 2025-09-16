#include "elements.hpp"
#include "globals.hpp"
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

void PointCollection::move() {
	for(int i = m_point_list.size() - 1; i >= 0; i--) {
		if(m_point_list[i].m_direction == 'u') {
			if(m_point_list[i].m_row <= 0) continue;
			m_point_list[i].assign(m_point_list[i].m_row - 1, m_point_list[i].m_col);
		} else if(m_point_list[i].m_direction == 'd') {
			if(m_point_list[i].m_row >= ROW - 1) continue;
			m_point_list[i].assign(m_point_list[i].m_row + 1, m_point_list[i].m_col);
		} else if(m_point_list[i].m_direction == 'l') {
			if(m_point_list[i].m_col <= 0) continue;
			m_point_list[i].assign(m_point_list[i].m_row, m_point_list[i].m_col - 1);
		} else if(m_point_list[i].m_direction == 'r') {
			if(m_point_list[i].m_col >= COL - 1) continue;
			m_point_list[i].assign(m_point_list[i].m_row, m_point_list[i].m_col + 1);
		}
	}
}

// bool _check_collision(Point &a, Point &b) {
// 	if(a.m_row == b.m_row && a.m_col == b.m_col && a.m_symbol == b.m_symbol) {
// 		return true;
// 	}
// 	return false;
// }

// void PointCollection::check_collision() {
	// for(int i = m_point_list.size() - 1; i >= 0; i--) {
	// 	for(int a = m_point_list.size() - 1; a >= 0; a--) {
	// 		if (i == a) continue;
	// 		_check_collision(m_point_list[i], m_point_list[a]);
			// if(m_point_list[i].m_row == m_point_list[a].m_row) {
			// 	if(m_point_list[i].m_col == m_point_list[a].m_col) {
			// 		if (m_point_list[i].m_symbol == m_point_list[a].m_symbol) {
			// 			if(m_point_list[i].m_direction == 'u') {
			// 				if(!m_point_list[a].m_collide) {
			// 					m_point_list[a].m_collide = true;
			// 					m_point_list[a].m_symbol *= 2;
			// 					m_point_list.erase(m_point_list.begin() + i);	
			// 				}
			// 				else {
			// 					m_point_list[i].m_row++;
			// 				}
			// 			}
			// 			if(m_point_list[i].m_direction == 'd') {
			// 			}
			// 			if(m_point_list[i].m_direction == 'l') {
			// 			}
			// 			if(m_point_list[i].m_direction == 'r') {
			// 			}
			// 		}
			// 	}
			// }
// 		}
// 	}
// }
