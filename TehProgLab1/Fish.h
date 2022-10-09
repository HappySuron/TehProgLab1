#pragma once
#include "Animal.h"
#include "CDshow.h"

class Fish :
    public Animal
{
private:
    std::string color;
    std::string breed;
    std::string food;
public:
    Fish();
    Fish(std::string breed, std::string color, std::string food);
    Fish(const Fish &other);
    ~Fish();

    std::string get_breed();
    std::string get_color();
    std::string get_food();
    std::string get_type();

    void set_breed(std::string);
    void set_color(std::string);
    void set_food(std::string);

    void show();


    void edit();
};

