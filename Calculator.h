//
// Created by Matthew Christiansen on 11/1/23.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H


class Calculator {
public:
    [[maybe_unused]] int add(int a, int b);
    [[maybe_unused]] double add(double a, double b);
    [[maybe_unused]] int subtract(int a, int b);
    [[maybe_unused]] static double subtract(double a, double b);
    [[maybe_unused]] int multiply(int a, int b);
    [[maybe_unused]] double multiply(double a, double b);
    [[maybe_unused]] int divide(int a, int b);
    [[maybe_unused]] double divide(double a, double b);
};


#endif //CALCULATOR_CALCULATOR_H
