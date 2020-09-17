#include "physicalobject.hpp"

PhysicalObject::PhysicalObject(b2World *_world):
    m_world(_world)
{

}

b2Body *PhysicalObject::addPart(const b2BodyDef &_bdef, const b2FixtureDef &_fdef)
{
    b2Body* body = m_world->CreateBody(&_bdef);
    body->CreateFixture(&_fdef);
    m_bodies.push_back(body);
    return body;
}
