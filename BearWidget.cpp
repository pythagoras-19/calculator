//
// Created by Matthew Christiansen on 1/9/24.
//

#include "BearWidget.h"

BearWidget::BearWidget(QWidget *parent) : QWidget(parent), dragging(false) {
    bearPixmap = QPixmap("/Users/mattc/CLionProjects/calculator/bear_cute.png");
}

void BearWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && bearPixmap.rect().contains(event->pos())) {
        dragging = true;
        dragPosition = event->pos();
    }
}

void BearWidget::mouseMoveEvent(QMouseEvent *event) {
    if (dragging) {
        int dx = event->pos().x() - dragPosition.x();
        int dy = event->pos().y() - dragPosition.y();
        move(pos() + QPoint(dx, dy));
    }
}

void BearWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = false;
    }
}

void BearWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, bearPixmap);
}

void BearWidget::setBearPixmap(QPixmap pixmap) {
    bearPixmap = pixmap;
    update(); // Redraw widget
}
