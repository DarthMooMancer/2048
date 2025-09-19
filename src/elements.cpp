#include "elements.hpp"
#include <cstdlib>
#include <ctime>

void set_direction(char direction, Point* board[ROW][COL]) {
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < ROW; j++) {
			if(board[i][j] == nullptr) continue;
			board[i][j]->m_direction = direction;
		}
	}
}

void create_point_on_board(Point* board[ROW][COL]) {
	int row, col;
	do {
		row = (rand() % ROW);
		col = (rand() % COL);
	} while (board[row][col] != nullptr);
	board[row][col] = new Point(row, col);
}

void move_points(Point* board[ROW][COL]) {
	for(int r = 0; r < ROW; r++) {
		for(int c = 0; c < COL; c++) {
			Point *p = board[r][c];
			if(p != nullptr) {
				int new_row = p->m_row;
				int new_col = p->m_col;
				if(p->m_direction == 'u') {
					if(p->m_row <= 0) continue;
					if(board[p->m_row - 1][p->m_col] != nullptr) continue;
					new_row = p->m_row - 1;
				}
				else if(p->m_direction == 'd') {
					if(p->m_row >= ROW - 1) continue;
					if(board[p->m_row + 1][p->m_col] != nullptr) continue;
					new_row = p->m_row + 1;
				}
				else if(p->m_direction == 'l') {
					if(p->m_col <= 0) continue;
					if(board[p->m_row][p->m_col - 1] != nullptr) continue;
					new_col = p->m_col - 1;
				}
				else if(p->m_direction == 'r') {
					if(p->m_col >= COL - 1) continue;
					if(board[p->m_row][p->m_col + 1] != nullptr) continue;
					new_col = p->m_col + 1;
				}
				if(new_row != p->m_row || new_col != p->m_col) {
					board[new_row][new_col] = p;
					board[p->m_row][p->m_col] = nullptr;
					p->m_row = new_row;
					p->m_col = new_col;
				}
			}
		}
	}
}

void collide_with_adjacent_point(Point* board[ROW][COL]) {
	for(int r = 0; r < ROW; r++) {
		for(int c = 0; c < COL; c++) {
			Point* p = board[r][c];
			Point* npu = board[r - 1][c];
			Point* npd = board[r + 1][c];
			Point* npl = board[r][c - 1];
			Point* npr = board[r][c + 1];
			if(p != nullptr) {
				if(p->m_direction == 'u' && npu != nullptr && npu->m_direction == 'u' && npu->m_row >= 0) {
					if(p->m_symbol != npu->m_symbol) continue;
					npu->m_symbol *= 2;
					delete board[r][c];
					board[r][c] = nullptr;
				}
				else if(p->m_direction == 'd' && npd != nullptr && npd->m_direction == 'd' && npd->m_row < ROW) {
					if(p->m_symbol != npd->m_symbol) continue;
					npd->m_symbol *= 2;
					delete board[r][c];
					board[r][c] = nullptr;
				}
				else if(p->m_direction == 'l' && npl != nullptr && npl->m_direction == 'l' && npl->m_col >= 0) {
					if(p->m_symbol != npl->m_symbol) continue;
					npl->m_symbol *= 2;
					delete board[r][c];
					board[r][c] = nullptr;
				}
				else if(p->m_direction == 'r' && npr != nullptr && npr->m_direction == 'r' && npr->m_col < COL) {
					if(p->m_symbol != npr->m_symbol) continue;
					npr->m_symbol *= 2;
					delete board[r][c];
					board[r][c] = nullptr;
				}
			}
		}
	}
}
