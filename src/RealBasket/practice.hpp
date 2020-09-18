#ifndef PRACTICE_HPP
#define PRACTICE_HPP

#include <QObject>
#include <QVector>

#include "common/physicalstage.hpp"
#include "ipractice.hpp"

class IBall;
class IBasket;
class PointListener;

class Practice : public QObject, public IPractice, public PhysicalStage
{
        Q_OBJECT
    public:
        Practice(IGame* _game);

        void draw(sf::RenderTarget* _target) const override;
        virtual void updateGraphics() override;

        bool calculate(double _dt, const QList<sf::Event> &_events) override;

        virtual double basketHeight() const override;

    protected slots:
        void onPointsEarned(IBall* _ball);
    protected:
        QVector<IBall*> m_balls;
        IBall* m_caughtBall;
        IBasket* m_basket;
        b2MouseJoint* m_mouseJoint;
        PointListener* m_pointListener;
        void back();
        void onMouseDown(const sf::Vector2i &_pos);
        void onMouseUp();
        IBall *ballUnderCursor(const b2Vec2 &_pos) const;
};

#endif // PRACTICE_HPP
