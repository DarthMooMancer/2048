#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "globals.hpp"
#include <array>

struct Window {
	std::array<std::array<int, COL>, ROW> m_board = {};
	void draw_window();
};

#endif
