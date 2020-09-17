#include "menubasefactory.hpp"
#include "imenuitemfactory.hpp"

MenuBaseFactory::MenuBaseFactory(IGame* _game,
                                 IMenuItemFactory* _factory):
    StageFactory<MenuBase>(_game, false),
    m_factory(_factory)
{

}

IStage* MenuBaseFactory::createStage()
{
    MenuBase* menu = StageFactory<MenuBase>::createStagePriv();

    if(!m_initialized)
    {
        menu->setMenuItemFactory(m_factory);

        for(const SMenuItem& item : qAsConst(m_menuItems))
        {
            menu->addMenuItem(item.text, item.value, item.enabled);
        }
        m_initialized = true;
    }

    return menu;
}

bool MenuBaseFactory::releaseStage()
{
    StageFactory<MenuBase>::releaseStage();
    m_factory->release();
    return true;
}

void MenuBaseFactory::addMenuPos(const QString& _text, int _value, bool _enabled)
{
    m_menuItems.append(SMenuItem(_text, _value, _enabled));
}
