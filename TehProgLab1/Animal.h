#pragma once
#include "CDshow.h"
#include "CDshow.h"
class Animal
{
protected:
	std::string type;
public:
		Animal() {
			if (S == 1) std::cout << "Animal const realesed" << std::endl;
		};			
		virtual ~Animal(){
			if (S == 1) std::cout << "Animal dst realesed" << std::endl;
		//	delete this;
		};		

		virtual void set_color(std::string) = 0;
		virtual void set_breed(std::string) = 0;

		virtual std::string get_color() = 0;
		virtual std::string get_breed() = 0;
		virtual std::string get_type() = 0;



		virtual void show() = 0;	
		virtual void edit() = 0;
};

