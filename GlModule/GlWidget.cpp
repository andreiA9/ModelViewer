#include "GlWidget.h"

#include <QDesktopWidget>
#include <QApplication>
#include <QMouseEvent>
#include <QDir>
#include <QDebug>

static QPointF calculateGlDeltaPosition(const QPoint& lastMousePosition,
                                        const QPoint& currentMousePosition)
{
    int deltaX = lastMousePosition.x() - currentMousePosition.x();
    int deltaY = lastMousePosition.y() - currentMousePosition.y();
    qDebug() << "deltaX: " << deltaX;
    qDebug() << "deltaY: " << deltaY;

    QPointF glDeltaPosition;
    if (deltaX > 9)
    {
        glDeltaPosition.setX(glDeltaPosition.x() + 0.1);
    }
    else if (deltaX > 6)
    {
        glDeltaPosition.setX(glDeltaPosition.x() + 0.01);
    }
    else if (deltaX > 3)
    {
        glDeltaPosition.setX(glDeltaPosition.x() + 0.001);
    }
    else if (deltaX > 0)
    {
        glDeltaPosition.setX(glDeltaPosition.x() + 0.0001);
    }
    else if (deltaX > -3)
    {
        glDeltaPosition.setX(glDeltaPosition.x() - 0.0001);
    }
    else if (deltaX > -6)
    {
        glDeltaPosition.setX(glDeltaPosition.x() - 0.001);
    }
    else if (deltaX > -9)
    {
        glDeltaPosition.setX(glDeltaPosition.x() - 0.01);
    }
    else
    {
        glDeltaPosition.setX(glDeltaPosition.x() - 0.01);
    }

    if (deltaY > 9)
    {
        glDeltaPosition.setY(glDeltaPosition.y() + 0.1);
    }
    else if (deltaY > 6)
    {
        glDeltaPosition.setY(glDeltaPosition.y() + 0.01);
    }
    else if (deltaY > 3)
    {
        glDeltaPosition.setY(glDeltaPosition.y() + 0.001);
    }
    else if (deltaY > 0)
    {
        glDeltaPosition.setY(glDeltaPosition.y() + 0.0001);
    }
    else if (deltaY > -3)
    {
        glDeltaPosition.setY(glDeltaPosition.y() - 0.0001);
    }
    else if (deltaY > -6)
    {
        glDeltaPosition.setY(glDeltaPosition.y() - 0.001);
    }
    else if (deltaY > -9)
    {
        glDeltaPosition.setY(glDeltaPosition.y() - 0.01);
    }
    else
    {
        glDeltaPosition.setY(glDeltaPosition.y() - 0.01);
    }

    qDebug() << "glDeltaPosition.x(): " << glDeltaPosition.x();
    qDebug() << "glDeltaPosition.y(): " << glDeltaPosition.y();
    return glDeltaPosition;
}

GlWidget::GlWidget(QWidget* parent)
{
    
}

void GlWidget::setEvents(Events* events)
{
    m_events = events;
}

void GlWidget::mousePressEvent(QMouseEvent* event)
{
    m_lastMovePosition = event->pos();
    // setCursor(Qt::BlankCursor);
    // este NEVOIE.de FUNCTIA.asta>incat sa
    // iti ia COORDONATELE.BUNE.pentru MOUSE
//    QCursor::setPos(mapToGlobal(rect().center()));
    // sceneController->callMousePressEventHandler(virtual_pos);
    QWidget::mousePressEvent(event);
}

void GlWidget::mouseMoveEvent(QMouseEvent* event)
{
    m_glDeltaPosition = calculateGlDeltaPosition(m_lastMovePosition, event->pos());
    m_lastMovePosition = event->pos();
}

void GlWidget::paintGL()
{
    Events::Action action = m_events->getCurrentAction();
    Events::DrawEvent drawEvent = m_events->getCurrentEvent();
    if (drawEvent == Events::Line)
    {
        glColor3f(0.9, 0.1, 0.2);
        Rect lineRectangle = {-1, 1, 0, 0};
        SceneController::drawLine(lineRectangle);
    }

    if (drawEvent == Events::Triangle)
    {
        Triangle triangle;
        triangle.topX = 0;
        triangle.topY = 1;
        triangle.bottomLeftX = -1;
        triangle.bottomLeftY = -1;
        triangle.bottomRightX = 1;
        triangle.bottomRightY = -1;
        if (action == Events::Translate)
        {
            SceneController::drawTriangle(triangle, true, false, false, m_glDeltaPosition);
        }
        else if (action == Events::Scale)
        {
            SceneController::drawTriangle(triangle, false, true, false, m_glDeltaPosition);
        }
        else if (action == Events::Rotate)
        {
            SceneController::drawTriangle(triangle, false, false, true, m_glDeltaPosition);
        }
        else if (action == Events::NoAction)
        {
            SceneController::drawTriangle(triangle, false, false, false, m_glDeltaPosition);
        }
    }

    if (drawEvent == Events::EmptyRectangle)
    {
        glColor3f(0.2, 0.1, 0.9);
        Rect emptyRectangle = {0, 0, 1, 1};
        SceneController::drawEmptyRectangle(emptyRectangle);
    }

    if (drawEvent == Events::FilledRectangle)
    {
        glColor3f(0.5, 0.5, 0.5);
        Rect filledRectangle = {-1, -1, 0, 0};
        SceneController::drawRectangle(filledRectangle);
    }

    // this will call paintEvent() on the QOpenGLWidget
    QOpenGLWidget::update();
}
