#include <memory>

#include "realbasket.hpp"

int main()
{
    std::unique_ptr<RealBasket> realBasket = std::make_unique<RealBasket>();
    realBasket->init();
    realBasket->run();
    return 0;
}
