//
// Created by Matthew Christiansen on 12/20/23.
//

#include "GameBoard.h"

GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent) {
    score = 0;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    this->setScene(scene);
    scene->setSceneRect(0, 0, 800, 600);
    this->setFixedSize(800, 600);
    scoreLabel = new QLabel("Blueberries Eaten: 0", this);
    scoreLabel->setGeometry(0, 0, 200, 50);

    // Load bear image
    QPixmap bearPixmap("/Users/mattc/CLionProjects/calculator/game_bear_cute.jpeg");
    bearItem = new QGraphicsPixmapItem(bearPixmap);
    scene->addItem(bearItem);
    bearItem->setPos(100, 100);

    // Load blueberry image
    QPixmap blueberryPixmap("/Users/mattc/CLionProjects/calculator/blueberry_cute_1.jpeg");
    blueberryItem = new QGraphicsPixmapItem(blueberryPixmap);
    scene->addItem(blueberryItem);
    blueberryItem->setPos(300, 300);
}

QGraphicsScene *GameBoard::getScene() const {
    return scene;
}