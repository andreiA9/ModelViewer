#ifndef APPLICATION_WINDOW_H
#define APPLICATION_WINDOW_H

#include "WindowContainer.h"
#include "GlModule.h"

class ApplicationWindow : public WindowContainer
{
    Q_OBJECT

public:
    ApplicationWindow();

    void initializeConnects();

private slots:
    void handleButtonFunction();

    void handleCheckboxFunction();

private:
    GlModule* m_glModule;
};

#endif // APPLICATION_WINDOW_H
