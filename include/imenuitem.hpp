#ifndef IMENUITEM_HPP
#define IMENUITEM_HPP

#include <SFML/Graphics/Text.hpp>

#include <QString>

class IMenuItem : public sf::Text
{
    public:
        virtual ~IMenuItem() = default;

        virtual void init(const QString& _text, const sf::Font& _font) = 0;
        virtual int value() const = 0;
        virtual bool isEnabled() const = 0;
        virtual bool isActive() const = 0;

        virtual void calculate(int _x, int _y, double _dt) = 0;

        virtual void activate(bool _active) = 0;
};

#endif // IMENUITEM_HPP
