//
// Created by Matthew Christiansen on 12/22/23.
//

#ifndef BLUEBERRY_H
#define BLUEBERRY_H

#include <QGraphicsItem>
#include <random>
#include <QPainter>
#include <QRectF>
#include <QPixmap>

class Blueberry : public QGraphicsItem {
public:
    Blueberry();
    void randomizePosition();
    [[nodiscard]] int getXPosition() const;
    [[nodiscard]] int getYPosition() const;
    void setPosition(int xPosition, int yPosition);
    void move(int xBoundary, int yBoundary);
    int getBlueberryWidth() const;
    int getBlueberryHeight() const;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


private:
    QPixmap image;
    int xPosition;
    int yPosition;
    int width;
    int height;
};

#endif // BLUEBERRY_H
