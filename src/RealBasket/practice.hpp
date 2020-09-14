#ifndef PRACTICE_HPP
#define PRACTICE_HPP

#include "common/physicalstage.hpp"

class IBall;
class IBasket;
class PointListener;

class Practice : public PhysicalStage
{
    public:
        Practice(IGame* _game);

    protected:
        QVector<IBall*> m_balls;
        IBall* m_caughtBall;
        IBasket* m_basket;
        b2MouseJoint* m_mouseJoint;
        PointListener* m_pointListener;
};

#endif // PRACTICE_HPP
