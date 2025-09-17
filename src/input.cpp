#include "input.hpp"
#include <ncurses.h>

void Input::get_input(bool &running, PointCollection &collection, Point* board[ROW][COL]) {
	while (running) {
		initscr();
		cbreak();
		noecho();
		
		_getch = getch();
		endwin();

		if(_getch == 65) {
			_getch = 0;
			for(int i = 0; i < collection.m_point_list.size() - 1; i++) {
				if(!collection.m_point_list[i].m_collide) {
					collection.m_point_list[i].m_collide = true;
				}
			}
			collection.set_direction('u');
			collection.m_point_list.push_back(Point());
			collection.m_point_list.back().assign();
		}
		else if(_getch == 66) {
			_getch = 0;
			for(int i = 0; i < collection.m_point_list.size() - 1; i++) {
				if(!collection.m_point_list[i].m_collide) {
					collection.m_point_list[i].m_collide = true;
				}
			}
			collection.set_direction('d');
			collection.m_point_list.push_back(Point());
			collection.m_point_list.back().assign();
		}
		else if(_getch == 67) {
			_getch = 0;
			for(int i = 0; i < collection.m_point_list.size() - 1; i++) {
				if(!collection.m_point_list[i].m_collide) {
					collection.m_point_list[i].m_collide = true;
				}
			}
			collection.set_direction('r');
			collection.m_point_list.push_back(Point());
			collection.m_point_list.back().assign();
		}
		else if(_getch == 68) {
			_getch = 0;
			for(int i = 0; i < collection.m_point_list.size() - 1; i++) {
				if(!collection.m_point_list[i].m_collide) {
					collection.m_point_list[i].m_collide = true;
				}
			}
			collection.set_direction('l');
			collection.m_point_list.push_back(Point());
			collection.m_point_list.back().assign();
		}
		else if(_getch == 113) running = false;
	}
}
