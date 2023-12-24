//
// Created by Matthew Christiansen on 12/20/23.
//

#ifndef CALCULATOR_GAMEBOARD_H
#define CALCULATOR_GAMEBOARD_H

#include "Blueberry.h"
#include "Animal.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QApplication>
#include <QTimer>
#include <QPixmap>

class GameBoard : public QGraphicsView {
    Q_OBJECT

public:
    explicit GameBoard(QWidget* parent = nullptr);
    QGraphicsScene* getScene() const;
    int getGameBoardWidth() const;
    int getGameBoardHeight() const;
    int getPlayButtonWidth() const;
    int getPlayButtonHeight() const;
    int getQuitButtonWidth() const;
    int getQuitButtonHeight() const;
    int getPauseButtonWidth() const;
    int getPauseButtonHeight() const;
    int getResumeButtonWidth() const;
    int getResumeButtonHeight() const;
    int getRestartButtonWidth() const;
    int getRestartButtonHeight() const;
    int getBlueberriesEaten();
    void increaseScore();
    void increaseBlueberriesEaten();
    void startCollisionDetection();
    ~GameBoard() override;

public slots:
    void startGame();
    void quitGame();
    void pauseGame();
    void resumeGame();
    void updateGame();
    void restartGame();


private:
    QGraphicsScene *scene;
    int blueberriesEaten;
    int resumeButtonWidth;
    int resumeButtonHeight;
    int pauseButtonWidth;
    int pauseButtonHeight;
    int playButtonWidth;
    int playButtonHeight;
    int gameBoardWidth;
    int gameBoardHeight;
    int quitButtonWidth;
    int quitButtonHeight;
    int restartButtonWidth;
    int restartButtonHeight;
    QLabel *scoreLabel;
    QPushButton *playButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
    QPushButton *resumeButton;
    QPushButton *restartButton;
    QTimer *gameTimer;
    QLabel *clockLabel;
    int elapsedTime;
    Blueberry *bb;
    Animal *bear;
    bool isGamePaused;
    bool isGameStarted;
    bool isGameQuit;
    bool isGameResumed;
    bool isGameRestarted;
};


#endif //CALCULATOR_GAMEBOARD_H
