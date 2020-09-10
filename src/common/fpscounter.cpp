#include "fpscounter.hpp"

#include <QString>

constexpr unsigned int DEFAULT_FPS_SIZE = 12;

FPSCounter::FPSCounter():
    m_elapsedTime(0.),
    m_fps(0u)
{
    setCharacterSize(DEFAULT_FPS_SIZE);
}

void FPSCounter::update(double _dt)
{
    m_elapsedTime += _dt;
    if(m_elapsedTime > 1.)
    {
        updateText(m_fps);
        m_fps = 0u;
        m_elapsedTime = 0.;
    }
    ++m_fps;
}

void FPSCounter::updateText(unsigned int fps)
{
    setString(QString("FPS: %1").arg(fps).toStdString());
}
