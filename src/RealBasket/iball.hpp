#ifndef IBALL_HPP
#define IBALL_HPP

#include <Box2D/Common/b2Math.h>
#include "common/gameobject.hpp"

class IBall : virtual public GameObject
{
    public:
        virtual ~IBall() = default;

        virtual bool isThrown() const = 0;
        virtual bool inBasket() const = 0;
        virtual double throwDistance() const = 0;
        virtual b2Vec2 position() const = 0;
        virtual b2Vec2 thrownPosition() const = 0;

        virtual void setInBasket(bool _inBasket) = 0;
        virtual void setThrown(bool _thrown) = 0;

        virtual b2Body* body() const = 0;

        virtual void calculateThrowDistance(double _basket_pos) = 0;
};

#endif // IBALL_HPP
