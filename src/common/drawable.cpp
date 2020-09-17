#include "drawable.hpp"

Drawable::Drawable()
{

}

Drawable::~Drawable()
{

}

void Drawable::draw(sf::RenderTarget &_target, sf::RenderStates _states) const
{
    for(const sf::Drawable* drawable : m_drawables)
        _target.draw(*drawable, _states);
}
