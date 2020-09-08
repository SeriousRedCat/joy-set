#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include "imenuitem.hpp"
#include <QString>

class MenuItem : public IMenuItem
{
    public:
        MenuItem(int _value, bool _enabled);
        virtual ~MenuItem() override = default;

        virtual int value() const override final;
        virtual bool isActive() const override final;
        virtual bool isEnabled() const override final;

        virtual void calculate(int _x, int _y, double _dt) override;

        virtual void activate(bool _active) override;

    protected:
        const int m_value;
        const bool m_isEnabled;
        bool m_isActive;
};

#endif // MENUITEM_HPP
