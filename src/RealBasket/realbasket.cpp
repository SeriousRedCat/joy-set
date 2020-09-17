#include "realbasket.hpp"
#include "../common/menubasefactory.hpp"
#include "../common/growingmenuitemfactory.hpp"
#include "../common/menuitem.hpp"

#include "practice.hpp"

enum RealBasketStage{
    PRACTICE = Game::StageType::USER_STAGE + 1
};

RealBasket::RealBasket()
{

}

bool RealBasket::init()
{
    m_resources.registerFont("ziperhea");
    m_resources.registerFont("calibril");
    m_resources.registerTexture("logo");
    m_resources.registerTexture("ball");

    GrowingMenuItemFactory* itemF =
            new GrowingMenuItemFactory(m_resources.font("ziperhea"), 400,
                                          250, 20);
    itemF->setEasingType(QEasingCurve::Type::OutBounce);
    itemF->setAnimationTime(0.5);
    itemF->setFactor(2.);

    MenuBaseFactory* factory = new MenuBaseFactory(this, itemF);
    factory->addMenuPos("PLAY", 3, false);
    factory->addMenuPos("PRACTICE", PRACTICE, true);
    factory->addMenuPos("BEST RESULTS", 3, false);
    factory->addMenuPos("ACHIEVEMENTS", 3, false);
    factory->addMenuPos("OPTIONS", 3, false);
    factory->addMenuPos("EXIT", Game::EXIT, true);
    m_stages[Game::MENU] = factory;
    m_stages[PRACTICE] = new StageFactory<Practice>(this, false);
    return true;
}
