//
// Created by Matthew Christiansen on 12/20/23.
//

#ifndef CALCULATOR_GAMEBOARD_H
#define CALCULATOR_GAMEBOARD_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
// #include <QSoundEffect>

class GameBoard : public QGraphicsView {
    Q_OBJECT

public:
    explicit GameBoard(QWidget* parent = nullptr);

private:
    int score;
    QLabel *scoreLabel;
};


#endif //CALCULATOR_GAMEBOARD_H
