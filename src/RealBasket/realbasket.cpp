#include "realbasket.hpp"
#include "../common/menubasefactory.hpp"
#include "../common/menuitemfactory.hpp"
#include "../common/menuitem.hpp"

RealBasket::RealBasket()
{

}

bool RealBasket::init()
{
    m_resources.registerFont("ziperhea");
    m_resources.registerTexture("logo");

    MenuItemFactory<MenuItem>* itemF =
            new MenuItemFactory<MenuItem>(m_resources.font("ziperhea"), 400,
                                          250, 20);

    MenuBaseFactory* factory = new MenuBaseFactory(this, itemF);
    factory->addMenuPos("PLAY", 3, false);
    factory->addMenuPos("PRACTICE", 3, false);
    factory->addMenuPos("BEST RESULTS", 3, false);
    factory->addMenuPos("ACHIEVEMENTS", 3, false);
    factory->addMenuPos("OPTIONS", 3, false);
    factory->addMenuPos("EXIT", Game::EXIT, true);
    m_stages[Game::MENU] = factory;
    return true;
}
