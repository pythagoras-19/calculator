//
// Created by Matthew Christiansen on 11/1/23.
//

/*
 * This is the header file for the Animal class
 * The Animal class represents the higher order of animals
 * Further animals will be created an inherit qualities from this class.
 */
#include <string>

#ifndef CALCULATOR_ANIMAL_H
#define CALCULATOR_ANIMAL_H


class Animal {
public:
    //setter functions
    void setWeight(double weight);
    void setHeight(double height);
    void setBeastLevel(double beastLevel);
    void setWhatItEats(std::string whatItEats);
    void setName(std::string name);
    void setSound(std::string sound);
    void setColor(std::string color);
    void setType(std::string type);
    void setSpeed(double speed);

    //getter functions
    double getWeight() const;
    double getHeight() const;
    double getBeastLevel() const;
    double getSpeed() const;
    std::string getWhatItEats();
    std::string getName();
    std::string getSound();
    std::string getColor();
    std::string getType();

    //constructor
    [[maybe_unused]] Animal(double weight, double height, double beastLevel, std::string whatItEats, std::string name,
                            std::string sound, std::string color, std::string type);

    //destructor
    virtual ~Animal();

    //other functions
    [[maybe_unused]] void makeSound();
    [[maybe_unused]] void eat();
    void sleep();
    void move();
    void attack();
    void defend();
    void die();
    void reproduce();
    void grow();

private:
    double weight;
    double height;
    double beastLevel; // this is a number from 0 to 1 that represents how much of a beast the animal is
    std::string whatItEats{}; // this is a string that represents what the animal eats
    std::string name{}; // this is the name of the animal
    std::string sound{}; // this is the sound the animal makes
    std::string color{}; // this is the color of the animal
    std::string type{}; // this is the type of animal
    int energy{}; // this is the energy level of the animal
    double speed;
    int animalID{};
};


#endif //CALCULATOR_ANIMAL_H
