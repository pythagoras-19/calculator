//
// Created by Matthew Christiansen on 12/20/23.
//

#include "GameBoard.h"

GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent) {
    this->setWindowTitle("Bear's Blueberry Adventure v.27.2");
    this->score = 0;
    this->gameBoardWidth = 800;
    this->gameBoardHeight = 600;
    this->playButtonHeight = 50;
    this->playButtonWidth = 200;
    this->quitButtonHeight = 50;
    this->quitButtonWidth = 200;
    this->pauseButtonHeight = 50;
    this->pauseButtonWidth = 100;
    this->resumeButtonHeight = 50;
    this->resumeButtonWidth = 100;
    this->blueberriesEaten = 0;
    playButton = new QPushButton("Play :)", this);
    playButton->setGeometry(
            (this->getGameBoardWidth()/2 - playButtonWidth/2),
            0,
            this->getPlayButtonWidth(),
            this->getPlayButtonHeight());
    playButton->setStyleSheet("QPushButton { background-color: blue; color: white; }");
    quitButton = new QPushButton("Quit :)", this);
    quitButton->setGeometry(
            (this->getGameBoardWidth()/2 - quitButtonWidth/2),
            600 - this->getQuitButtonHeight(),
            this->getQuitButtonWidth(),
            this->getQuitButtonHeight());
    quitButton->setStyleSheet("QPushButton { background-color: red; color: white; }");
    pauseButton = new QPushButton("Pause :)", this);
    pauseButton->setGeometry(
            (this->getGameBoardWidth() - pauseButtonWidth),
            0,
            this->getPauseButtonWidth(),
            this->getPauseButtonHeight());
    pauseButton->setStyleSheet("QPushButton { background-color: yellow; color: black; }");
    resumeButton = new QPushButton("Resume :)", this);
    resumeButton->setGeometry(
            (this->getGameBoardWidth() - resumeButtonWidth),
            0 + this->getPauseButtonHeight(),
            this->getResumeButtonWidth(),
            this->getResumeButtonHeight());
    resumeButton->setStyleSheet("QPushButton { background-color: green; color: black; }");
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    this->setScene(scene);
    scene->setSceneRect(0, 0, 800, 600);
    this->setFixedSize(800, 600);
    scoreLabel = new QLabel("Blueberries Eaten: " + QString::number(this->blueberriesEaten), this);
    scoreLabel->setGeometry(0, 0, 200, 20);
    scoreLabel->setStyleSheet("QLabel { color: black; }");
    connect(playButton, &QPushButton::clicked, this, &GameBoard::startGame);
    connect(quitButton, &QPushButton::clicked, this, &GameBoard::quitGame);
    connect(pauseButton, &QPushButton::clicked, this, &GameBoard::pauseGame);
    connect(resumeButton, &QPushButton::clicked, this, &GameBoard::resumeGame);
    this->scene->addWidget(playButton);
    this->scene->addWidget(quitButton);
    this->scene->addWidget(pauseButton);
    this->scene->addWidget(resumeButton);

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

void GameBoard::startGame() {
    /*
     * TODO: add a timer to move the blueberry around the screen
     * */
}

void GameBoard::quitGame() {
    QApplication::quit();
}

void GameBoard::pauseGame() {
    // TODO: FINISH
}

void GameBoard::resumeGame() {
    // TODO: FINISH
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

int GameBoard::getBlueberriesEaten() {
    return this->blueberriesEaten;
}

void GameBoard::increaseBlueberriesEaten() {
    this->blueberriesEaten++;
}

int GameBoard::getPauseButtonWidth() const {
    return this->pauseButtonWidth;
}

int GameBoard::getPauseButtonHeight() const {
    return this->pauseButtonHeight;
}

int GameBoard::getResumeButtonHeight() const {
    return this->resumeButtonHeight;
}

int GameBoard::getResumeButtonWidth() const {
    return this->resumeButtonWidth;
}



