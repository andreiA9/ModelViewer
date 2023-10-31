#include "ApplicationWindow.h"

ApplicationWindow::ApplicationWindow()
{
    initializeDrawingButtons();
    initializeOperationButtons();

    GlWidget* openGLWidget = new GlWidget(this);
    m_glModule = new GlModule(openGLWidget);
    initializeGlWidget(openGLWidget);

    initializeConnects();
}

void ApplicationWindow::initializeConnects()
{
    connect(m_lineButton0, &QPushButton::pressed, this, &ApplicationWindow::handleButtonFunction);
    connect(m_triangleButton1, &QPushButton::pressed, this, &ApplicationWindow::handleButtonFunction);
    connect(m_emptyRectangleButton2, &QPushButton::pressed, this, &ApplicationWindow::handleButtonFunction);
    connect(m_filledRectangleButton3, &QPushButton::pressed, this, &ApplicationWindow::handleButtonFunction);
    connect(m_translateCheckbox, &QCheckBox::pressed, this, &ApplicationWindow::handleCheckboxFunction);
    connect(m_scaleCheckbox, &QCheckBox::pressed, this, &ApplicationWindow::handleCheckboxFunction);
    connect(m_rotateCheckbox, &QCheckBox::pressed, this, &ApplicationWindow::handleCheckboxFunction);
}

void ApplicationWindow::handleButtonFunction()
{
    QObject* sender = QObject::sender();
    if      (sender == m_lineButton0)
    {
        m_glModule->drawLineTriggered();
    }
    else if (sender == m_triangleButton1)
    {
        m_glModule->drawTriangleTriggered();
    }
    else if (sender == m_emptyRectangleButton2)
    {
        m_glModule->drawEmptyRectangleTriggered();
    }
    else if (sender == m_filledRectangleButton3)
    {
        m_glModule->drawFilledRectangleTriggered();
    }
}

void ApplicationWindow::handleCheckboxFunction()
{
    QObject* sender = QObject::sender();
    if      (sender == m_translateCheckbox)
    {
        m_glModule->translateTriggered();
    }
    else if (sender == m_scaleCheckbox)
    {
        m_glModule->scaleTriggered();
    }
    else if (sender == m_rotateCheckbox)
    {
        m_glModule->rotateTriggered();
    }
}
