//
// Created by Matthew Christiansen on 12/20/23.
//

#ifndef CALCULATOR_GAMEBOARD_H
#define CALCULATOR_GAMEBOARD_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QApplication>

class GameBoard : public QGraphicsView {
    Q_OBJECT

public:
    explicit GameBoard(QWidget* parent = nullptr);
    QGraphicsScene* getScene() const;
    int getScore();
    int getGameBoardWidth() const;
    int getGameBoardHeight() const;
    int getPlayButtonWidth() const;
    int getPlayButtonHeight() const;
    int getQuitButtonWidth() const;
    int getQuitButtonHeight() const;
    int getBlueberriesEaten();
    void increaseScore();
    void increaseBlueberriesEaten();

public slots:
    static void startGame();
    static void quitGame();

private:
    QGraphicsScene *scene;
    int blueberriesEaten;
    int score;
    int playButtonWidth;
    int playButtonHeight;
    int gameBoardWidth;
    int gameBoardHeight;
    int quitButtonWidth;
    int quitButtonHeight;
    QLabel *scoreLabel;
    QGraphicsPixmapItem *bearItem;
    QGraphicsPixmapItem *blueberryItem;
    QPushButton *playButton;
    QPushButton *quitButton;
    //TODO: pause button
    //TODO: resume button
};


#endif //CALCULATOR_GAMEBOARD_H
