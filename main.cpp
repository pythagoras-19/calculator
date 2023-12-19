#include "ClickableLabel.h"
#include "Animal.h"
#include <QApplication>
#include <QDebug>
#include <QPixmap>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QFont>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
using namespace std;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    try {
        auto *bear = new Animal(500.0, 15.0, 20.0, "berries", "Bear1",
                                "Roar","Brown", "canidae");
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
        bearDetails.append("Successfully created an animal and calculator object.\n");

        QLabel *detailsLabel = new QLabel(bearDetails);
        detailsLabel->setTextFormat(Qt::RichText);

        QFont cuteFont("Comic Sans MS", 14, QFont::Bold);
        detailsLabel->setFont(cuteFont);

        QPixmap bearImage("/Users/mattc/CLionProjects/calculator/bear_cute.png");
        if (bearImage.isNull()) {
            qDebug() << "Failed to load the image!";
            return -1;
        }
        qDebug() << "Loaded img successfully! Size: " << bearImage.size();
        /*
        QLabel* imageLabel = new QLabel;
        imageLabel->setPixmap(bearImage);
        imageLabel->setMinimumSize(100, 100);
         */

        ClickableLabel *imageLabel = new ClickableLabel;
        imageLabel->setPixmap(bearImage);
        imageLabel->setMinimumSize(100, 100);
        imageLabel->setStyleSheet("border: 1px solid red;");
        detailsLabel->setStyleSheet("border: 1px solid blue;");

        QGraphicsOpacityEffect *bearOpacityEffect = new QGraphicsOpacityEffect(imageLabel);
        imageLabel->setGraphicsEffect(bearOpacityEffect);
        bearOpacityEffect->setOpacity(1.0);


        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(detailsLabel);
        layout->addWidget(imageLabel);
        layout->setMargin(10);

        QWidget window;
        window.setLayout(layout);
        window.setWindowTitle("Animal App v.37.0");
        window.setMinimumSize(400, 300);
        QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(&window);
        window.setGraphicsEffect(opacityEffect);
        QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
        animation->setDuration(5000);
        animation->setStartValue(0.0); // start fully transparent
        animation->setEndValue(1.0); // end fully opaque
        animation->start();
        window.show();

        return QApplication::exec();

    } catch (exception &e) {
        qDebug() << "Error:" << e.what();
    }
    return 0;
}