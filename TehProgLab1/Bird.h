#pragma once
#include "Animal.h"
#include "CDshow.h"
class Bird :
    public Animal
{
private:
        std::string breed;
        std::string color;    
        std::string food;
        std::string location;
public:
    Bird();
    Bird(std::string breed, std::string color, std::string food, std::string location);
    Bird(const Bird& other);
    ~Bird();

    std::string get_breed();
    std::string get_color();
    std::string get_food();
    std::string get_location();
    std::string get_type();

    void set_breed(std::string);
    void set_color(std::string);
    void set_food(std::string);
    void set_location(std::string);
    
    void show();

    void edit();
};

