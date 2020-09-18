#ifndef IBASKET_HPP
#define IBASKET_HPP

#include "common/gameobject.hpp"

class IBasket : virtual public GameObject
{
    public:
        virtual ~IBasket() = default;
        virtual double height() const = 0;
        virtual double baseX() const = 0;
};

#endif // IBASKET_HPP
