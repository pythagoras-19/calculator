//
// Created by Matthew Christiansen on 12/22/23.
//

#include "Blueberry.h"

Blueberry::Blueberry() {
    this->xPosition = 300;
    this->yPosition = 200;
    this->width = 100;
    this->height = 100;
}

QRectF Blueberry::boundingRect() const {
    return QRectF(xPosition, yPosition, width, height);
}

void Blueberry::randomizePosition() {

}

/*
void Blueberry::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
   QPixmap blueberryPixmap("/Users/mattc/CLionProjects/calculator/blueberry_cute_1.jpeg");
   painter->drawPixmap(xPosition, yPosition, blueberryPixmap);
}
 */
void Blueberry::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Load the pixmap only once for performance reasons
    static QPixmap blueberryPixmap("/Users/mattc/CLionProjects/calculator/blueberry_cute_1.jpeg");

    // Draw the pixmap at the current position
    painter->drawPixmap(xPosition, yPosition, blueberryPixmap);
}


int Blueberry::getXPosition() const {
    return xPosition;
}

int Blueberry::getYPosition() const {
    return yPosition;
}

void Blueberry::setPosition(int xPosition, int yPosition) {
    this->xPosition = xPosition;
    this->yPosition = yPosition;
}

void Blueberry::move() {
    qDebug("Blueberry::move() called.");
    xPosition += 50;
    qDebug("Made it after xPosition += 50");
    // this->setPos(xPosition, yPosition);
    this->setPosition(xPosition, yPosition);
    qDebug("%s", "Blueberry::move() moved blueberry 10 spaces to the right.");
    qDebug("xPosition: %d", xPosition);
    this->update();
}

int Blueberry::getBlueberryHeight() const {
    return this->height;
}

int Blueberry::getBlueberryWidth() const {
    return this->width;
}

