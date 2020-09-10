#ifndef GROWINGMENUITEMFACTORY_HPP
#define GROWINGMENUITEMFACTORY_HPP

#include "common/menuitemfactory.hpp"
#include "common/growingmenuitem.hpp"

class GrowingMenuItemFactory : public MenuItemFactory<GrowingMenuItem>
{
    public:
        GrowingMenuItemFactory(const sf::Font& _font, unsigned int _x, unsigned int _y,
                               unsigned int _interval);

        virtual IMenuItem * createItem(const QString &_text, int _val, bool _enabled) override;

        void setEasingType(QEasingCurve::Type _type);

        void setAnimationTime(double _time);

        void setFactor(double _factor);

    protected:
        QEasingCurve::Type m_type;
        double m_animationTime;
        double m_factor;
};

#endif // GROWINGMENUITEMFACTORY_HPP
