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

class GameBoard : public QGraphicsView {
    Q_OBJECT

    QGraphicsScene *scene;

public:
    explicit GameBoard(QWidget* parent = nullptr);
    QGraphicsScene* getScene() const;  // Getter for the scene

private:
    int score;
    QLabel *scoreLabel;
    QGraphicsPixmapItem *bearItem;
    QGraphicsPixmapItem *blueberryItem;
};


#endif //CALCULATOR_GAMEBOARD_H
