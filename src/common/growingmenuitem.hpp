#ifndef GROWINGMENUITEM_HPP
#define GROWINGMENUITEM_HPP

#include "common/menuitem.hpp"

#include <QEasingCurve>

class GrowingMenuItem : public MenuItem
{
    public:
        GrowingMenuItem(int _value, bool _enabled);
        virtual ~GrowingMenuItem() override = default;

        virtual void init(const QString &_text, const sf::Font &_font) override;

        void setAnimationType(QEasingCurve::Type _type);
        void setAnimationTime(double _animTime);
        void setSizeFactor(double _sizeFactor);

        virtual void calculate(int _x, int _y, double _dt) override;

    protected:
        QEasingCurve m_curve;
        double m_animationTime;
        double m_sizeFactor;
        unsigned int m_baseSize;

        double m_currentTime;
        bool m_inProgress;
};

#endif // GROWINGMENUITEM_HPP
