#include "Bird.h"
#include "CDshow.h"

Bird::Bird() {
	this->breed = "other";
	this->color = "other";
	this->food = "all-consuming";
	this->location = "other";
	this->type = "Bird";
	if (S == 1) std::cout << "Bird const basic realesed" << std::endl;
}



Bird::Bird(std::string breed, std::string color, std::string food, std::string location) {
	this->breed = breed;
	this->color = color;
	this->food = food;
	this->location = location;
	this->type = "Bird";
	if (S == 1) std::cout << "Bird const input realesed" << std::endl;
}


Bird::Bird(const Bird& other) {
	this->breed = other.breed;
	this->color = other.color;
	this->food = other.food;
	this->location = other.location;
	this->type = "Bird";
	if (S == 1) std::cout << "Bird const copy realesed" << std::endl;

}



Bird::~Bird() {
	//delete this;
	if (S == 1) std::cout << "Bird dst realesed" << std::endl;
}




void Bird::set_breed(std::string breed) {
	this->breed = breed;
}

void Bird::set_color(std::string color) {
	this->color = color;
}

void Bird::set_food(std::string food) {
	this->food = food;
}

void Bird::set_location(std::string location) {
	this->location = location;
}


std::string Bird::get_breed() {
	return(this->breed);
}

std::string Bird::get_color() {
	return(this->color);
}

std::string Bird::get_food() {
	return(this->food);
}

std::string Bird::get_location() {
	return(this->location);
}

std::string Bird::get_type() {
	return(this->type);
}


void Bird::show() {
	std::cout << "Bird breed-" << this->breed << " color-" << this->color << " food-" << this->food << " location-" << this->location << std::endl;
}

void Bird::edit() {
	int feedbackIDedit;
	std::string theNewValue;
	std::cout << "What would you like to change?" << std::endl;
	std::cout << "1 - breed ";
	std::cout << "2 - color ";
	std::cout << "3 - food ";
	std::cout << "4 - location" << std::endl;
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
		this->set_food(theNewValue);
		break;
	case 4:
		std::cout << "Enter the new data" << std::endl;
		std::cin >> theNewValue;
		this->set_location(theNewValue);
		break;
	default:
		std::cout << "Critical error" << std::endl;
	}
}