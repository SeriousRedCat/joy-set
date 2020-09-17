#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <QVector>

class Drawable : virtual public sf::Drawable
{
    public:
        Drawable();
        virtual ~Drawable();

    protected:
        virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const override;

        QVector<sf::Drawable*> m_drawables;
};

#endif // DRAWABLE_HPP
