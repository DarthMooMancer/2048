#include <iostream>
#include <thread>
#include "input.hpp"
#include "window.hpp"
#include "elements.hpp"

bool _check_collision(Point &a, Point &b) {
	if(a.m_row == b.m_row && a.m_col == b.m_col && a.m_symbol == b.m_symbol) {
		return true;
	}
	return false;
}

int main() {
	Input input;
	Window window;
	PointCollection collection;
	bool running = true;
	std::thread input_thread(&Input::get_input, &input, std::ref(running), std::ref(collection));

	collection.m_point_list.push_back(Point());
	collection.m_point_list.back().assign();

	while (running) {
		// collection.check_collision();
		collection.move();
		window.draw_window(collection);
		for(int i = collection.m_point_list.size() - 1; i >= 0; i--) {
			for(int a = collection.m_point_list.size() - 1; a >= 0; a--) {
				if (i == a) continue;
				if(_check_collision(collection.m_point_list[i], collection.m_point_list[a])) {
					std::cout << "Collision with " << collection.m_point_list[i].to_string() << " & " << collection.m_point_list[a].to_string() << "\n";
				}
			}
		}
		std::cout << collection.m_point_list.size() << "\n";
	}

	input_thread.join();
	return 0;
}
