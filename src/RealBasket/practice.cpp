#include "practice.hpp"
#include "pointlistener.hpp"
#include "ball.hpp"
#include "ballcallback.hpp"

#include "igame.hpp"

Practice::Practice(IGame* _game):
    PhysicalStage(_game, 100., b2Vec2(0.0, -7.8)),
    m_caughtBall(nullptr),
    m_basket(nullptr),
    m_mouseJoint(nullptr),
    m_pointListener(nullptr)
{
    createFrame(TOP | BOTTOM | LEFT | RIGHT);
    m_balls.push_back(new Ball(this, 3, 3, 0.25));
}

void Practice::draw(sf::RenderTarget *_target) const
{
    Stage::draw(_target);

    for(IBall* ball : m_balls)
        _target->draw(*ball);
}

void Practice::updateGraphics()
{
    Stage::updateGraphics();

    for(IBall* ball : qAsConst(m_balls))
        ball->updateGraphics();
}

void Practice::onMouseDown(const sf::Vector2i &_pos)
{
    b2Vec2 p = screen2World((double)_pos.x, (double)_pos.y);

    if(m_mouseJoint)
    {
        m_mouseJoint->SetTarget(p);
        return;
    }

    IBall* ball = ballUnderCursor(p);

    if (ball)
    {
        b2Body* body = ball->body();
        b2MouseJointDef md;
        md.bodyA = m_frame;
        md.bodyB = body;
        md.target = p;
        md.maxForce = 100000.0f * body->GetMass();
        md.collideConnected = true;
        m_mouseJoint = (b2MouseJoint*)m_world->CreateJoint(&md);
        body->SetAwake(true);

        m_caughtBall = ball;
        m_caughtBall->setThrown(false);
    }
}

void Practice::onMouseUp()
{
    if(m_mouseJoint)
    {
//        m_caughtBall->calculateThrowDistance(m_basket->baseX());
        m_caughtBall->setThrown(true);
        m_world->DestroyJoint(m_mouseJoint);
        m_mouseJoint = nullptr;
        m_caughtBall = nullptr;
    }
}

IBall *Practice::ballUnderCursor(const b2Vec2 &_pos) const
{
    b2AABB aabb;
    b2Vec2 d;
    d.Set(0.001f, 0.001f);
    aabb.lowerBound = _pos - d;
    aabb.upperBound = _pos + d;

    BallCallback callback(_pos);
    m_world->QueryAABB(&callback, aabb);

    return callback.ball();
}

void Practice::back()
{
    m_outputData.nextStage = 1;
//    m_wantExit = true;
}

bool Practice::calculate(double _dt, const QList<sf::Event> &_events)
{
    for(const auto& event : _events)
    {
        if(event.type == sf::Event::KeyReleased)
        {
            if(event.key.code == sf::Keyboard::Escape)
            {
                back();
                return false;
            }
        }
    }

//    const sf::Vector2f cpos = m_game mapPixelToCoords(cursorPos());

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        onMouseDown(m_game->cursorPos());
    else
        onMouseUp();

    return PhysicalStage::calculate(_dt, _events);
}
