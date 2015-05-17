#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
#include <time.h>

using namespace std;

void add_to_list(adjacency_list_t& list,Node<Obj>* currentNode, Node<Obj>* neighborNode) {
	Obj* o = neighborNode->getContents();
	int price = 1;

	// TODO: why does it jump if I simple leave out node instead of boosting price?
	if(o->getType() != WALL) {
		list[currentNode->getID()].push_back(neighbor(neighborNode->getID(), price));
	} else
	{
		// test
	}
	
}

void fill_adjacency_list(Board<Obj>& b, adjacency_list_t& list) {

	int rows = b.getRows();
	int cols = b.getCols();

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			Node<Obj>* cNode = b.getByRowCol(r, c);

			// Row above if not negative index

			if(r > 0) {
				if (c > 1)		
					add_to_list( list, cNode, b.getByRowCol( r-1, c-1) );
				if (c < cols-1)	
					add_to_list( list, cNode,  b.getByRowCol( r-1, c+1) );
				add_to_list( list, cNode, b.getByRowCol( r-1, c) );
			}

			// Same row
			if (c > 0)
				add_to_list( list, cNode, b.getByRowCol( r, c-1) );
			if (c < cols-1)	
				add_to_list( list, cNode, b.getByRowCol( r, c+1) );

			// Row below
			if (r < (rows-1)) {
				add_to_list( list, cNode, b.getByRowCol(r+1,c) );
				if (c > 1)		
					add_to_list(list, cNode, b.getByRowCol(r+1,c-1));
				if (c < cols-1)	
					add_to_list(list, cNode, b.getByRowCol(r+1,c+1));
			}
		}
	}
}


//XXX: better as static in Node?
Node<Obj>* get_pos_from_user(Board<Obj>& b, Obj* o, string msg) {

	int row;
	int col;

	cout << msg << " x: ";
	cin >> col;
	cout << msg << " y: ";
	cin >> row;
	
	return b.set(row, col, o);
}


//XXX: better as static in Node?
int get_direction(Node<Obj>* c, Node<Obj>* e, char xy) {
	if (xy == 'x') {
		if (c->getX() > e->getX() )
			return -1;
		else if (c->getX()  == e->getX() )
			return 0;
	}
		
	if (xy == 'y') {
		if (c->getY() > e->getY())
			return -1;
		else if (c->getY() == e->getY())
			return 0;
	}

	return 1;
}


void random_wall_generator(Board<Obj>& b, Obj* wallO, unsigned int walls, unsigned int maxLength) {
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

		Node<Obj>* nextNode;
		Node<Obj>* adjecent;
		// TODO: Repeted code from main in exp 1, abstract?
		while (currentNode->getX() != endNode->getX() || currentNode->getY() != endNode->getY()) 
		{
			currentNode->setContents(new Obj(WALL));
			
			// double up  wall thickness to prevent diagonal jump
			if (currentNode->getX() != (c-1)) { 
				adjecent = b.getByXY(currentNode->getX()+1, currentNode->getY());
				adjecent->setContents(new Obj(WALL));
			}

			int nextX = currentNode->getX() + get_direction(currentNode, endNode, 'x');	
			int nextY = currentNode->getY() + get_direction(currentNode, endNode, 'y');


			currentNode = b.getByXY(nextX, nextY);
		}
	}
}


#endif