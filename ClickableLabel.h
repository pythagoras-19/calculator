//
// Created by Matthew Christiansen on 12/18/23.
//

#ifndef CALCULATOR_CLICKABLELABEL_H
#define CALCULATOR_CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <QDebug>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    int rotation() const;
    void setRotation(int rotation);

signals:
    void clicked();
    void rotationChanged();


protected:
    void mousePressEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    int m_rotation = 0;
};



#endif //CALCULATOR_CLICKABLELABEL_H
