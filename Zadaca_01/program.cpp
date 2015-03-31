#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include "game_of_life.h"
using namespace std;

int main() {
	game_of_life the_game;
	int redrawPause = 1000;

	bool autorun = false;
	int choice;
	do {
		the_game.iscrtaj();
		the_game.sljedeca_generacija();
		
		if(autorun) {
			std::this_thread::sleep_for(std::chrono::milliseconds(redrawPause));
			continue;
		}
		
		cout << "Dalje (1); Autorun(2); Exit(0): ";
		cin >> choice;
		
		if(choice == 2)
			autorun = true;

	} while (choice > 0);


	do {
		the_game.iscrtaj();
		the_game.sljedeca_generacija();
		

	} while (true);

	return 0;
}