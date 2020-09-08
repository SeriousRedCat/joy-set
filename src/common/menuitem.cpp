#include "menuitem.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

MenuItem::MenuItem(int _value, bool _enabled):
    m_value(_value),
    m_isEnabled(_enabled)
{

}

int MenuItem::value() const
{
    return m_value;
}

bool MenuItem::isActive() const
{
    return m_isActive;
}

bool MenuItem::isEnabled() const
{
    return m_isEnabled;
}

void MenuItem::calculate(int _x, int _y, double _dt)
{
    (void)_dt;
    m_isActive = getGlobalBounds().contains(_x, _y);
}

void MenuItem::activate(bool _active)
{
    setFillColor(_active ? sf::Color::Yellow : sf::Color::Red);
}
