/*
	Zadatak 1: I4, 2 boda
	U prilogu je aplikacija kakvu trebate napraviti, a sastoji se od sljedećeg: prilikom pokretanja aplikacije korisnik unosi redak i
	stupac početne točke A i redak i stupac krajnje točke B (broj retka ide od 1 do 20, a broj stupca od 1 do 40). Nakon toga,
	aplikacija treba osmisliti put od točke A do točke B i svakih 100 milisekundi iscrtati gdje se trenutno nalazimo. Točka A i točka
	B se mogu nalaziti na bilo kojem dopuštenom mjestu (isprobajte kako radi aplikacija u prilogu s, primjerice, A = 1, 1 i B = 20,
	40, te kako radi s A = 20, 20 i B = 10, 10).
*/

#include <iostream>
#include <string>
#include "Point.h"
#include "Board.h"
#include <windows.h>

using namespace std;

Point get_point(string title) {

	int x;
	int y;
	string symb;

	cout << title << " row: ";
	cin >> x;
	cout << title << " col: ";
	cin >> y;

	cout << title << " display symbol: ";
	cin >> symb;

	Point p(x, y, symb);
	return p;
}

//XXX: better as static in Point?
int get_direction(Point& c, Point& e, char xy) {
	if (xy == 'x') {
		if (c.x > e.x)
			return -1;
		else if (c.x == e.x)
			return 0;
	}
		
	if (xy == 'y') {
		if (c.y > e.y)
			return -1;
		else if (c.y == e.y)
			return 0;
	}

	return 1;
}

int main() {
	const int width = 40;
	const int height = 20;
	Point c = get_point("Start");
	Point e = get_point("End");
	Board<Point> b(height, width);

	b.set(c.x, c.y, &c);
	b.set(e.x, e.y, &e);

	system("cls");
	cout << b.toString();
	while (c.x != e.x || c.y != e.y) 
	{
		int nextX = c.x + get_direction(c, e, 'x');	
		int nextY = c.y + get_direction(c, e, 'y');
		b.move(c.x, c.y, nextX, nextY);
		c.x = nextX;
		c.y = nextY;
		
		system("cls");
		cout << b.toString();
		Sleep(100);
	}


	return 0;
}