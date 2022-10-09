#include "Cat.h"
#include "CDshow.h"


Cat::Cat() {
	this->breed = "other";
	this->color = "other";
	this->owner = "Rayan_Aleksandrovich_Gosling";
	this->name = "Catname";
	this->type = "Cat";
	if (S == 1) std::cout << "Cat const basic realesed" << std::endl;
}



Cat::Cat(std::string breed, std::string color, std::string owner, std::string name) {
	this->breed = breed;
	this->color = color;
	this->owner = owner;
	this->name = name;
	this->type = "Cat";
	if (S == 1) std::cout << "Cat const input realesed" << std::endl;
}

Cat::Cat(const Cat& other) {
	this->breed = other.breed;
	this->color = other.color;
	this->owner = other.owner;
	this->name = other.name;
	this->type = "Cat";
	if (S == 1) std::cout << "Cat const copy realesed" << std::endl;
}




Cat::~Cat() {
	//delete this;
	if (S == 1) std::cout << "Cat dst realesed" << std::endl;
}




void Cat::set_breed(std::string breed) {
	this->breed = breed;
}

void Cat::set_color(std::string color) {
	this->color = color;
}

void Cat::set_owner(std::string owner) {
	this->owner= owner;
}


void Cat::set_name(std::string location) {
	this->name = location;
}


std::string Cat::get_breed() {
	return(this->breed);
}

std::string Cat::get_color() {
	return(this->color);
}

std::string Cat::get_owner() {
	return(this->owner);
}

std::string Cat::get_name() {
	return(this->name);
}

std::string Cat::get_type() {
	return(this->type);
}

void Cat::show() {
	std::cout << "Cat breed-" << this->breed << " color-" << this->color << " owner-" << this->owner << " name-" << this->name << std::endl;
}

void Cat::edit() {
	int feedbackIDedit;
	std::string theNewValue;
	std::cout << "What would you like to change?" << std::endl;
	std::cout << "1 - breed ";
	std::cout << "2 - color ";
	std::cout << "3 - owner ";
	std::cout << "4 - name" << std::endl;
	std::cin >> feedbackIDedit;
	switch (feedbackIDedit) {
	case 1:
		std::cout << "Enter the new data" << std::endl;
		std::cin >> theNewValue;
		this->set_breed(theNewValue);
		break;
	case 2:
		std::cout << "Enter the new data" << std::endl;
		std::cin >> theNewValue;
		this->set_color(theNewValue);
		break;
	case 3:
		std::cout << "Enter the new data" << std::endl;
		std::cin >> theNewValue;
		this->set_owner(theNewValue);
		break;
	case 4:
		std::cout << "Enter the new data" << std::endl;
		std::cin >> theNewValue;
		this->set_name(theNewValue);
		break;
	default:
		std::cout << "Critical error" << std::endl;
	}
}