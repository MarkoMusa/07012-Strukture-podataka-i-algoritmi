#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include <sstream>

using namespace std;

/// XXX: ... wanted to play with templates ended up with triple pointers ...
template<class T> class Board {
private:
	const unsigned int width;
	const unsigned int height;
	T*** board;

public:
	Board(const int height, const int width): width(width), height(height) {
		board = new T**[height];
		for (int i = 0; i < height; i++) {
			board[i] = new T*[width];
			for (int j = 0; j < width; j++)
				board[i][j] = nullptr;
		}
	}

	void set(int x, int y, T* t) {
		board[y][x] = t;
	}
	void move(int x1, int y1, int x2, int y2) {
		board[y2][x2] = board[y1][x1];
		board[y1][x1] = nullptr;
	}

	string toString()  { 
		std::stringstream ss;
  		for (unsigned int i = 0; i < height; i++) {
			for (unsigned int j = 0; j < width; j++) {
				if (board[i][j] == nullptr)
					ss << "-";
				else
					ss << board[i][j]->toString();
			}
			ss << endl;
		}
	  return ss.str();
	}
	~Board() {
		delete[] board;
	}
};

#endif