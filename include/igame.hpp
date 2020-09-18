#ifndef IGAME_HPP
#define IGAME_HPP

#include <SFML/Window/Event.hpp>

#include <QList>

namespace sf{
    class RenderWindow;
}

class ResourceManager;

class IGame
{
    public:
        enum StageType{
            EXIT = 0,
            MENU,
            USER_STAGE = 1000
        };
        virtual ~IGame() = default;

        virtual bool init() = 0;

        virtual const QList<sf::Event> pollEvents() = 0;
        virtual const sf::Vector2i cursorPos() const = 0;

        virtual sf::RenderWindow* renderWindow() const = 0;
        virtual const ResourceManager* resources() const = 0;
};

#endif // IGAME_HPP
