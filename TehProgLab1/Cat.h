#pragma once
#include "Animal.h"
#include "CDshow.h"
class Cat :
    public Animal
{

private:
    std::string breed;
    std::string color;
    std::string owner;
    std::string name;
public:
    Cat();
    Cat(std::string breed, std::string color, std::string owner, std::string name);
    Cat(const Cat& other);
    ~Cat();

    std::string get_breed();
    std::string get_color();
    std::string get_owner();
    std::string get_name();
    std::string get_type();

    void set_breed(std::string);
    void set_color(std::string);
    void set_owner(std::string);
    void set_name(std::string);
    
    void show();

    void edit();
};

