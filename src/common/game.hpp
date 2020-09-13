#ifndef GAME_HPP
#define GAME_HPP

#include "igame.hpp"
#include "resourcemanager.hpp"

#include <QMap>

namespace sf {
    class RenderWindow;
}

class IStageFactory;

class Game : public IGame
{
    public:
        enum StageType{
            EXIT = 0,
            MENU,
            USER_STAGE = 1000
        };

        Game();
        virtual ~Game() override;

        virtual void run();

        virtual bool init() override;

        virtual const QList<sf::Event> pollEvents() override;

        const sf::Vector2i cursorPos() const override final;
        virtual sf::RenderWindow* renderWindow() const override;
        virtual const ResourceManager* resources() const override;

    protected:
        int m_stage;
        sf::RenderWindow* m_window;
        QMap<int, IStageFactory*> m_stages;

        ResourceManager m_resources;
};

#endif // GAME_HPP
