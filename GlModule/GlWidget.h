#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "SceneController.h"
#include "Events.h"

#include <QWidget>
#include <QOpenGLWidget>

class GlWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit GlWidget(QWidget *parent = nullptr);

    void setEvents(Events* events);

    void mousePressEvent(QMouseEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void paintGL() override;

private:
    QPoint m_lastMovePosition;
    QPointF m_glDeltaPosition;
    Events* m_events;
};

#endif // GLWIDGET_H
