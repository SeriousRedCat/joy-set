#include "practice.hpp"
#include "pointlistener.hpp"
#include "ball.hpp"
#include "basket.hpp"
#include "ballcallback.hpp"
#include "pointsinfotext.hpp"
#include "igame.hpp"
#include "common/resourcemanager.hpp"

#include <QDebug>
Practice::Practice(IGame* _game):
    PhysicalStage(_game, 100., b2Vec2(0.0, -7.8)),
    m_caughtBall(nullptr),
    m_basket(nullptr),
    m_mouseJoint(nullptr),
    m_pointListener(nullptr)
{
    createFrame(TOP | BOTTOM | LEFT | RIGHT);
    m_balls.push_back(new Ball(this, 3, 3, 0.25));
    m_basket = new Basket(this, 7.7, 3, 0.55);

    m_pointListener = new PointListener(this);
    m_world->SetContactListener(m_pointListener);

    connect(m_pointListener, &PointListener::pointsEarned, this, &Practice::onPointsEarned);
}

void Practice::draw(sf::RenderTarget *_target) const
{
    Stage::draw(_target);

    for(IBall* ball : m_balls)
        _target->draw(*ball);

    _target->draw(*m_basket);

    for(auto& info : m_infos)
    {
        _target->draw(*info);
    }
}

void Practice::updateGraphics()
{
    Stage::updateGraphics();

    for(IBall* ball : qAsConst(m_balls))
        ball->updateGraphics();

    m_basket->updateGraphics();

    for (auto it=m_infos.begin(); it!=m_infos.end();)
    {

       if((*it)->isDone())
       {
           delete *it;
           m_infos.erase(it);
#ifdef _MSC_VER
           break;
#endif
       }
       else
          ++it;
     }
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
        m_caughtBall->calculateThrowDistance(m_basket->baseX());
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
    m_outputData.nextStage = IGame::StageType::MENU;
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

    for(auto& info : m_infos)
    {
        info->calculate(_dt);
    }

    return PhysicalStage::calculate(_dt, _events);
}

double Practice::basketHeight() const
{
    return m_basket->height();
}

void Practice::onPointsEarned(IBall *_ball)
{
    qDebug() << "Points:" << _ball->throwDistance();

    sf::Vector2f pos = world2Screen(_ball->thrownPosition().x, _ball->thrownPosition().y);
    auto pi = new PointsInfoText(m_game->resources()->font("ziperhea"), _ball->throwDistance(), pos.x, pos.y, pos.y - 100, 10, 0);
    pi->init();
    m_infos.push_back(pi);

}
