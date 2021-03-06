#include "controlbutton.h"
#include <QToolTip>
#include <QEvent>
#include <QMouseEvent>

controlButton::controlButton(QWidget *parent)
    : QPushButton(parent)
{
    setMouseTracking(true);
}

bool controlButton::eventFilter(QObject *obj, QEvent *event){
    Q_UNUSED(obj);
    if(event->type() == QEvent::ToolTip){
        return true;
    }
    return false;
}

void controlButton::mouseMoveEvent(QMouseEvent *e){

    QToolTip::showText(this->mapToGlobal(e->localPos().toPoint()),this->toolTip());

    QPushButton::mouseMoveEvent(e);
}
