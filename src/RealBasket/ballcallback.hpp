#ifndef BALLCALLBACK_HPP
#define BALLCALLBACK_HPP


#include "Box2D/Box2D.h"

class IBall;

class BallCallback : public b2QueryCallback
{
    public:
        BallCallback(const b2Vec2& _point);
        virtual ~BallCallback() {}

        virtual bool ReportFixture(b2Fixture *fixture) override;

        IBall* ball() const;

    protected:
        b2Vec2 m_point;
        b2Fixture* m_fixture;
        IBall* m_ball;
};
#endif // BALLCALLBACK_HPP
