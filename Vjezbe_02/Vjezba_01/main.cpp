/* 
	Definirajte tip podataka za čuvanje podataka o točkama(x, y) te 
	definirajte operaciju za izračun udaljenosti točke od ishodišta (d = 𝑥2−𝑥12+𝑦2−𝑦12). 
	Napravite poljeod
		a.1.000
		b.10.000
		c.20.000
		d.*100.000 –obratite pažnju na sadržaj datoteke. U čemuje problem i kako ga možemo riješiti? točaka te u datoteku ispišite udaljenost svake od njih do ishodišta u obliku:
d(x, y) = udaljenost
Neka x i y svake točke budu jednaki indeksu točke. Ispišiteu konzolu koliko milisekundi je izračun udaljenosti trajao.
*/
#include "high_res_timer.h"
#include "Point.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

void fillPoints(Point arr[], int length) {

	for (int i = 0; i < length; i++)
		arr[i].init(i+1,i+1);

}

int writePoints(std::string fn, Point arr[], int length) {
	std::ofstream ofs(fn);
	if (!ofs)
	{
		std::cout << "Error opening file";
		return 1;
	}

	for (int i = 0; i < length; i++) 
	{
		Point* p = &arr[i];
		ofs << "d(" << p->getX() << ", " << p->getY() << ") = " << p->getDistanceFromOrigin() << std::endl;
	}

	ofs.close();
	return 0;
}


int main() {
	std::string fn = "file.txt";
	std::vector<std::pair<Point*, int>> data;
	hr_timer timer;

	data.push_back(std::make_pair(new Point[1000], 1000));
	data.push_back(std::make_pair(new Point[10000], 10000));
	data.push_back(std::make_pair(new Point[20000], 20000));
	data.push_back(std::make_pair(new Point[100000], 100000));

	for (unsigned int i = 0; i < data.size(); i++) {
		fillPoints(data[i].first, data[i].second);

		start_hr_timer(timer);
		int failFileWrite = writePoints(fn, data[i].first, data[i].second);
		stop_hr_timer(timer);

		std::cout << "Time for " << data[i].second << " Points : " << get_elapsed_time_microsec(timer) / 1000 << " ms" << std::endl;

		delete[] data[i].first;
		if(failFileWrite)
			return 1;
	}
	return 0;
}