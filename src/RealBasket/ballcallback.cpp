#include "ballcallback.hpp"

BallCallback::BallCallback(const b2Vec2 &_point):
    m_point(_point), m_ball(nullptr)
{

}

bool BallCallback::ReportFixture(b2Fixture *fixture)
{
    void* tmp = fixture->GetUserData();

    if(!tmp)
        return true;

//    GameObject<Practice>* obj = static_cast<GameObject<Practice>*>(tmp);
//    Ball* ball = dynamic_cast<Ball*>(obj);

    if(fixture->TestPoint(m_point) && fixture->GetFilterData().categoryBits == 0x0002)
    {
        m_fixture = fixture;
        m_ball = static_cast<IBall*>(tmp);
        return false;
    }
    return true;
}

IBall *BallCallback::ball() const
{
    return m_ball;
}
