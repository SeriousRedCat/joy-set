#include "practice.hpp"
#include "pointlistener.hpp"

Practice::Practice(IGame* _game):
    PhysicalStage(_game, 100., b2Vec2(0.0, -7.8)),
    m_caughtBall(nullptr),
    m_basket(nullptr),
    m_mouseJoint(nullptr),
    m_pointListener(nullptr)
{

}
