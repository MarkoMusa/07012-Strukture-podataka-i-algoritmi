#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
#include <time.h>

using namespace std;

void add_to_list(adjacency_list_t& list,int index, Node<Obj>* neighborNode, int weight) {
	Obj* o = neighborNode->getContents();
	// If node is a wall we skip adding it
	if(o->getType() != WALL) {
		list[index].push_back(neighbor(neighborNode->getID(), weight));
	}
}

void fill_adjacency_list(Board<Obj>& b, adjacency_list_t& list) {
	
	// Weird problem of shortes path not found when all nodes have same weight.
	// Fixed by giving non-diagnoal nodes a slightly higher priority.
	// Apperently the fastest distance between two points is a strait line...
	int weightStrait = 10;		
	int weightDiagonal = 11;	
	int rows = b.getRows();
	int cols = b.getCols();
	
	// TODO: Abstract some sort of grid work util
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {

			Node<Obj>* cNode = b.getByRowCol(r, c);

			// No need to map for walls
			if (cNode->getContents()->getType() == WALL)
				continue;

			int index = cNode->getID();

			// Same row
			if (c > 0) 		add_to_list( list, index, b.getByRowCol( r, c-1 ), weightStrait );	// Left
			if (c < cols-1)	add_to_list( list, index, b.getByRowCol( r, c+1 ), weightStrait );	// Right

			// Row above (if on first row skip)
			if(r > 0) {
								add_to_list( list, index, b.getByRowCol( r-1, c   ), weightStrait );		// Top
				if (c > 0)		add_to_list( list, index, b.getByRowCol( r-1, c-1 ), weightDiagonal );	// Top left
				if (c < cols-1)	add_to_list( list, index, b.getByRowCol( r-1, c+1 ), weightDiagonal );	// Top right
			}

			// Row below (if on last row skip)
			if (r < (rows-1)) {
								add_to_list( list, index, b.getByRowCol( r+1, c   ), weightStrait );		// Bottom
				if (c > 0)		add_to_list( list, index, b.getByRowCol( r+1, c-1 ), weightDiagonal );	// Bottom left
				if (c < cols-1)	add_to_list( list, index, b.getByRowCol( r+1, c+1 ), weightDiagonal );	// Bottom right
			}
		}
	}
}


//XXX: better as static in Node?
Node<Obj>* get_pos_from_user(Board<Obj>& b, Obj* o, string msg) {

	int row;
	int col;

	cout << msg << " (0 - " << b.getCols() - 1 << ") x: ";
	cin >> col;
	cout << msg << " (0 - " << b.getRows() - 1 << ") y: ";
	cin >> row;
	
	return b.set(row, col, o);
}


//XXX: better as static in Node?
int get_direction(Node<Obj>* c, Node<Obj>* e, char axis) {
	if (axis == 'x') {
		if (c->getX() > e->getX() )
			return -1;
		else if (c->getX()  == e->getX() )
			return 0;
	}
		
	if (axis == 'y') {
		if (c->getY() > e->getY())
			return -1;
		else if (c->getY() == e->getY())
			return 0;
	}

	return 1;
}


void random_wall_generator(Board<Obj>& b, Obj* wall, unsigned int walls, unsigned int maxLength) {
	srand((unsigned int)time(NULL));
	for (unsigned int i = 0; i < walls; i++)
	{
		int c = b.getCols();
		int r = b.getRows();

		int wallStartX = rand() % c;
		int wallStartY = rand() % r;
		int wallEndX = rand() % maxLength;
		int wallEndY = rand() % maxLength - maxLength/2; // some negatives so all walls do not slope same way


		// Shrink end location to make sure we do not overflow
		while (wallStartX + wallEndX >= c) wallEndX--;
		while (wallStartY + wallEndY >= r) wallEndY--;
		while (wallStartY + wallEndY < 0) wallEndY++;

		Node<Obj>* currentNode = b.getByXY(wallStartX, wallStartY);
		Node<Obj>* endNode = b.getByXY(wallStartX + wallEndX, wallStartY + wallEndY);

		Node<Obj>* adjecent;
		// TODO: Repeted code from main in exp 1, abstract?
		while (currentNode->getX() != endNode->getX() || currentNode->getY() != endNode->getY()) 
		{
			currentNode->setContents(wall);
			
			// double up  wall thickness to prevent diagonal jump
			if (currentNode->getX() != (c-1)) { 
				adjecent = b.getByXY(currentNode->getX()+1, currentNode->getY());
				adjecent->setContents(wall);
			}

			int nextX = currentNode->getX() + get_direction(currentNode, endNode, 'x');	
			int nextY = currentNode->getY() + get_direction(currentNode, endNode, 'y');

			currentNode = b.getByXY(nextX, nextY);
		}
	}
}


#endif