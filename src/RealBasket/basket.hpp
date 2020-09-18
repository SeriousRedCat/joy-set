#ifndef BASKET_HPP
#define BASKET_HPP

#include "ibasket.hpp"

class Basket : public IBasket
{
    public:
        Basket(PhysicalStage* _stage, double _x, double _height, double _r);
        virtual ~Basket() {}

        double height() const;
        double baseX() const;

    protected:
        struct SBoundary
        {
                double Width, Height, Radius, X, Y;
        };

        double m_height;
        double m_baseX;
};

#endif // BASKET_HPP
