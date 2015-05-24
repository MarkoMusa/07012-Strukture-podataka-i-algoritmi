/*
	Zadatak 2: I3, 1 ekstra 1 bod i I4, 1 ekstra bod
	Prethodna aplikacija je odlična u slučaju kad nema neprelaznih prepreka. Međutim, ako se na igralištu pojave zidovi, morat
	ćemo mijenjati način dolaska od A do B tako da ne prolazimo kroz zidove, već da ih zaobiđemo. Druga aplikacija demonstrira
	takav način rada (isprobajte kako radi aplikacija u prilogu s A = 1, 1 i B = 1, 40 – uredno ćemo zaobići zid i stići do cilja. Navedeni
	princip vrijedi koliko god zidova postavimo na igralištu).
	Vaš zadatak je isprogramirati aplikaciju tako da se igrač na putu od A do B zaobilazi zidove i sretno stiže do odredišta. Postoji
	puno načina za to napraviti, a najjednostavniji je primjenom Dijkstrinog algoritma pronalaska najkraćeg puta:
	  Opis i primjer rada algoritma na hrvatskom:
	http://www.veleri.hr/files/datoteke/nastavni_materijali/k_promet_s1/Kvantitativne_4_Promet.pdf
	  Odlična implementacija koju smijete koristiti (smijete i druge, naravno, a možete napisati i svoju, ali ova je najkraći put
	do rješenja): http://rosettacode.org/wiki/Dijkstra%27s_algorithm
*/

#include "Dijkstra.h"
#include "Board.h"
#include "Node.h"
#include "Obj.h"
#include "Util.h"
#include <iostream>
#include <math.h>
#include <time.h>
#include <windows.h>

using namespace std;


int main() {

	const int rows = 20;				// Set field size
	const int columns = 40;
	unsigned int maxWalls = 10;			// # of walls generated
	unsigned int maxWallLength = 16;	// randomize wall length within this number

	Obj* empty = new Obj(EMPTY);
	Obj* player = new Obj(PLAYER);
	Obj* exit = new Obj(DEST);
	Obj* wall = new Obj(WALL);
	
	Board<Obj> b(rows, columns);

	// Set walls first to be overwritten by player/destination
	random_wall_generator(b, wall, maxWalls, maxWallLength);

	Node<Obj>* playerPos = get_pos_from_user(b, player, "Enter player start pos");
	Node<Obj>* exitPos = get_pos_from_user(b, exit, "Enter destination pos");
	Node<Obj>* current = playerPos;

	adjacency_list_t adjacency_list(rows * columns);
	fill_adjacency_list(b, adjacency_list);
 
    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;
    DijkstraComputePaths(playerPos->getID(), adjacency_list, min_distance, previous);
    std::list<vertex_t> path = DijkstraGetShortestPathTo(exitPos->getID(), previous);
 
	
	// Show initial state
	system("cls");
	cout << b.toString(); 

	// End early if no path found
	if (path.size() == 1)
	{
		cout << endl << endl << "NO PATH" << endl;
	} else {
		// XXX: very similar code to wall generation, abstract?
		//TODO: why does it hug north wall?
		for (std::list<vertex_t>::iterator it=path.begin(); it != path.end(); ++it) {

		
			current->setContents(empty);	// clean out old node

			current = b.getNodeByID(*it);	// get and update next
			current->setContents(player);

			system("cls");
			cout << b.toString();
			Sleep(500);
		}
	}

    return 0;
}