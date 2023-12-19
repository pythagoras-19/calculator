//
// Created by Matthew Christiansen on 11/7/23.
//

#include "Housecat.h"
#include <iostream>

Housecat::~Housecat() {
    std::cout << "Housecat destructor called" << std::endl;

}

Housecat::Housecat(double weight, double height, double beastLevel, std::string whatItEats, std::string name,
                   std::string sound, std::string color, std::string type, int houseCatId)
        : Animal(weight, height, beastLevel, std::move(whatItEats), std::move(name), std::move(sound), std::move(color),
                 std::move(type)),houseCatId(houseCatId)
{
}

