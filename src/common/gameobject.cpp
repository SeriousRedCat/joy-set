#include "gameobject.hpp"
#include "physicalstage.hpp"

#include <QtMath>

GameObject::GameObject(PhysicalStage *_stage): PhysicalObject(_stage->world()),
    m_stage(_stage)
{

}

void GameObject::updateGraphics()
{
    for(decltype(m_fixture2Transformable)::const_iterator it = m_fixture2Transformable.constBegin();
        it != m_fixture2Transformable.constEnd(); ++it)
    {
        const b2Body* body = it.key()->GetBody();
        sf::Transformable* transformable = it.value();
        const b2Vec2 position = body->GetPosition();

        transformable->setPosition(m_stage->world2Screen(position.x, position.y));
        transformable->setRotation(-qRadiansToDegrees(body->GetAngle()));
    }
}
