#include "input.hpp"
#include <ncurses.h>

void Input::get_input(bool &running, Point* board[ROW][COL]) {
	while (running) {
		initscr();
		cbreak();
		noecho();
		
		_getch = getch();
		endwin();

		if(_getch == 65) {
			_getch = 0;
			set_direction('u', board);
			create_point_on_board(board);
		}
		else if(_getch == 66) {
			_getch = 0;
			set_direction('d', board);
			create_point_on_board(board);
		}
		else if(_getch == 67) {
			_getch = 0;
			set_direction('r', board);
			create_point_on_board(board);
		}
		else if(_getch == 68) {
			_getch = 0;
			set_direction('l', board);
			create_point_on_board(board);
		}
		else if(_getch == 113) running = false;
	}
}
