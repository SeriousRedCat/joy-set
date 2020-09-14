#include "physicalstage.hpp"
#include "igame.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

constexpr int DEFAULT_VELOCITY_ITERATIONS = 6;
constexpr int DEFAULT_POSITION_ITERATIONS = 16;

PhysicalStage::PhysicalStage(IGame *_game, double _pixPerMeter, const b2Vec2 &_gravity):
    Stage(_game),
    m_world(new b2World(_gravity)),
    m_pixPerMeter(_pixPerMeter),
    m_worldSize(m_game->renderWindow()->getSize().x /_pixPerMeter,
                m_game->renderWindow()->getSize().y / _pixPerMeter)
{

}

PhysicalStage::~PhysicalStage()
{
    delete m_world;
}

bool PhysicalStage::calculate(double _dt, const QList<sf::Event>& _events)
{
    Stage::calculate(_dt, _events);

    m_world->Step(static_cast<float>(_dt),
                  DEFAULT_VELOCITY_ITERATIONS,
                  DEFAULT_POSITION_ITERATIONS);

    return true;
}
