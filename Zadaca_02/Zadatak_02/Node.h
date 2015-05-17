#ifndef _NODE_H_
#define _NODE_H_

using namespace std;

template<class T> class Node {
private:
	static int objectCount;
	unsigned long int id;
	int x;
	int y;
	T* obj;
public:
	
	Node(int x, int y, T* obj): x(x), y(y), obj(obj) {
		id = objectCount++;
	}
	int getID() { return id; }
	int getX() { return x; }
	int getY() { return y; }
	T* getContents()	{ return obj; } 
	void setContents(T* o) { obj = o; }
	string toString() { return obj->toString(); }
};
template<class T> int Node<T>::objectCount = 0;

#endif