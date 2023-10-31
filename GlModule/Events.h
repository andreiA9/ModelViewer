#ifndef EVENTS_H
#define EVENTS_H

class Events
{
public:
    enum DrawEvent
    {
        NoEvent,
        Line,
        Triangle,
        EmptyRectangle,
        FilledRectangle
    };

    enum Action
    {
        NoAction,
        Translate,
        Scale,
        Rotate
    };

    Events();

    inline Action getCurrentAction() const { return m_action; }

    void setActionEnabled(Action action)
    {
        m_previousAction = m_action;
        m_action = action;
    }

    void resetToPreviousAction() { m_action = m_previousAction; }

    inline DrawEvent getCurrentEvent() const { return m_event; }

    void setEventEnabled(DrawEvent event)
    {
        m_previousEvent = m_previousEvent;
        m_event = event;
    }

    void resetToPreviousEvent() { m_event = m_previousEvent; }

private:
    DrawEvent m_event;
    DrawEvent m_previousEvent;
    Action m_action;
    Action m_previousAction;
};

#endif // EVENTS_H
