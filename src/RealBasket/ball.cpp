#include "ball.hpp"

#include "common/physicalstage.hpp"
#include "igame.hpp"
#include "common/resourcemanager.hpp"

static constexpr float BALL_DENSITY = 1.f;
static constexpr float BALL_FRICTION = 1.f;
static constexpr float BALL_RESTITUTION = 0.5f;

Ball::Ball(PhysicalStage *_stage, double _x, double _y, double _radius):
    GameObject(_stage), m_inBasket(false), m_isThrown(false), m_throwDistance(0.)
{
    b2BodyDef bdef;
    bdef.type = b2_dynamicBody;
    bdef.position.Set(_x, _y);

    b2CircleShape cshape;
    cshape.m_radius = _radius;

    b2FixtureDef fdef;
    fdef.shape = &cshape;
    fdef.density = BALL_DENSITY;
    fdef.friction = BALL_FRICTION;
    fdef.restitution = BALL_RESTITUTION;
    fdef.filter.categoryBits = 0x0002;

    auto fixture = addPart(bdef, fdef)->GetFixtureList();
    fixture->SetUserData(this);
    sf::Sprite* sprite = new sf::Sprite(m_stage->game()->resources()->texture("ball"));
    double scale = (_radius * 2. * m_stage->pixelsPerMeter()) / sprite->getLocalBounds().width;
    double origin = _radius * m_stage->pixelsPerMeter() / scale;
    sprite->setScale(scale, scale);
    sprite->setOrigin(origin, origin);

    assignSprite(fixture, sprite);
}

Ball::~Ball()
{

}

b2Vec2 Ball::position() const
{
    return m_bodies.at(0)->GetPosition();
}

bool Ball::inBasket() const
{
    return m_inBasket;
}

double Ball::throwDistance() const
{
    return m_throwDistance;
}

bool Ball::isThrown() const
{
    return m_isThrown;
}

b2Vec2 Ball::thrownPosition() const
{
    return m_thrownPosition;
}

b2Body *Ball::body() const
{
    return m_bodies[0];
}

void Ball::setInBasket(bool _in)
{
    m_inBasket = _in;
}

void Ball::setThrown(bool _thrown)
{
    m_isThrown = _thrown;
    m_thrownPosition = _thrown ? position() : b2Vec2();
}

void Ball::calculateThrowDistance(double _basket_pos)
{
    double myX = position().x;
    m_throwDistance = std::abs(_basket_pos - myX);
}

void Ball::resetThrowDistance()
{
    m_throwDistance = 0.;
}
