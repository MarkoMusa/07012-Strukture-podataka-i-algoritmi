#ifndef _OBJ_H_
#define _OBJ_H_

using namespace std;

enum ObjectType { PLAYER, DEST, WALL, EMPTY };

class Obj {
private:
	int TYPE;

public:
	Obj() {
		TYPE = EMPTY;
	}
	Obj(const int type) {
		TYPE = type;
	}

	int getType() { return TYPE; }

	string toString()  { 
		switch(TYPE) {
		case PLAYER: 
			return "X";
		case DEST: 
			return "O";
		case WALL:
			return "#";
		case EMPTY:
			return " ";
		}
	}
};

#endif