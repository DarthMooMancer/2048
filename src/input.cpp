#include "input.hpp"
#include <ncurses.h>

void Input::get_input(bool &running, PointCollection &collection) {
	while (running) {
		initscr();
		cbreak();
		noecho();
		
		_getch = getch();
		endwin();

		if(_getch == 65) {
			_getch = 0;
			collection.set_direction('u');
		}
		else if(_getch == 66) {
			_getch = 0;
			collection.set_direction('d');
		}
		else if(_getch == 67) {
			_getch = 0;
			collection.set_direction('r');
		}
		else if(_getch == 68) {
			_getch = 0;
			collection.set_direction('l');
		}
		else if(_getch == 113) running = false;
	}
}
