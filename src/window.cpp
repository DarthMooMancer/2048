#include "window.hpp"
#include <iomanip>
#include <iostream>
#include <thread>

void Window::tick(int milliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Window::draw_window() {
	std::cout << "\033[H" << std::flush;
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(m_board[i][j] == nullptr) std::cout << std::setw(4) << '.';
			else std::cout << std::setw(4) << m_board[i][j]->m_symbol;
		}
		std::cout << "\r\n";
	}
}
