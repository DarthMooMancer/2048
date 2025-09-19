#include "elements.hpp"
#include <cstdlib>
#include <ctime>

void Point::assign() {
	m_row = (rand() % ROW);
	m_col = (rand() % COL);
}

void Point::assign(int row, int col) {
	m_row = row;
	m_col = col;
}

std::string Point::to_string() {
	return "(" + std::to_string(m_row) + ", " + std::to_string(m_col) + " )\n";
}

void PointCollection::set_direction(char direction, Point* board[ROW][COL]) {
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < ROW; j++) {
			if(board[i][j] == nullptr) continue;
			board[i][j]->m_direction = direction;
		}
	}
}

void create_point_on_board(Point* board[ROW][COL]) {
	int row = (rand() % (ROW - 1));
	int col = (rand() % (COL - 1));
	if(board[row][col] == nullptr) {
		board[row][col] = new Point(row, col);
	}
}

void move(Point* board[ROW][COL]) {
	for(int r = 0; r < ROW; r++) {
		for(int c = 0; c < COL; c++) {
			Point *p = board[r][c];
			if(p != nullptr) {
				if(p->m_direction == 'u') {
					if(p->m_row <= 0) continue;
					if(board[p->m_row - 1][p->m_col] != nullptr) continue;
					p->m_row--;
				}
				else if(p->m_direction == 'd') {
					if(p->m_row >= ROW - 1) continue;
					if(board[p->m_row + 1][p->m_col] != nullptr) continue;
					p->m_row++;
				}
				else if(p->m_direction == 'l') {
					if(p->m_col <= 0) continue;
					if(board[p->m_row][p->m_col - 1] != nullptr) continue;
					p->m_col--;
				}
				else if(p->m_direction == 'r') {
					if(p->m_col >= COL - 1) continue;
					if(board[p->m_row][p->m_col + 1] != nullptr) continue;
					p->m_col++;
				}
			}
		}
	}
}

void PointCollection::collide_with_adjacent(Point* board[ROW][COL]) {
	for(int r = 0; r < ROW; r++) {
		for(int c = 0; c < COL; c++) {
			Point* p = board[r][c];
			Point* npu = board[r - 1][c];
			Point* npd = board[r + 1][c];
			Point* npl = board[r][c - 1];
			Point* npr = board[r][c + 1];
			if(p != nullptr) {
				if(p->m_direction == 'u' && npu != nullptr && npu->m_row >= 0) {
					if(p->m_symbol != npu->m_symbol) continue;
					npu->m_symbol *= 2;
					delete board[r][c];
					board[r][c] = nullptr;
					// Board is not cleared as the point still exists in m_points_list so it needs to be removed
					// I recommend adding an id to the points to track which to remove and make a function in
					// the PointCollection to remove the point
				}
				// else if(p->m_direction == 'd') {
				// 	np = board[p->m_row + 1][p->m_col];
				// 	if(np->m_row >= ROW - 1) continue;
				// 	if(np == nullptr) continue;
				// 	if(p->m_symbol != np->m_symbol) continue;
				// 	board[r][c] = nullptr;
				// 	np->m_symbol *= 2;
				// }
				// else if(p->m_direction == 'l') {
				// 	np = board[p->m_row][p->m_col - 1];
				// 	if(np->m_col <= 0) continue;
				// 	if(np == nullptr) continue;
				// 	if(p->m_symbol != np->m_symbol) continue;
				// 	board[r][c] = nullptr;
				// 	np->m_symbol *= 2;
				// }
				// else if(p->m_direction == 'r') {
				// 	np = board[p->m_row][p->m_col + 1];
				// 	if(np->m_col >= COL - 1) continue;
				// 	if(np == nullptr) continue;
				// 	if(p->m_symbol != np->m_symbol) continue;
				// 	board[r][c] = nullptr;
				// 	np->m_symbol *= 2;
				// }
			}
		}
	}
}
