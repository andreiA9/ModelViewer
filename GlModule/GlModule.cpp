#include "GlModule.h"

GlModule::GlModule(GlWidget* openGlWidget)
    : m_openGlWidget(openGlWidget)
{
    m_events = new Events;
    m_openGlWidget->setEvents(m_events);
}

void GlModule::drawLineTriggered()
{
    m_events->setEventEnabled(Events::Line);
}

void GlModule::drawTriangleTriggered()
{
    m_events->setEventEnabled(Events::Triangle);
}

void GlModule::drawEmptyRectangleTriggered()
{
    m_events->setEventEnabled(Events::EmptyRectangle);
}

void GlModule::drawFilledRectangleTriggered()
{
    m_events->setEventEnabled(Events::FilledRectangle);
}

void GlModule::translateTriggered()
{
    if (m_events->getCurrentAction() == Events::Translate)
    {
        m_events->setActionEnabled(Events::NoAction);
    }
    else
    {
        m_events->setActionEnabled(Events::Translate);
    }
}

void GlModule::scaleTriggered()
{
    if (m_events->getCurrentAction() == Events::Scale)
    {
        m_events->setActionEnabled(Events::NoAction);
    }
    else
    {
        m_events->setActionEnabled(Events::Scale);
    }
}

void GlModule::rotateTriggered()
{
    if (m_events->getCurrentAction() == Events::Rotate)
    {
        m_events->setActionEnabled(Events::NoAction);
    }
    else
    {
        m_events->setActionEnabled(Events::Rotate);
    }
}
