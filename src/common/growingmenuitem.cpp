#include "growingmenuitem.hpp"

GrowingMenuItem::GrowingMenuItem(int _value, bool _enabled):
    MenuItem(_value, _enabled),
    m_curve(QEasingCurve::Type::Linear),
    m_animationTime(0.),
    m_sizeFactor(1.),
    m_baseSize(getCharacterSize()),
    m_currentTime(0.),
    m_inProgress(false)
{

}

void GrowingMenuItem::init(const QString &_text, const sf::Font &_font)
{
    MenuItem::init(_text, _font);

    m_baseSize = getCharacterSize();
}

void GrowingMenuItem::setAnimationType(QEasingCurve::Type _type)
{
    m_curve = QEasingCurve(_type);
}

void GrowingMenuItem::setAnimationTime(double _animTime)
{
    m_animationTime = _animTime;
}

void GrowingMenuItem::setSizeFactor(double _sizeFactor)
{
    m_sizeFactor = _sizeFactor;
}

void GrowingMenuItem::calculate(int _x, int _y, double _dt)
{
    MenuItem::calculate(_x, _y, _dt);

    double factor = 1.;
    if(m_isActive)
    {
        m_currentTime += _dt;
        if(m_currentTime < m_animationTime)
        {
            const double progress = m_curve.valueForProgress(m_currentTime / m_animationTime);
            factor = 1. + (m_sizeFactor - 1.) * progress;
        }
        else
        {
            factor = m_sizeFactor;
            m_currentTime = m_animationTime;
        }
    }
    else
    {
        m_currentTime -= _dt;
        if(m_currentTime > 0)
        {
            const double progress = m_curve.valueForProgress(1 - m_currentTime / m_animationTime);
            factor = m_sizeFactor - (m_sizeFactor - 1.) * progress;
        }
        else
        {
            m_currentTime = 0;
        }
    }
    setCharacterSize(m_baseSize * factor);
    const sf::FloatRect textRect = getLocalBounds();
    setOrigin(textRect.left + textRect.width * 0.5, textRect.top + textRect.height * 0.5);
}
