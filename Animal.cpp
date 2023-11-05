//
// Created by Matthew Christiansen on 11/1/23.
//

#include "Animal.h"
#include <string>
#include <iostream>

using namespace std;

// constructor that sets the attributes by passing in the values
[[maybe_unused]] Animal::Animal(double weight, double height, double beastLevel, std::string whatItEats, std::string name, std::string sound,
               std::string color, std::string type) {
    this->weight = weight;
    this->height = height;
    this->beastLevel = beastLevel;
    this->whatItEats = whatItEats;
    this->name = name;
    this->sound = sound;
    this->color = color;
    this->type = type;
}

void Animal::setWeight(double weight) {
    this->weight = weight;
}
void Animal::setHeight(double height) {
    this->height = height;
}
//rest of setter functions
void Animal::setBeastLevel(double beastLevel) {
    this->beastLevel = beastLevel;
}
void Animal::setWhatItEats(std::string whatItEats) {
    this->whatItEats = whatItEats;
}
void Animal::setName(std::string name) {
    this->name = name;
}
void Animal::setSound(std::string sound) {
    this->sound = sound;
}
void Animal::setColor(std::string color) {
    this->color = color;
}
void Animal::setType(std::string type) {
    this->type = std::move(type);
}
//getter functions
double Animal::getWeight() {
    return this->weight;
}
double Animal::getHeight() {
    return this->height;
}
double Animal::getBeastLevel() {
    return this->beastLevel;
}
std::string Animal::getWhatItEats() {
    return this->whatItEats;
}
std::string Animal::getName() {
    return this->name;
}
std::string Animal::getSound() {
    return this->sound;
}
std::string Animal::getColor() {
    return this->color;
}
std::string Animal::getType() {
    return this->type;
}
//destructor
Animal::~Animal() {
    cout << "Animal " << this->name << " has been destroyed" << endl;
}
//other functions that need to be implemented
// TODO: implement these functions
[[maybe_unused]] void Animal::makeSound() {
    cout << this->sound << endl;
}
void Animal::eat() {
    cout << this->name << " is eating " << this->whatItEats << endl;
    this->weight += 1;
}
void Animal::sleep() {
    cout << this->name << " is sleeping" << endl;
    this->energy += 1;
}
void Animal::move() {
    cout << this->name << " is moving" << endl;
}
void Animal::attack() {
    cout << this->name << " is attacking" << endl;
}
void Animal::defend() {
    cout << this->name << " is defending" << endl;
}
void Animal::die() {
    cout << this->name << " is dying" << endl;
}
void Animal::reproduce() {
    cout << this->name << " is reproducing" << endl;
}
void Animal::grow() {
    cout << this->name << " is growing" << endl;
}
