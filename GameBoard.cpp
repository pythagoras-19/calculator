//
// Created by Matthew Christiansen on 12/20/23.
//

#include "GameBoard.h"

GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent) {
    this->score = 0;
    this->gameBoardWidth = 800;
    this->gameBoardHeight = 600;
    this->playButtonHeight = 50;
    this->playButtonWidth = 200;
    this->quitButtonHeight = 50;
    this->quitButtonWidth = 200;
    this->blueberriesEaten = 0;
    playButton = new QPushButton("Play", this);
    playButton->setGeometry(
            (this->getGameBoardWidth()/2 - playButtonWidth/2),
            0,
            this->getPlayButtonWidth(),
            this->getPlayButtonHeight());
    quitButton = new QPushButton("Quit", this);
    quitButton->setGeometry(
            (this->getGameBoardWidth()/2 - quitButtonWidth/2),
            600 - this->getQuitButtonHeight(),
            this->getQuitButtonWidth(),
            this->getQuitButtonHeight());
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    this->setScene(scene);
    scene->setSceneRect(0, 0, 800, 600);
    this->setFixedSize(800, 600);
    scoreLabel = new QLabel("Blueberries Eaten: " + QString::number(this->blueberriesEaten), this);
    scoreLabel->setGeometry(0, 0, 200, 20);
    connect(playButton, &QPushButton::clicked, this, &GameBoard::startGame);
    connect(quitButton, &QPushButton::clicked, this, &GameBoard::quitGame);
    this->scene->addWidget(playButton);
    this->getScene()->addWidget(quitButton);

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
    return this->scene;
}

int GameBoard::getScore() const {
    return this->score;
}

void GameBoard::startGame() {
}

void GameBoard::quitGame() {
    QApplication::quit();
}

int GameBoard::getGameBoardWidth() const {
    return this->gameBoardWidth;
}

int GameBoard::getGameBoardHeight() const {
    return this->gameBoardHeight;
}

int GameBoard::getPlayButtonWidth() const {
    return this->playButtonWidth;
}

int GameBoard::getPlayButtonHeight() const {
    return this->playButtonHeight;
}

int GameBoard::getQuitButtonWidth() const {
    return this->quitButtonWidth;
}

int GameBoard::getQuitButtonHeight() const {
    return this->quitButtonHeight;
}

int GameBoard::getBlueberriesEaten() const {
    return this->blueberriesEaten;
}

