#ifndef BALL_HPP
#define BALL_HPP

#include "common/gameobject.hpp"
#include "iball.hpp"

class Ball : public IBall
{
    public:
        Ball(PhysicalStage* _stage, double _x, double _y, double _radius);
        ~Ball();

        b2Vec2 position() const;
        bool inBasket() const;
        double throwDistance() const;
        bool isThrown() const;
        b2Vec2 thrownPosition() const;

        b2Body *body() const;

        void setInBasket(bool _in);
        void setThrown(bool _thrown);

        void calculateThrowDistance(double _basket_pos);

    private:
        void resetThrowDistance();
        bool m_inBasket;
        bool m_isThrown;
        double m_throwDistance;

        b2Vec2 m_thrownPosition;
};

#endif // BALL_HPP
