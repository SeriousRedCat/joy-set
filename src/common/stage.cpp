#include "stage.hpp"
#include "igame.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

Stage::Stage(IGame *_game):
    m_game(_game)
{

}

const OutputData Stage::outputData() const
{
    return m_outputData;
}

bool Stage::run(double _dt, const QList<sf::Event> &_events)
{
    const bool inProgress = calculate(_dt, _events);
        updateGraphics();

        m_game->renderWindow()->clear(sf::Color::Black);
        draw(m_game->renderWindow());
        m_game->renderWindow()->display();

        return inProgress;
}

bool Stage::calculate(double _dt, const QList<sf::Event> &events)
{
    return true;
}

void Stage::updateGraphics()
{

}

void Stage::draw(sf::RenderTarget *_target) const
{

}

void Stage::reset()
{

}
