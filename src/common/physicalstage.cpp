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

b2World *PhysicalStage::world() const
{
    return m_world;
}

bool PhysicalStage::calculate(double _dt, const QList<sf::Event>& _events)
{
    Stage::calculate(_dt, _events);

    m_world->Step(static_cast<float>(_dt),
                  DEFAULT_VELOCITY_ITERATIONS,
                  DEFAULT_POSITION_ITERATIONS);

    return true;
}

sf::Vector2f PhysicalStage::world2Screen(double _x, double _y) const
{
    return sf::Vector2f(_x * m_pixPerMeter, (m_worldSize.y - _y) * m_pixPerMeter);
}

b2Vec2 PhysicalStage::screen2World(double _x, double _y) const
{
    return b2Vec2(_x / m_pixPerMeter, (m_game->renderWindow()->getSize().y - _y) / m_pixPerMeter);
}

double PhysicalStage::pixelsPerMeter() const
{
    return m_pixPerMeter;
}

void PhysicalStage::createFrame(int _frame)
{
    b2BodyDef bdef;
    bdef.type = b2_staticBody;
    bdef.position.Set(0,0);

    m_frame = m_world->CreateBody(&bdef);
    b2Vec2 ld(0, 0),
            lg(0, m_worldSize.y),
            pd(m_worldSize.x, 0),
            pg(m_worldSize.x, m_worldSize.y);

    b2EdgeShape edge;

    b2FixtureDef fdef;
    fdef.shape = &edge;
    fdef.restitution = 0.8f;

    if(_frame & BOTTOM)
    {
        edge.Set(ld, pd);
        m_frame->CreateFixture(&fdef);
    }
    if(_frame & TOP)
    {
        edge.Set(lg, pg);
        m_frame->CreateFixture(&fdef);
    }
    if(_frame & LEFT)
    {
        edge.Set(lg, ld);
        m_frame->CreateFixture(&fdef);
    }
    if(_frame & RIGHT)
    {
        edge.Set(pg, pd);
        m_frame->CreateFixture(&fdef);
    }
}
