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
void get_and_add_number(vector<double>& n)
{
	double number;
	cout << "Enter number: ";
	cin >> number;
	n.push_back(number);
}
void save_to_file(vector<double>& n)
{
	ofstream ofs("numbers.txt");
	if (!ofs)
	{
		cout << "error saving to numbers.txt";
		return;
	}

	double number;
	for (int i = 0; i < n.size(); i++)
	{
		ofs << n[i] << endl;
	}
	cout << "Saved";
	n.clear();
}

int main()
{
	vector<double> numbers;
	while (true)
	{
		int option;
		option = get_menu_choice();
		switch (option)
		{
			case ADD:	
				get_and_add_number(numbers);
				break;
			case SAVE:
				save_to_file(numbers);
				break;
			case EXIT: 
				return 0;
			default:
				cout << "Incorrect option";
				break;
		}
	}

	return 0;
}