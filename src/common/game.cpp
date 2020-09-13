#include "game.hpp"
#include "istage.hpp"
#include "istagefactory.hpp"

#include <SFML/Graphics.hpp>

Game::Game():
    m_stage(Game::MENU),
    m_window(new sf::RenderWindow(sf::VideoMode(800, 600),
                                  QString("%1 v.%2").arg("test").arg("test").toStdString(),
                                  sf::Style::Default, sf::ContextSettings(0,0,0)))
{
}

Game::~Game()
{
    delete m_window;
}

void Game::run()
{
    while(Game::EXIT != m_stage)
    {
        OutputData data;

        if(IStageFactory* stageFactory = m_stages.value(m_stage, nullptr);
                        stageFactory)
        {
            if(IStage* stage = stageFactory->createStage(); stage)
            {
                sf::Clock clock;
                sf::Time elapsed;

                bool inProgress = true;
                while(inProgress)
                {
                    elapsed = clock.restart();

                    inProgress = stage->run(static_cast<double>(elapsed.asSeconds()),
                                            pollEvents());
                }

                data = stage->outputData();
                m_stage = data.nextStage;

                stageFactory->releaseStage();
            }
        }
        else
        {
            m_stage = Game::EXIT;
        }
    }
}

bool Game::init()
{
    return true;
}

const QList<sf::Event> Game::pollEvents()
{
    QList<sf::Event> rval;
    sf::Event event;
    while (m_window->pollEvent(event))
    {
        rval.append(event);
    }
    return rval;
}

const sf::Vector2i Game::cursorPos() const
{
    return sf::Mouse::getPosition(*m_window);
}

sf::RenderWindow *Game::renderWindow() const
{
    return m_window;
}

const ResourceManager* Game::resources() const
{
    return &m_resources;
}

