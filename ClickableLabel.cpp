//
// Created by Matthew Christiansen on 12/18/23.
//

#include "ClickableLabel.h"
#include <QMouseEvent>
#include <QPainter>

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
        : QLabel(parent, f) {}

int ClickableLabel::rotation() const {
    return m_rotation;
}

void ClickableLabel::setRotation(int newRotation) {
    if (m_rotation == newRotation)
        return;
    m_rotation = newRotation;
    emit rotationChanged();
    update(); // Trigger a repaint
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    QLabel::mousePressEvent(event);
    emit clicked();
}

/* TODO: GET RID OF THIS */
void ClickableLabel::paintEvent(QPaintEvent* event) {
    qDebug("paintEvent called.");
    QPainter painter(this);
    painter.translate(width() / 2, height() / 2);
    painter.rotate(m_rotation);
    painter.translate(-width() / 2, -height() / 2);
    QLabel::paintEvent(event);
}

