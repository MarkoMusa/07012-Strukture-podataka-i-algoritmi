/* 
	Ispišite na konzolu nazive svih zemalja za kojih nema niti
	jednog podatka. Podaci se nalaze u datoteci
	Broj_znanstvenika_na_milijun_stanovnika.csv.
*/
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
int main()
{

	std::string inputFileName = "Broj_znanstvenika_na_milijun_stanovnika.csv";
	std::ifstream ifs(inputFileName);
	if(!ifs) 
	{
		std::cout << "Error opening input file";
		return 1;
	}
	
	std::string tmp = "";
	std::getline(ifs, tmp);				// ignore first line

	while(std::getline(ifs, tmp))
	{
		std::string countryName = "";

		std::stringstream ss(tmp);
		getline(ss, countryName, ';');

		bool hasData = false;
		while (getline(ss, tmp, ';'))
		{
			int tmpIntData = 0;

			std::stringstream tmpStream(tmp);
			tmpStream >> tmpIntData;
			if(tmpIntData != 0) {
				hasData = true;
				break;
			}
		}
		
		if(!hasData)
			std::cout << countryName << std::endl;
	}

	return 0;
}