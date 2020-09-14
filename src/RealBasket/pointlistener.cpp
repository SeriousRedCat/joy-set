#include "pointlistener.hpp"
#include "ipractice.hpp"
#include "iball.hpp"

#include <QDebug>

PointListener::PointListener(IPractice *_stage):
    m_stage(_stage),
    m_basketHeight(_stage->basketHeight())
{

}

void PointListener::BeginContact(b2Contact *contact)
{
    int typeA = contact->GetFixtureA()->GetFilterData().categoryBits;
    int typeB = contact->GetFixtureB()->GetFilterData().categoryBits;

    int needed = static_cast<int>(EnFixtureType::BALL) | static_cast<int>(EnFixtureType::POINT_SENSOR);
    int current = (typeA | typeB);
    if(current != needed)
        return;

    IBall* ball =
            typeA == static_cast<int>(EnFixtureType::BALL) ?
                static_cast<IBall*>(contact->GetFixtureA()->GetUserData()) :
                static_cast<IBall*>(contact->GetFixtureB()->GetUserData());

    if(!ball->isThrown())
        return;

    if(ball->position().y > m_basketHeight)
        ball->setInBasket(true);
}

void PointListener::EndContact(b2Contact *contact)
{
    int typeA = contact->GetFixtureA()->GetFilterData().categoryBits;
    int typeB = contact->GetFixtureB()->GetFilterData().categoryBits;

    int needed = static_cast<int>(EnFixtureType::BALL) | static_cast<int>(EnFixtureType::POINT_SENSOR);
    int current = (typeA | typeB);
    if(current != needed)
        return;

    IBall* ball =
            typeA == static_cast<int>(EnFixtureType::BALL) ?
                static_cast<IBall*>(contact->GetFixtureA()->GetUserData()) :
                static_cast<IBall*>(contact->GetFixtureB()->GetUserData());

    if(!ball->isThrown())
        return;

    if(ball->position().y < m_basketHeight && ball->inBasket())
    {
        emit pointsEarned(ball);
        ball->setThrown(false);
        qDebug() << "Yeah";
    }
    ball->setInBasket(false);
}
