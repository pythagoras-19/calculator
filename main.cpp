#include "Calculator.h"
#include "Animal.h"
#include <iostream>
#include <QApplication>
#include <QDebug>
using namespace std;

int main() {
    try {
        auto *bear = new Animal(500.0, 15.0, 20.0, "berries", "Bear1", "Roar",
                                  "Brown", "canidae");
        auto *calc = new Calculator();

        cout << "Bear details: " << endl;
        cout << "Weight: " << bear->getWeight() << endl;
        cout << "Height: " << bear->getHeight() << endl;
        cout << "Beast Level: " << bear->getBeastLevel() << endl;
        cout << "What it eats: " << bear->getWhatItEats() << endl;
        cout << "Name: " << bear->getName() << endl;
        cout << "Sound: " << bear->getSound() << endl;
        cout << "Color: " << bear->getColor() << endl;
        cout << "Type: " << bear->getType() << endl;

        calc->add(1, 2);
        calc->add(1.0, 2.0);
        calc->subtract(1, 2);
        Calculator::subtract(1.0, 2.0);
        calc->multiply(1, 2);
        cout << "Successfully created an animal and calculator object." << endl;

    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

