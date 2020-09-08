#ifndef REALBASKET_HPP
#define REALBASKET_HPP

#include "common/game.hpp"

class RealBasket : public Game
{
    public:
        RealBasket();
        virtual ~RealBasket() override = default;

        virtual bool init() override;
};

#endif // REALBASKET_HPP
