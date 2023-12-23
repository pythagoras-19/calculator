//
// Created by Matthew Christiansen on 12/22/23.
//

#ifndef BLUEBERRY_H
#define BLUEBERRY_H

#include <QGraphicsItem>
#include <random>
#include <QPainter>
#include <QRectF>

class Blueberry : public QGraphicsItem {
public:
    Blueberry();
    void randomizePosition();
    [[nodiscard]] int getXPosition() const;
    [[nodiscard]] int getYPosition() const;
    void setPosition(int xPosition, int yPosition);
    void move();

    // override from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


private:
    QPixmap image;
    int xPosition;
    int yPosition;
};

#endif // BLUEBERRY_H
