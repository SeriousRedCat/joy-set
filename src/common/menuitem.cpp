#include "menuitem.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

MenuItem::MenuItem(int _value, bool _enabled):
    m_value(_value),
    m_isEnabled(_enabled)
{

}

void MenuItem::init(const QString& _text, const sf::Font& _font)
{
    setStyle(sf::Text::Bold);
    setOutlineThickness(1);
    setCharacterSize(30);
    setFont(_font);
    setString(_text.toStdString());
    setFillColor(sf::Color(m_isEnabled ? 0xFF0000FF : 0x646464FF));
    setOutlineColor(sf::Color::Green);
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
