//
// Created by Matthew Christiansen on 12/22/23.
//

#include "Blueberry.h"

Blueberry::Blueberry() {
    this->xPosition = 200;
    this->yPosition = 300;
    this->width = 100;
    this->height = 100;
    this->setPos(xPosition, yPosition);
}

QRectF Blueberry::boundingRect() const {
    qDebug("------ Blueberry::boundingRect() called. ------");
    qDebug("xPosition: %d", xPosition);
    qDebug("yPosition: %d", yPosition);
    qDebug("width: %d", width);
    qDebug("height: %d", height);
    return QRectF(xPosition, yPosition, width, height);
}

void Blueberry::randomizePosition() {

}

void Blueberry::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    qDebug("------ Blueberry::paint() called. ------");
    QPixmap blueberryPixmap("/Users/mattc/CLionProjects/calculator/blueberry_cute_1.jpeg");
    painter->drawPixmap(0, 0, blueberryPixmap.scaled(100, 100));
    qDebug("------ Blueberry::paint() finished. ------");
}

int Blueberry::getXPosition() const {
    return xPosition;
}

int Blueberry::getYPosition() const {
    return yPosition;
}

void Blueberry::move(qreal xBoundary, qreal yBoundary) {
    qDebug("Blueberry::move() called.");
    xPosition += 1;
    if (xPosition >= xBoundary - width) {
        qDebug("Blueberry::move() called. xPosition >= xBoundary");
        xPosition = 0;
        // TODO: Start bb at 0, 300
        //return;
    }
    qDebug("New position: (%d, %d)", xPosition, yPosition);
    this->setPos(xPosition, yPosition);
    update();
}


int Blueberry::getBlueberryHeight() const {
    return this->height;
}

int Blueberry::getBlueberryWidth() const {
    return this->width;
}

