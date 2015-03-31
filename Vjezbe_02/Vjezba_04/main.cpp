/*
	Prepišite samo nazive svih država iz tekstualne datoteke
	Broj_znanstvenika_na_milijun_stanovnika.csv u binarnu
	datoteku.
*/
#include <fstream>
#include <string>
#include <iostream>

int main()
{
	std::string inputFileName = "Broj_znanstvenika_na_milijun_stanovnika.csv";
	std::string outputFileName = "Country_names.bin";

	std::ifstream ifs(inputFileName);
	if(!ifs) 
	{
		std::cout << "Error opening input file";
		return 1;
	}
	
	std::ofstream ofs(outputFileName, std::ios_base::binary);
	if(!ofs) 
	{
		std::cout << "Error opening output file";
		return 1;
	}

	std::string tmp = "";
	int len = 0;
	std::getline(ifs, tmp);				// ignore first line

	while(std::getline(ifs, tmp, ';'))
	{
		len = tmp.length();
		ofs.write((char*)&len, 4);		// Output untested, var values ok during debug
		ofs.write((char*)&tmp, len);

		std::getline(ifs, tmp);			// Get rid of rest of the line
	}

	return 0;
}