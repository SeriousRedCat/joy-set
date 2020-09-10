#include "growingmenuitemfactory.hpp"

GrowingMenuItemFactory::GrowingMenuItemFactory(const sf::Font& _font, unsigned int _x, unsigned int _y,
                                               unsigned int _interval):
    MenuItemFactory<GrowingMenuItem>(_font, _x, _y, _interval),
    m_type(QEasingCurve::Type::Linear),
    m_animationTime(0.),
    m_factor(1.)

{

}

IMenuItem *GrowingMenuItemFactory::createItem(const QString &_text, int _val, bool _enabled)
{
    auto item = createItemImpl(_text, _val, _enabled);
    item->setAnimationType(m_type);
    item->setAnimationTime(m_animationTime);
    item->setSizeFactor(m_factor);
    return item;
}

void GrowingMenuItemFactory::setEasingType(QEasingCurve::Type _type)
{
    m_type = _type;
}

void GrowingMenuItemFactory::setAnimationTime(double _time)
{
    m_animationTime = _time;
}

void GrowingMenuItemFactory::setFactor(double _factor)
{
    m_factor = _factor;
}
