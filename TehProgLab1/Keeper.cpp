#define _CRT_SECURE_NO_WARNINGS
#include "Keeper.h"
#include "CDshow.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include "Animal.h"
void Keeper::show(int id) {
	this->MAS[id]->show();
}

void Keeper::show() {
	for (int i = 0; i < countMass; i++) {
		std::cout << i+1 << " ";

		this->MAS[i]->show();
	}
}

std::ostream& operator<<(std::ostream& os, const Keeper& KP)
{
	for (int i = 0; i < KP.countMass; i++) {
		std::cout << i + 1 << " ";
		KP.MAS[i]->show();
	}
	return os;
}

void Keeper::Create() {
		MAS = new Animal * [countMass];
}

void Keeper::takeData() {
	std::ifstream workFile;
	

		workFile.open("myFile.txt");
		std::string FHstr;
		int FHcounter = 0;

		while (!workFile.eof()) {
			FHstr = "";
			getline(workFile, FHstr);
			FHcounter++;
		}
		workFile.close();
		//std::cout << FHcounter;
		MAS = new Animal * [FHcounter];

		workFile.open("myFile.txt");
		char FHchars[100];
		FHcounter = 0;
		if (workFile.peek() == std::ifstream::traits_type::eof())
			throw "empty";
		while (!workFile.eof()) {
			FHstr = "";
			getline(workFile, FHstr);
			std::strcpy(FHchars, FHstr.c_str());
			char* pch = strtok(FHchars, " ");
			//std::cout << pch;
			if (!strcmp(pch, "Fish")) {
				std::string breed;
				std::string color;
				std::string food;
				if (!workFile.eof())	breed = strtok(NULL, " "); else throw 404;
				if (!workFile.eof())	color = strtok(NULL, " "); else throw 404;
				if (!workFile.eof())	food = strtok(NULL, " "); else throw 404;
				this->MAS[FHcounter] = new Fish(breed, color, food);
				//	this->MAS[FHcounter]->show();
			}

			else if (!strcmp(pch, "Bird")) {
				std::string breed;
				std::string color;
				std::string food;
				std::string location;
				if (!workFile.eof())	breed = strtok(NULL, " "); else throw 404;
				if (!workFile.eof())	color = strtok(NULL, " "); else throw 404;
				if (!workFile.eof())	food = strtok(NULL, " "); else throw 404;
				if (!workFile.eof())	location = strtok(NULL, " "); else throw 404;
				this->MAS[FHcounter] = new Bird(breed, color, food, location);
				//	this->MAS[FHcounter]->show();
			}

			else if (!strcmp(pch, "Cat")) {
				std::string breed;
				std::string color;
				std::string owner;
				std::string name;
				if (!workFile.eof())	breed = strtok(NULL, " "); else throw 404;
				if (!workFile.eof())	color = strtok(NULL, " "); else throw 404;
				if (!workFile.eof())	owner = strtok(NULL, " "); else throw 404;
				if (!workFile.eof())	name = strtok(NULL, " "); else throw 404;
				this->MAS[FHcounter] = new Cat(breed, color, owner, name);
				//	this->MAS[FHcounter]->show();
			}
			else {
				throw 404;
			}
			FHcounter++;
			/*
			while (pch != NULL)
			{
				std::cout << pch << std::endl;
				pch = strtok(NULL, " ");
			}
			*/
		}
		this->countMass = FHcounter;
		
		
	workFile.close();
}



void Keeper::saveData() {
	std::ofstream workFile;
	workFile.open("myFile.txt", std::ofstream::out | std::ofstream::trunc);
	for (int i = 0; i < countMass; i++) {
		if (this->MAS[i]->get_type() == "Fish") {
			workFile << this->MAS[i]->get_type() << " " << this->MAS[i]->get_breed() << " " << this->MAS[i]->get_color() << " " << dynamic_cast<Fish*>(this->MAS[i])->get_food();
		}

		if (this->MAS[i]->get_type() == "Bird") {
			workFile << this->MAS[i]->get_type() << " " << this->MAS[i]->get_breed() << " " << this->MAS[i]->get_color() << " " << dynamic_cast<Bird*>(this->MAS[i])->get_food() << " " << dynamic_cast<Bird*>(this->MAS[i])->get_location();
		}

		if (this->MAS[i]->get_type() == "Cat") {
			workFile << this->MAS[i]->get_type() << " " << this->MAS[i]->get_breed() << " " << this->MAS[i]->get_color() << " " << dynamic_cast<Cat*>(this->MAS[i])->get_owner() << " " << dynamic_cast<Cat*>(this->MAS[i])->get_name();
		}
		if (i != countMass-1) workFile << std::endl;
	}

	workFile.close();
}









void Keeper::addAnimal() {
	std::cout << "Which animal whould you like to add" << std::endl;
	std::cout << "1 - Fish" << std::endl;
	std::cout << "2 - Bird" << std::endl;
	std::cout << "3 - Cat" << std::endl;
	std::string data_1;
	std::string data_2;
	std::string data_3;
	std::string data_4;
	int feedbackAddAnimal;
	int feedbackAddAnimalCustomOrDefault;
	std::cin >> feedbackAddAnimal;
	Animal** MAS_helperAdding;
	switch (feedbackAddAnimal)
	{
		case 1:
			MAS_helperAdding = new Animal * [countMass + 1];
			for (int i = 0; i < countMass; i++) {
				MAS_helperAdding[i] = MAS[i];
			}
			std::cout << "Do you want to add a custom or default one?" << std::endl;
			std::cout << "1 - default" << std::endl;
			std::cout << "2 - custom" << std::endl;
			std::cin >> feedbackAddAnimalCustomOrDefault;
			switch (feedbackAddAnimalCustomOrDefault) {
			case 1:
				MAS_helperAdding[countMass] = new Fish();
				break;
			case 2:
				std::cout << "Enter breed" << std::endl;
				std::cin >> data_1;
				std::cout << "Enter color" << std::endl;
				std::cin >> data_2;
				std::cout << "Enter food" << std::endl;
				std::cin >> data_3;
				MAS_helperAdding[countMass] = new Fish(data_1, data_2, data_3);
				break;
			default:
				std::cout << "Critical error" << std::endl;
				std::cout << "To escape total error default one was added" << std::endl;
				MAS_helperAdding[countMass] = new Fish();
				break;
			}
			
			delete[] MAS;
			countMass++;
			MAS = MAS_helperAdding;
			break;
		case 2:
			
			MAS_helperAdding = new Animal * [countMass + 1];
			for (int i = 0; i < countMass; i++) {
				MAS_helperAdding[i] = MAS[i];
			}
			std::cout << "Do you want to add a custom or default one?" << std::endl;
			std::cout << "1 - default" << std::endl;
			std::cout << "2 - custom" << std::endl;
			std::cin >> feedbackAddAnimalCustomOrDefault;
			switch (feedbackAddAnimalCustomOrDefault) {
			case 1:
				MAS_helperAdding[countMass] = new Bird();
				break;
			case 2:
				std::cout << "Enter breed" << std::endl;
				std::cin >> data_1;
				std::cout << "Enter color" << std::endl;
				std::cin >> data_2;
				std::cout << "Enter food" << std::endl;
				std::cin >> data_3;
				std::cout << "Enter location" << std::endl;
				std::cin >> data_4;
				MAS_helperAdding[countMass] = new Bird(data_1, data_2, data_3, data_4);
				break;
			default:
				std::cout << "Critical error" << std::endl;
				std::cout << "To escape total error default one was added" << std::endl;
				MAS_helperAdding[countMass] = new Bird();
				break;
			}
			delete[] MAS;
			countMass++;
			MAS = MAS_helperAdding;
			break;
		case 3:
			MAS_helperAdding = new Animal * [countMass + 1];
			for (int i = 0; i < countMass; i++) {
				MAS_helperAdding[i] = MAS[i];
			}std::cout << "Do you want to add a custom or default one?" << std::endl;
			std::cout << "1 - default" << std::endl;
			std::cout << "2 - custom" << std::endl;
			std::cin >> feedbackAddAnimalCustomOrDefault;
			switch (feedbackAddAnimalCustomOrDefault) {
			case 1:
				MAS_helperAdding[countMass] = new Cat();
				break;
			case 2:
				std::cout << "Enter breed" << std::endl;
				std::cin >> data_1;
				std::cout << "Enter color" << std::endl;
				std::cin >> data_2;
				std::cout << "Enter owner" << std::endl;
				std::cin >> data_3;
				std::cout << "Enter name" << std::endl;
				std::cin >> data_4;
				MAS_helperAdding[countMass] = new Cat(data_1, data_2, data_3, data_4);
				break;
			default:
				std::cout << "Critical error" << std::endl;
				std::cout << "To escape total error default one was added" << std::endl;
				MAS_helperAdding[countMass] = new Cat();
				break;
			}
			delete[] MAS;
			countMass++;
			MAS = MAS_helperAdding;
			break;
	default:
		std::cout << "Critical mistake." << std::endl;
		break;
	}
}

void Keeper::deleteAnimal(int id) {
	Animal** MAS_helperDelete;
	MAS_helperDelete = new Animal * [countMass - 1];
	int i = 0;
	for (i = 0; i < id; i++) {
		MAS_helperDelete[i] = MAS[i];
	}
	for (int j = i+1; j < countMass; j++) {
		MAS_helperDelete[j-1] = MAS[j];
	}
	
	//for (int i = 0; i < countMass; ++i) {
	//	delete MAS[i];
	//}
	this->MAS[id]->~Animal();
	delete[] MAS;
	countMass--;
		MAS = MAS_helperDelete;
		int x = 1;
}

void Keeper::editAnimal(int id) {
	this->MAS[id]->edit();
}


void Keeper::saveDataCVS() {
	std::ofstream outData;
	outData.open("outfile.csv", std::ofstream::out | std::ofstream::trunc);
	for (int i = 0; i < countMass; i++) {
		if (this->MAS[i]->get_type() == "Fish") {
			outData << this->MAS[i]->get_type() << ";" << this->MAS[i]->get_breed() << ";" << this->MAS[i]->get_color() << ";" << dynamic_cast<Fish*>(this->MAS[i])->get_food();
		}
		if (this->MAS[i]->get_type() == "Bird") {
			outData << this->MAS[i]->get_type() << ";" << this->MAS[i]->get_breed() << ";" << this->MAS[i]->get_color() << ";" << dynamic_cast<Bird*>(this->MAS[i])->get_food() << ";" << dynamic_cast<Bird*>(this->MAS[i])->get_location();
		}

		if (this->MAS[i]->get_type() == "Cat") {
			outData << this->MAS[i]->get_type() << ";" << this->MAS[i]->get_breed() << ";" << this->MAS[i]->get_color() << ";" << dynamic_cast<Cat*>(this->MAS[i])->get_owner() << ";" << dynamic_cast<Cat*>(this->MAS[i])->get_name();
		}
		if (i != countMass - 1) outData << std::endl;
	}
	outData.close();
}