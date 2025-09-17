#include <iostream>
#include <thread>
#include "input.hpp"
#include "window.hpp"
#include "elements.hpp"

int main() {
	Input input;
	Window window;
	PointCollection collection;
	bool running = true;
	std::thread input_thread(&Input::get_input, &input, std::ref(running), std::ref(collection), std::ref(window.m_board));

	collection.m_point_list.push_back(Point());
	collection.m_point_list.back().assign();

	while (running) {
		collection.move(window.m_board);
		window.draw_window(collection);
	}

	input_thread.join();
	return 0;
}
