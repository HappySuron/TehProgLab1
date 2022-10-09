#pragma once
#include "Animal.h"
#include "CDshow.h"

class Keeper
{
public:
	Animal** MAS;
	int countMass;

public:
	Keeper() {
		try {
			takeData();
		}
		catch (int exCode) {
			std::cout << "File seemes to be broken" << std::endl;
			std::cout << "The programm cannot take info" << std::endl;
			std::cout << "It will be considered that there is no data" << std::endl;
			std::cout << "All the current data will be deleted" << std::endl;
		}
		catch (const char * txtEx)
		{
			std::cout << "The file is empty" << std::endl;
			std::cout << "It will be considered that there is no data" << std::endl;
		}
		if (S == 1)	 std::cout << "Keeper const realesed" << std::endl;
	}

	//Keeper(const Keeper& other);

	~Keeper() { 
		for (int i = 0; i < countMass; ++i) {
		delete MAS[i];
	}
	if (S == 1) std::cout << "Keeper destr realesed" << std::endl;
	}

	void show(int id);
	void show();
	void takeData();
	void saveData();



	void addAnimal();
	void deleteAnimal(int id);


	void editAnimal(int id);

	friend std::ostream& operator<<(std::ostream& os, const Keeper& dt);

	void saveDataCVS();
};


