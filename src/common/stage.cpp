#include "stage.hpp"
#include "igame.hpp"

#include "../common/resourcemanager.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

static const sf::Vector2f DEFAULT_FPS_POSITION(740, 2);
static const QString DEFAULT_FPS_FONT_NAME("calibril");

Stage::Stage(IGame *_game):
    m_game(_game)
{
    m_fpsCounter.setFont(m_game->resources()->font(DEFAULT_FPS_FONT_NAME));
    m_fpsCounter.setPosition(DEFAULT_FPS_POSITION);
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
    m_fpsCounter.update(_dt);
    return true;
}

void Stage::updateGraphics()
{

}

void Stage::draw(sf::RenderTarget *_target) const
{
    _target->draw(m_fpsCounter);
}

void Stage::reset()
{

}

IGame *Stage::game() const
{
    return m_game;
}
