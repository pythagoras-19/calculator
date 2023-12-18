//
// Created by Matthew Christiansen on 11/7/23.
//

#ifndef CALCULATOR_HOUSECAT_H
#define CALCULATOR_HOUSECAT_H


#include "Animal.h"

class Housecat: public Animal{
public:
public:
    Housecat(double weight, double height, double beastLevel, std::string whatItEats, std::string name,
             std::string sound, std::string color, std::string type, int houseCatId);

    ~Housecat() override;

    int getHouseCatId() const;
    void setHouseCatId(int houseCatId);
    void scratch();
    void purr();
    void meow();
    void hiss();

private:
    int houseCatId;
};


#endif //CALCULATOR_HOUSECAT_H
