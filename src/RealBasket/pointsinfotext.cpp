#include "pointsinfotext.hpp"

#include <QString>

PointsInfoText::PointsInfoText(const sf::Font &font, double _points, int _x,
                               int _y_start, int _y_end, double _time,
                               double _time_to_start):
    m_currentTime(0.),
    m_x(_x),
    m_startY(_y_start),
    m_endY(_y_end),
    m_timeAll(_time),
    m_timeStart(_time_to_start),
    m_curve(QEasingCurve::Linear),
    m_done(false)
{
    setFont(font);
    setString(QString::number(_points, 'f', 3).toStdString());
}

void PointsInfoText::init()
{
    setStyle(sf::Text::Bold);
    setOutlineThickness(1);
    setCharacterSize(30);
    setFillColor(sf::Color(100,100,100));
    setOutlineColor(sf::Color::Yellow);

    sf::FloatRect textRect = getLocalBounds();
    setOrigin(textRect.left + textRect.width * 0.5, textRect.top + textRect.height * 0.5);

    setPosition(m_x, m_startY);
}

void PointsInfoText::calculate(double _dt)
{
    m_currentTime += _dt;

    if(m_currentTime > m_timeStart)
    {
        auto pos = getPosition();
        const double delta = m_curve.valueForProgress((m_currentTime - m_timeStart)/(m_timeAll - m_timeStart));
        pos.y = m_startY - (m_startY - m_endY) * delta;
        setPosition(pos);
        sf::Color fc = getFillColor();
        sf::Color oc = getOutlineColor();
        fc.a = 255 * (1 - delta);
        oc.a = fc.a;
        setFillColor(fc);
        setOutlineColor(oc);
    }

    if(m_currentTime > m_timeAll)
        m_done = true;
}

bool PointsInfoText::isDone() const
{
    return m_done;
}
