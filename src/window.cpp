#include "window.hpp"
#include <iomanip>
#include <iostream>
#include <thread>

void Window::draw_window(PointCollection &collection) {
	for(Point** row = m_board[0]; row != m_board[0] + 16; row++) { *row = nullptr; }
	for(int i = collection.m_point_list.size() - 1; i >= 0; i--) {
		m_board[collection.m_point_list[i].m_row][collection.m_point_list[i].m_col] = &collection.m_point_list[i];
	}
	std::cout << "\033[H" << std::flush;
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(m_board[i][j] == nullptr) std::cout << std::setw(4) << '.';
			else std::cout << std::setw(4) << m_board[i][j]->m_symbol;
		}
		std::cout << "\r\n";
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(16));
}
