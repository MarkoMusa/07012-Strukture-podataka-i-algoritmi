#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include <sstream>
#include "Node.h"
#include "Obj.h"

using namespace std;


/// XXX: ... wanted to play with templates ended up with triple pointers ...
template<class T> class Board {
private:
	const unsigned int totRows;
	const unsigned int totCols;
	Node<T>*** board;

public:
	// Shift array over one so we are working from 1 to n+1. Can keep IDs simple this way
	Board(const int rows, const int columns): totRows(rows), totCols(columns) {

		board = new Node<T>**[getRows()];

		for (unsigned int r = 0; r < getRows(); r++) {

			board[r] = new Node<T>*[getCols()];

			for (unsigned int c = 0; c < getCols(); c++) {
				board[r][c] = new Node<T>(c, r, new T());
			}
		}		
	}

	Node<T>* set(int row, int col, T* t) {	
		(board[row][col])->setContents(t);
		return board[row][col];
	}

	unsigned int getRows() { return totRows; }
	unsigned getCols() { return totCols; }
	// TODO: Hide node behind inteface
	Node<T>* getByRowCol(int row, int col) {	
		return board[row][col];	
	}

	Node<T>* getByXY(int x, int y) {	
		return board[y][x];	
	}

	Node<T>* getNodeByID(int id) {
		  for (unsigned int r = 0; r < getRows(); r++)
			for (unsigned int c = 0; c < getCols(); c++)
				if (board[r][c]->getID() == id)
					return board[r][c];
		return nullptr;
	}

	string toString()  { 
		std::stringstream ss;
  		for (unsigned int r = 0; r < getRows(); r++) {
			for (unsigned int c = 0; c < getCols(); c++) {
					ss << board[r][c]->toString();
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