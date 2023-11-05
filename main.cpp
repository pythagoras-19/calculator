#include "Calculator.h"
#include "Animal.h"
#include <iostream>
#include <QApplication>
#include <QDebug>
#include <QLabel>
#include <QString>
using namespace std;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv); // Move QApplication up so it is initialized first

    try {
        auto *bear = new Animal(500.0, 15.0, 20.0, "berries", "Bear1", "Roar",
                                "Brown", "canidae");
        auto *calc = new Calculator();

        // Create a QString to hold the details of the bear.
        QString bearDetails;
        bearDetails.append("<b>Bear details:</b><br>");
        bearDetails.append("Weight: " + QString::number(bear->getWeight()) + "<br>");
        bearDetails.append("Height: " + QString::number(bear->getHeight()) + "<br>");
        bearDetails.append("Beast Level: " + QString::number(bear->getBeastLevel()) + "<br>");
        bearDetails.append("What it eats: " + QString::fromStdString(bear->getWhatItEats()) + "<br>");
        bearDetails.append("Name: " + QString::fromStdString(bear->getName()) + "<br>");
        bearDetails.append("Sound: " + QString::fromStdString(bear->getSound()) + "<br>");
        bearDetails.append("Color: " + QString::fromStdString(bear->getColor()) + "<br>");
        bearDetails.append("Type: " + QString::fromStdString(bear->getType()) + "<br><br>");


        calc->add(1, 2);
        calc->add(1.0, 2.0);
        calc->subtract(1, 2);
        Calculator::subtract(1.0, 2.0);
        calc->multiply(1, 2);

        bearDetails.append("Successfully created an animal and calculator object.\n");

        // Create the QLabel with the bear details
        QLabel label(bearDetails);
        label.setTextFormat(Qt::RichText);
        label.setWindowTitle("Animal Details");
        label.setMargin(10); // Add some margin for aesthetic spacing
        label.show();

        return app.exec(); // Run the application event loop

    } catch (exception &e) {
        qDebug() << "Error:" << e.what();
    }
    return 0;
}
