#ifndef WINDOW_CONTAINER_H
#define WINDOW_CONTAINER_H

#include "GlWidget.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QCheckBox>

class WindowContainer : public QWidget
{
    Q_OBJECT

public:
    WindowContainer(QWidget *parent = nullptr);
    ~WindowContainer();

    void initializeDrawingButtons();

    void initializeOperationButtons();

    void initializeGlWidget(GlWidget* openGLWidget);

protected:
    QGridLayout* m_mainLayout;
    QHBoxLayout* m_glWidgetLayout;

    // upper buttons
    QHBoxLayout* m_upperButtonsLayout;
    QPushButton* m_lineButton0;
    QPushButton* m_triangleButton1;
    QPushButton* m_emptyRectangleButton2;
    QPushButton* m_filledRectangleButton3;
    QPushButton* m_upperButton4;

    // below check-boxes
    QHBoxLayout* m_belowCheckboxesLayout;
    QCheckBox* m_translateCheckbox;
    QCheckBox* m_scaleCheckbox;
    QCheckBox* m_rotateCheckbox;
};

#endif // WINDOW_CONTAINER_H
