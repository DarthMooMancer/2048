#include "elements.hpp"

void Point::assign(int row, int col) {
	m_row = row;
	m_col = col;
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
