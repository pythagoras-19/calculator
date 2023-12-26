//
// Created by Matthew Christiansen on 12/22/23.
//

#include "Blueberry.h"

Blueberry::Blueberry() {
    this->xPosition = 0;
    this->yPosition = 200;
    this->width = 100;
    this->height = 100;
    this->setPos(xPosition, yPosition);
}

QRectF Blueberry::boundingRect() const {
    return QRectF(xPosition, yPosition, width, height);
}

void Blueberry::randomizePosition() {

}

void Blueberry::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    qDebug("------ Blueberry::paint() called. ------");
    QPixmap blueberryPixmap("/Users/mattc/CLionProjects/calculator/blueberry_cute_1.jpeg");
    painter->drawPixmap(0, 0, blueberryPixmap.scaled(100, 100));
}

int Blueberry::getXPosition() const {
    return xPosition;
}

int Blueberry::getYPosition() const {
    return yPosition;
}

void Blueberry::move(int xBoundary, int yBoundary) {
    qDebug("Blueberry::move() called.");
    if (xPosition >= xBoundary) {
        xPosition = 0;
    }
    if (yPosition >= yBoundary) {
        yPosition = yBoundary;
    }
    int newXPosition = xPosition += 2;
    if (newXPosition > xBoundary) {
        newXPosition = xBoundary;
    }
    this->setPos(xPosition, yPosition);
    qDebug("New position: (%d, %d)", xPosition, yPosition);
    update();
}

int Blueberry::getBlueberryHeight() const {
    return this->height;
}

int Blueberry::getBlueberryWidth() const {
    return this->width;
}

