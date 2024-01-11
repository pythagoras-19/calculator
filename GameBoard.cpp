//
// Created by Matthew Christiansen on 12/20/23.
//

#include "GameBoard.h"

GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent) {
    isGameStarted = false;
    isGamePaused = false;
    isGameQuit = false;
    isGameResumed = false;
    isGameRestarted = false;
    gameTimer = new QTimer(this);
    clockLabel = new QLabel(this);
    bbObj = new Blueberry();
    elapsedTime = 0;

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    this->setScene(scene);

    auto *meadowPixmap = new QGraphicsPixmapItem(
            QPixmap("/Users/mattc/CLionProjects/calculator/meadow_cute.jpeg"));
    scene->addItem(meadowPixmap);

    auto *bW = new BearWidget();
    bW->setBearPixmap(QPixmap(
            "/Users/mattc/CLionProjects/calculator/bear_cute.png").scaled(100, 100));
    QGraphicsProxyWidget *proxy_1 = scene->addWidget(bW);
    if (proxy_1) {
        proxy_1->setPos(100, 100);
        proxy_1->setFlag(QGraphicsItem::ItemIsMovable);
    } else {
        qDebug() << "-- proxy_1 is null --";
    }

    scene->addItem(bbObj);

    clockLabel->setText("Time: " + QString::number(elapsedTime));
    clockLabel->setGeometry(0, 20, 200, 20);
    clockLabel->setStyleSheet("QLabel { color: black; }");

    this->setWindowTitle("Bear's Blueberry Adventure v.27.2");
    this->gameTimer = new QTimer(this);
    this->gameBoardWidth = 800;
    this->gameBoardHeight = 600;
    this->playButtonHeight = 50;
    this->playButtonWidth = 100;
    this->quitButtonHeight = 50;
    this->quitButtonWidth = 100;
    this->pauseButtonHeight = 50;
    this->pauseButtonWidth = 100;
    this->resumeButtonHeight = 50;
    this->resumeButtonWidth = 100;
    this->restartButtonHeight = 50;
    this->restartButtonWidth = 100;
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
    restartButton = new QPushButton("Restart :)", this);
    restartButton->setGeometry(
            (this->getGameBoardWidth() - restartButtonWidth),
            0 + this->pauseButtonHeight + this->resumeButtonHeight,
            this->restartButtonWidth,
            this->restartButtonHeight);
    restartButton->setStyleSheet("QPushButton { background-color: purple; color: black; }");
    this->setFixedSize(800, 600);
    scoreLabel = new QLabel("Blueberries Eaten: " + QString::number(this->blueberriesEaten), this);
    scoreLabel->setGeometry(0, 0, 200, 20);
    scoreLabel->setStyleSheet("QLabel { color: black; }");
    connect(gameTimer, &QTimer::timeout, this, &GameBoard::updateGame);
    connect(playButton, &QPushButton::clicked, this, &GameBoard::startGame);
    connect(quitButton, &QPushButton::clicked, this, &GameBoard::quitGame);
    connect(pauseButton, &QPushButton::clicked, this, &GameBoard::pauseGame);
    connect(resumeButton, &QPushButton::clicked, this, &GameBoard::resumeGame);
    connect(restartButton, &QPushButton::clicked, this, &GameBoard::restartGame);
    this->scene->addWidget(playButton);
    this->scene->addWidget(quitButton);
    this->scene->addWidget(pauseButton);
    this->scene->addWidget(resumeButton);
    this->scene->addWidget(restartButton);

    gameTimer->setInterval(100);
}

QGraphicsScene *GameBoard::getScene() const {
    return this->scene;
}

void GameBoard::startGame() {
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
    gameTimer->start(100);
}

void GameBoard::restartGame() {
    delete bbObj;
    bbObj = new Blueberry();
    scene->addItem(bbObj);
    isGameRestarted = true;
    elapsedTime = 0;
    blueberriesEaten = 0;
    scoreLabel->setText("Blueberries Eaten: " + QString::number(this->blueberriesEaten));
    clockLabel->setText("Time: " + QString::number(elapsedTime));
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

int GameBoard::getRestartButtonWidth() const {
    return this->restartButtonWidth;
}

int GameBoard::getRestartButtonHeight() const {
    return this->restartButtonHeight;
}

void GameBoard::startCollisionDetection() {
    qDebug("GameBoard::startCollisionDetection() called.");
    if (this->proxy && this->proxy->collidesWithItem(bbObj)) {
        increaseBlueberriesEaten();
        //TODO: bbObj->setRandomPosition();
    } else {
        if (!this->proxy) {
            qDebug("GameBoard::startCollisionDetection() called. proxy is null.");
        }
        if (!bbObj) {
            qDebug("GameBoard::startCollisionDetection() called. bbObj is null.");
        }
        qDebug("GameBoard::startCollisionDetection() called. No collision detected.");
    }
}

void GameBoard::updateGame() {
    qDebug("GameBoard::updateGame() called Initially.");
    QRectF sceneBounds = scene->sceneRect();
    QSizeF blueberrySize = bbObj->boundingRect().size();
    qDebug("Blueberry size: (%f, %f)", blueberrySize.width(), blueberrySize.height());

    qreal maxX = sceneBounds.width() - blueberrySize.width();
    qreal maxY = sceneBounds.height() - blueberrySize.height();
    qDebug("GameBoard::updateGame() called. maxX: %f, maxY: %f", maxX, maxY);

    elapsedTime++;
    clockLabel->setText("Time: " + QString::number(elapsedTime));
    bbObj->move(maxX, maxY);
    startCollisionDetection();
    scoreLabel->setText("Blueberries Eaten: " + QString::number(this->blueberriesEaten));
    scene->update();
    qDebug("GameBoard::updateGame() called. Iteration: %d", elapsedTime);
}

GameBoard::~GameBoard() {
    delete bbObj;
    delete scene;
    delete gameTimer;
    delete clockLabel;
    delete playButton;
    delete quitButton;
    delete pauseButton;
    delete resumeButton;
    delete scoreLabel;
}


