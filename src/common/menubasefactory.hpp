#ifndef MENUBASEFACTORY_HPP
#define MENUBASEFACTORY_HPP

#include "stagefactory.hpp"
#include "menubase.hpp"

class IStage;

struct SMenuItem
{
        SMenuItem(): text(), value(0), enabled(false) {

        }

        SMenuItem(const QString& _txt, int _val, bool _enabled):
            text(_txt), value(_val), enabled(_enabled) {

        }

        const QString text;
        const int value;
        const bool enabled;
};

class MenuBaseFactory : public StageFactory<MenuBase>
{
    public:
        MenuBaseFactory(IGame* _game, IMenuItemFactory* _factory);
        virtual ~MenuBaseFactory() override = default;

        virtual IStage* createStage() override;

        void addMenuPos(const QString& _text, int _value, bool _enabled);

    protected:
        IMenuItemFactory* m_factory;
        QVector<SMenuItem> m_menuItems;
};

#endif // MENUBASEFACTORY_HPP
