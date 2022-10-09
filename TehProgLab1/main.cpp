#define _CRT_SECURE_NO_WARNINGS
#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include "Keeper.h"
#include "CDshow.h"

#include <iomanip>

void main() {
	
	Keeper zxc;		// The main dinamic massiv, all the values are from the txt
	int exitCh =0;		// tipical infinate loop with checker
	int feedback=0;
	int feedbackIDdelete;
	int feedbackIDEdit;			// used futher to check what showld we do
	while (!exitCh) {
		std::cout << "What should we do now?" << std::endl;
		std::cout << "1-Show the current massiv" << std::endl;
		std::cout << "2-Add a new animal" << std::endl;
		std::cout << "3-Delete the animal by id" << std::endl;
		std::cout << "4-Edit the enimal by id" << std::endl;
		std::cout << "9-Save data to cvs" << std::endl;
		std::cout << "0-Save and Exit" << std::endl;
		
		std::cin >> feedback;
		switch (feedback)
		{
		case 1:
			system("cls");
			std::cout << zxc;			// The only place where we use << cause it was nesecery in
			break;						// the task so here it is
		case 2:
			system("cls");				// add Animal
			zxc.addAnimal();
			std::cout << "The animal was added" << std::endl;
			zxc.show();
			break;
		case 3:
			zxc.show();					// delete Animal
			std::cout << std::endl << "Enter the id (starting by 1)" << std::endl;
			std::cin >> feedbackIDdelete;
			system("cls");
			zxc.deleteAnimal(feedbackIDdelete -1);
			std::cout << "The animal was deleted" << std::endl;
			zxc.show();
			break;
		case 4:
			zxc.show();					// change animal (edit)
			std::cout << std::endl << "Enter the id (starting by 1)" << std::endl;
			std::cin >> feedbackIDEdit;
			system("cls");
			zxc.show(feedbackIDEdit - 1);
			zxc.editAnimal(feedbackIDEdit-1);
			break;
		case 0:
			zxc.saveData();				// save to the txt
			
			exitCh = 1;
			break;
		case 9:
			zxc.saveDataCVS();
			break;
		default:
			break;
		}

	}

//	Fish A;
}