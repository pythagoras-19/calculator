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

void ClickableLabel::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    // Translate the coordinate system's origin to the center of the label
    painter.translate(width() / 2, height() / 2);
    // Rotate around the new origin (center of the label)
    painter.rotate(m_rotation);
    // Translate back so that the drawing happens at the correct position
    painter.translate(-width() / 2, -height() / 2);
    // Call the base class paintEvent to draw the label as usual
    QLabel::paintEvent(event);
}

