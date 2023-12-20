//
// Created by Matthew Christiansen on 12/20/23.
//

#include "GameBoard.h"

GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent) {
    auto *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    setScene(scene);
    score = 0;
    scoreLabel = new QLabel("Blueberries Eaten: 0", this);
    scoreLabel->setGeometry(0, 0, 200, 50); // TODO: Adjust me!
    //chompsound = new QSoundEffect(this);
}

// initialize bear and blueberry as QGraphicsItems