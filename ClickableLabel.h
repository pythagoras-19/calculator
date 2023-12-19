//
// Created by Matthew Christiansen on 12/18/23.
//

#ifndef CALCULATOR_CLICKABLELABEL_H
#define CALCULATOR_CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event) override;
};



#endif //CALCULATOR_CLICKABLELABEL_H
