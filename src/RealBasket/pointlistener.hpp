#ifndef POINTLISTENER_HPP
#define POINTLISTENER_HPP

#include "Box2D/Box2D.h"

#include <QObject>

class IPractice;
class IBall;

class PointListener : public QObject, public b2ContactListener
{
        Q_OBJECT
    public:
        PointListener(IPractice* _stage);
        virtual ~PointListener() = default;

        virtual void BeginContact(b2Contact *contact) override;
        virtual void EndContact(b2Contact *contact) override;

    signals:
        void pointsEarned(IBall* ball);

    private:
        IPractice* m_stage;
        double m_basketHeight;
};

#endif // POINTLISTENER_HPP
