//
// Created by Matthew Christiansen on 1/9/24.
//

#ifndef CALCULATOR_BEARWIDGET_H
#define CALCULATOR_BEARWIDGET_H


#include <QWidget>
#include <QMouseEvent>
#include <QPainter>

class BearWidget : public QWidget {
Q_OBJECT
public:
    explicit BearWidget(QWidget *parent = nullptr);
    void setBearPixmap(QPixmap pixmap);
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
private:
    QPixmap bearPixmap;
    QPoint dragPosition;
    bool dragging;
};


#endif //CALCULATOR_BEARWIDGET_H
