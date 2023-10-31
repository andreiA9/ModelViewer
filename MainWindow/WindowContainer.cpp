#include "WindowContainer.h"

WindowContainer::WindowContainer(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("ModelViewer"));
    QWidget::resize(1600, 800);

    m_mainLayout = new QGridLayout(this);
    m_mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    QWidget::setLayout(m_mainLayout);
}

WindowContainer::~WindowContainer()
{
}

void WindowContainer::initializeDrawingButtons()
{
    m_lineButton0 = new QPushButton(this);
    m_triangleButton1 = new QPushButton(this);
    m_emptyRectangleButton2 = new QPushButton(this);
    m_filledRectangleButton3 = new QPushButton(this);
    m_upperButton4 = new QPushButton(this);

    m_lineButton0->setObjectName(QString("pushButton0"));
    m_lineButton0->setText("Line");
    m_lineButton0->setGeometry(QRect(20, 30, 40, 25));

    m_triangleButton1->setObjectName(QString("pushButton1"));
    m_triangleButton1->setText("Triangle");
    m_triangleButton1->setGeometry(QRect(110, 30, 40, 25));

    m_emptyRectangleButton2->setObjectName(QString("pushButton2"));
    m_emptyRectangleButton2->setText("Empty rectangle");
    m_emptyRectangleButton2->setGeometry(QRect(200, 30, 40, 25));

    m_filledRectangleButton3->setObjectName(QString("pushButton3"));
    m_filledRectangleButton3->setText("Filled rectangle");
    m_filledRectangleButton3->setGeometry(QRect(290, 30, 40, 25));

    m_upperButton4->setObjectName(QString("pushButton4"));
    m_upperButton4->setText("Button4");
    m_upperButton4->setGeometry(QRect(380, 30, 40, 25));

    // addLayout(QLayout * layout, int row, int column, int rowSpan, int columnSpan, Qt::Alignment alignment = 0)
    m_upperButtonsLayout = new QHBoxLayout();
    m_upperButtonsLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_upperButtonsLayout, 0, 0, 1, 8);

    m_upperButtonsLayout->setObjectName(QString("verticalLayout"));
    m_upperButtonsLayout->addWidget(m_lineButton0);
    m_upperButtonsLayout->addWidget(m_triangleButton1);
    m_upperButtonsLayout->addWidget(m_emptyRectangleButton2);
    m_upperButtonsLayout->addWidget(m_filledRectangleButton3);
    m_upperButtonsLayout->addWidget(m_upperButton4);

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // AI RAMAS
    // 1. SPACING ul nu iti merge
    // 2. trebuie sa faci SIZE POLICY = EXPANDING pentru QIMAGE = DrawingView
    m_upperButtonsLayout->setSpacing(20);
}

void WindowContainer::initializeOperationButtons()
{
    m_translateCheckbox = new QCheckBox(this);
    m_scaleCheckbox = new QCheckBox(this);
    m_rotateCheckbox = new QCheckBox(this);

    m_translateCheckbox->setObjectName(QString("checkBox0"));
    m_translateCheckbox->setText("Translate");
    m_translateCheckbox->setGeometry(QRect(20, 30, 20, 25));

    m_scaleCheckbox->setObjectName(QString("checkBox1"));
    m_scaleCheckbox->setText("Scale");
    m_scaleCheckbox->setGeometry(QRect(50, 30, 20, 25));

    m_rotateCheckbox->setObjectName(QString("checkBox2"));
    m_rotateCheckbox->setText("Rotate");
    m_rotateCheckbox->setGeometry(QRect(80, 30, 20, 25));

    // addLayout(QLayout * layout, int row, int column, int rowSpan, int columnSpan, Qt::Alignment alignment = 0)
    m_belowCheckboxesLayout = new QHBoxLayout();
    m_belowCheckboxesLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_belowCheckboxesLayout, 1, 0, 1, 8);

    m_belowCheckboxesLayout->setObjectName(QString("verticalLayout"));
    m_belowCheckboxesLayout->addWidget(m_translateCheckbox);
    m_belowCheckboxesLayout->addWidget(m_scaleCheckbox);
    m_belowCheckboxesLayout->addWidget(m_rotateCheckbox);

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // AI RAMAS
    // 1. SPACING ul nu iti merge
    // 2. trebuie sa faci SIZE POLICY = EXPANDING pentru QIMAGE = DrawingView
    m_belowCheckboxesLayout->setSpacing(20);
}

void WindowContainer::initializeGlWidget(GlWidget* openGLWidget)
{
    openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
    m_glWidgetLayout = new QHBoxLayout(this);
    m_glWidgetLayout->setSpacing(6);
    m_glWidgetLayout->setObjectName(QString::fromUtf8("glWidgetLayout"));
    m_glWidgetLayout->setContentsMargins(0, 0, 0, 0);
    m_glWidgetLayout->addWidget(openGLWidget);
    m_mainLayout->addLayout(m_glWidgetLayout, 2, 0, 6, 8);
}
