/*
Napišite program koji korisniku omogućava sljedeće
opcije: napisati i spremiti e-mail, poslati sve napisane e-
mailove te završetak rada. Kad korisnik odabere pisanje i
spremanja e-maila, potrebno ga je tražiti da upiše naslov,
sadržaj te prioritet e-maila (0 = standardno, -3 = nevažno,
3 = jako važno). Kad korisnik odabere slanje svih dotada
napisanih e-mailova, potrebno je obraditi (ispisati)
upisane e-mailove prema njihovim prioritetima.
*/

#include <iostream>
#include "prioritetni_red.h"

using namespace std;


void show_menu(){
	cout << "-- Menu --" << endl;
	cout << " (w)rite and save" << endl;
	cout << " (s)end email(s) " << endl;
}

char get_menu_choice(){
	show_menu();
	char choice = 'x';

	while (choice != 'w' && choice != 's')
			cin >> choice;
	cin.ignore();

	return choice;
}

ELTYPE get_new_email() {
	char sel; 
	ELTYPE e;

	cout << "to: ";
	getline(cin, e.to);

	cout << "from: ";
	getline(cin, e.from);

	cout << "subject: ";
	getline(cin, e.subject);

	cout << "message: ";
	getline(cin, e.body);

	cout << "priority [(h)igh, (l)ow]: ";
	cin >> sel;
	switch (sel)
	{
	case 'h':
		e.priority = 3;
		break;
	case 'l':
		e.priority = -3;
		break;
	default:
		e.priority = 0;
		break;
	}
	return e;
}

void send_emails(prioritetni_red& r) {
	while (!r.is_empty())
	{
		ELTYPE e;
		r.dequeue(e);
		cout << "---------------------------------" << endl;
		cout << "From: " << e.from  << endl;
		cout << "To: " << e.to  << endl;
		cout << "Subject: " << e.subject  << endl;
		cout << "Body: " << e.body  << endl;
		cout << "Priority: " << e.priority  << endl;
	}

}

int main() {
	prioritetni_red r;

	while (true)
	{
		char selection = get_menu_choice();
		if (selection == 'w')
		{
			ELTYPE e = get_new_email();
			r.enqueue(e, e.priority);
		} else if (selection == 's')
		{
			send_emails(r);
		}
	}


}