#ifndef GL_MODULE_H
#define GL_MODULE_H

#include "GlWidget.h"
#include "SceneController.h"

class GlModule
{
public:
    GlModule(GlWidget* openGlWidget);

    void drawLineTriggered();

    void drawTriangleTriggered();

    void drawEmptyRectangleTriggered();

    void drawFilledRectangleTriggered();

    void translateTriggered();

    void scaleTriggered();

    void rotateTriggered();

private:
    GlWidget* m_openGlWidget;
    Events* m_events = nullptr;
};

#endif // GL_MODULE_H
