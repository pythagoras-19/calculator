//
// Created by Matthew Christiansen on 12/18/23.
//

#include "ClickableLabel.h"
#include <QMouseEvent>

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
        : QLabel(parent, f) {
    // Constructor
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    QLabel::mousePressEvent(event);
    emit clicked();
}
