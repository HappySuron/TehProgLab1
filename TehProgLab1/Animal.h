#pragma once
#include <string>
class Animal
{
public:
		Animal() {};

		virtual ~Animal() {};

		virtual void set_color(std::string) = 0;
		virtual void set_breed(std::string) = 0;

		virtual std::string get_color() = 0;
		virtual std::string get_breed() = 0;
};

