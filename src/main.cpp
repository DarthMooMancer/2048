#include <thread>
#include "input.hpp"
#include "window.hpp"
#include "elements.hpp"

int main() {
	std::srand(std::time(0));
	Input input;
	Window window;
	bool running = true;
	std::thread input_thread(&Input::get_input, &input, std::ref(running), std::ref(window.m_board));

	create_point_on_board(window.m_board);
	create_point_on_board(window.m_board);

	// Create a way to win and lose

	while (running) {
		window.tick(16);
		collide_with_adjacent_point(window.m_board);
		move_points(window.m_board);
		window.draw_window();
	}

	input_thread.join();
	return 0;
}
