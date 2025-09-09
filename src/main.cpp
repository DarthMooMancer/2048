#include <iostream>
#include <thread>
#include "input.hpp"
#include "window.hpp"

int main() {
	Input input;
	Window window;
	bool running = true;
	std::thread input_thread(&Input::get_input, &input, std::ref(running));


	window.m_board[0][0] = 4;
	while (running) {
		window.draw_window();
	}

	input_thread.join();
	return 0;
}
