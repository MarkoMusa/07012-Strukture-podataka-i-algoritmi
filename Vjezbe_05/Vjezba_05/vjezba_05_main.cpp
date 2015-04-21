/*
	Napišite program koji korisniku u petlji nudi opcije:
	o Upis novog broja
	o Slanje svih do sada upisanih brojeva u datoteku
	o Kraj rada
	Unesene brojeve čuvajte u prikladnom tipu podataka.
	Zadavanjem naredbe za slanje brojeva u datoteku se podaci
	upisani podaci iz memorije upisuju u tekstualnu datoteku te je
	memorija spremnaza upis novih podataka.
*/
#include <iostream>
#include <vector>
#include <fstream>
#include "red_dinamicki.h"

using namespace std;

enum MenuOptions { ADD, SAVE, EXIT };

void show_main()
{
	cout << "---- Menu ----" << endl;
	cout << ADD << " = add number" << endl;
	cout << SAVE << " = write numbers to file" << endl;
	cout << EXIT << " = exit" << endl;
}
int get_menu_choice()
{
	system("cls");
	show_main();
	cout << "Enter option number: ";
	int opt;
	cin >> opt;
	return opt;
}
void get_and_add_number(red_dinamicki& n)
{
	ELTYPE number;
	cout << "Enter number: ";
	cin >> number;
	n.enqueue(number);
}
void save_to_file(red_dinamicki& n, ofstream& ofs)
{
	ELTYPE e;
	while(n.dequeue(e))
		ofs << e << endl;

	cout << "Saved";
}

int main()
{
	ofstream ofs("numbers.txt");
	if (!ofs)
	{
		cout << "error saving to numbers.txt";
		return 1;
	}

	bool cont = true;
	red_dinamicki numbers;
	while (cont)
	{
		int option;
		option = get_menu_choice();
		switch (option)
		{
			case ADD:	
				get_and_add_number(numbers);
				break;
			case SAVE:
				save_to_file(numbers, ofs);
				break;
			case EXIT: 
				cont = false;
				break;
			default:
				cout << "Incorrect option";
				break;
		}
	}
	ofs.close();
	return 0;
}