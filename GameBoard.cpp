//
// Created by Matthew Christiansen on 12/20/23.
//

#include "GameBoard.h"

GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent) {
    isGameStarted = false;
    isGamePaused = false;
    isGameQuit = false;
    isGameResumed = false;
    gameTimer = new QTimer(this);
    clockLabel = new QLabel(this);
    bb = new Blueberry();
    elapsedTime = 0;

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    this->setScene(scene);

    auto *meadowPixmap = new QGraphicsPixmapItem(
            QPixmap("/Users/mattc/CLionProjects/calculator/meadow_cute.jpeg"));
    scene->addItem(meadowPixmap);

    auto *bearPixmap = new QGraphicsPixmapItem(
            QPixmap("/Users/mattc/CLionProjects/calculator/bear_cute.png"));
    bearPixmap->setPos(100, 100);
    bearPixmap->setPixmap(bearPixmap->pixmap().scaled(100, 100));
    scene->addItem(bearPixmap);

    auto *blueberryPixmap = new QGraphicsPixmapItem(
            QPixmap("/Users/mattc/CLionProjects/calculator/blueberry_cute_1.jpeg"));
    blueberryPixmap->setPos(bb->getXPosition(), bb->getYPosition());
    blueberryPixmap->setPixmap(
            blueberryPixmap->pixmap().scaled(bb->getBlueberryWidth(), bb->getBlueberryHeight()));
    scene->addItem(blueberryPixmap);

    clockLabel->setText("Time: " + QString::number(elapsedTime));
    clockLabel->setGeometry(0, 20, 200, 20);
    clockLabel->setStyleSheet("QLabel { color: black; }");

    this->setWindowTitle("Bear's Blueberry Adventure v.27.2");
    this->gameTimer = new QTimer(this);
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
    this->setFixedSize(800, 600);
    scoreLabel = new QLabel("Blueberries Eaten: " + QString::number(this->blueberriesEaten), this);
    scoreLabel->setGeometry(0, 0, 200, 20);
    scoreLabel->setStyleSheet("QLabel { color: black; }");
    connect(gameTimer, &QTimer::timeout, this, &GameBoard::updateGame);
    connect(playButton, &QPushButton::clicked, this, &GameBoard::startGame);
    connect(quitButton, &QPushButton::clicked, this, &GameBoard::quitGame);
    connect(pauseButton, &QPushButton::clicked, this, &GameBoard::pauseGame);
    connect(resumeButton, &QPushButton::clicked, this, &GameBoard::resumeGame);
    this->scene->addWidget(playButton);
    this->scene->addWidget(quitButton);
    this->scene->addWidget(pauseButton);
    this->scene->addWidget(resumeButton);

    gameTimer->setInterval(1000);
}

QGraphicsScene *GameBoard::getScene() const {
    return this->scene;
}

void GameBoard::startGame() {
    playButton->hide();
    gameTimer->start();
    isGameStarted = true;
    updateGame();
}

void GameBoard::quitGame() {
    isGameQuit = true;
    QApplication::quit();
}

void GameBoard::pauseGame() {
    isGamePaused = true;
    gameTimer->stop();
}

void GameBoard::resumeGame() {
    isGamePaused = true;
    gameTimer->start(1000);
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

void GameBoard::startCollisionDetection() {
    // TODO: FINISH ME
}

void GameBoard::updateGame() {
    qDebug("GameBoard::updateGame() called Initially.");
    elapsedTime++;
    clockLabel->setText("Time: " + QString::number(elapsedTime));
    bb->move();
    //TODO: startCollisionDetection();
    scene->update();
    qDebug("GameBoard::updateGame() called. Iteration: %d", elapsedTime);
}

GameBoard::~GameBoard() {
    delete bb;
    delete scene;
    delete gameTimer;
    delete clockLabel;
    delete playButton;
    delete quitButton;
    delete pauseButton;
    delete resumeButton;
    delete scoreLabel;
}


