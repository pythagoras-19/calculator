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

        // set up images
        QLabel *detailsLabel = new QLabel(bearDetails);
        detailsLabel->setTextFormat(Qt::RichText);

        QLabel *meadowLabel = new QLabel;
        meadowLabel->setPixmap(QPixmap("/Users/mattc/CLionProjects/calculator/meadow_cute.jpeg"));
        meadowLabel->setMinimumSize(100, 100);
        meadowLabel->hide();

        QGraphicsOpacityEffect *meadowOpacityEffect = new QGraphicsOpacityEffect(meadowLabel);
        meadowLabel->setGraphicsEffect(meadowOpacityEffect);
        meadowOpacityEffect->setOpacity(0.0); // start fully transparent

        QFont cuteFont("Comic Sans MS", 14, QFont::Bold);
        detailsLabel->setFont(cuteFont);

        QPixmap bearImage("/Users/mattc/CLionProjects/calculator/bear_cute.png");
        if (bearImage.isNull()) {
            qDebug() << "Failed to load the image!";
            return -1;
        }
        qDebug() << "Loaded img successfully! Size: " << bearImage.size();

        ClickableLabel *imageLabel = new ClickableLabel;
        imageLabel->setPixmap(bearImage);
        imageLabel->setMinimumSize(100, 100);
        imageLabel->setStyleSheet("border: 1px solid red;");
        detailsLabel->setStyleSheet("border: 1px solid blue;");

        QGraphicsOpacityEffect *bearOpacityEffect = new QGraphicsOpacityEffect(imageLabel);
        imageLabel->setGraphicsEffect(bearOpacityEffect);
        bearOpacityEffect->setOpacity(1.0); // start fully visible

        // create fade out animation on click of bear image
        QObject::connect(imageLabel, &ClickableLabel::clicked, [&](){
            QPropertyAnimation *fadeOutAnimation =
                    new QPropertyAnimation(bearOpacityEffect, "opacity");
            fadeOutAnimation->setDuration(1000); // 1 second for fade-out
            fadeOutAnimation->setStartValue(1.0); // Start fully visible
            fadeOutAnimation->setEndValue(0.0); // Fade to fully transparent

            // fade in meadow image
            QObject::connect(fadeOutAnimation, &QPropertyAnimation::finished, [&](){
                imageLabel->hide();

                meadowLabel->show();
                QPropertyAnimation *fadeInAnimation =
                        new QPropertyAnimation(meadowOpacityEffect, "opacity");
                fadeInAnimation->setDuration(1000);
                fadeInAnimation->setStartValue(0.0);
                fadeInAnimation->setEndValue(1.0);
                fadeInAnimation->start(QAbstractAnimation::DeleteWhenStopped);
            });
            fadeOutAnimation->start(QAbstractAnimation::DeleteWhenStopped);
        });

        // create fade in animation on click of meadow image

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(detailsLabel);
        layout->addWidget(imageLabel);
        layout->setMargin(10);
        layout->addWidget(meadowLabel);

        QWidget window;
        window.setLayout(layout);
        window.setWindowTitle("Animal App v.37.0");
        window.setMinimumSize(800, 300);
        /*
        QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(&window);
        window.setGraphicsEffect(opacityEffect);
        QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
        animation->setDuration(5000);
        animation->setStartValue(0.0); // start fully transparent
        animation->setEndValue(1.0); // end fully opaque
        animation->start();
         */
        window.show();

        return QApplication::exec();

    } catch (exception &e) {
        qDebug() << "Error:" << e.what();
    }
    return 0;
}