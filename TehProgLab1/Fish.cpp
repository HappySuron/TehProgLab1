#include "Fish.h"
#include "CDshow.h"


Fish::Fish() {
	this->breed = "other";
	this->color = "other";
	this->food = "all-consuming";
	this->type = "Fish";
	if (S == 1) std::cout << "Fish const basic realesed" << std::endl;
}



Fish::Fish(std::string breed, std::string color, std::string food) {
	this->breed = breed;
	this->color = color;
	this->food = food;
	this->type = "Fish";
	if (S == 1) std::cout << "Fish const input realesed" << std::endl;
}

Fish::Fish(const Fish& other) {
	this->breed = other.breed;
	this->color = other.color;
	this->food = other.food;
	this->type = "Fish";
	if (S == 1) std::cout << "Animal const copy realesed" << std::endl;
}

Fish::~Fish() {
	//delete this;
	if (S == 1) std::cout << "Fish dst realesed" << std::endl;
}




void Fish::set_breed(std::string breed) {
	this->breed = breed;
}

void Fish::set_color(std::string color) {
	this->color = color;
}

void Fish::set_food(std::string food) {
	this->food = food;
}




std::string Fish::get_breed() {
	return(this->breed);
}

std::string Fish::get_color() {
	return(this->color);
}

std::string Fish::get_food() {
	return(this->food);
}

std::string Fish::get_type() {
	return(this->type);
}



void Fish::show() {
	std::cout << "Fish breed-" << this->breed << " color-" << this->color << " food-" << this->food<< std::endl;
}


void Fish::edit() {
	int feedbackIDedit;
	std::string theNewValue;
	std::cout << "What would you like to change?" << std::endl;
	std::cout << "1 - breed ";
	std::cout << "2 - color ";
	std::cout << "3 - food" << std::endl;
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
	default:
		std::cout << "Critical error" << std::endl;
	}
}