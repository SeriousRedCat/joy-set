#include "menubase.hpp"
#include "menuitem.hpp"
#include "imenuitemfactory.hpp"
#include "igame.hpp"

#include "../common/resourcemanager.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

MenuBase::MenuBase(IGame* _game):
    Stage(_game),
    m_factory(nullptr)
{
    m_logo.setTexture(m_game->resources()->texture("logo"));
    m_logo.setPosition((m_game->renderWindow()->getSize().x -
                        m_logo.getGlobalBounds().width) / 2,
                       50);
}

void MenuBase::setMenuItemFactory(IMenuItemFactory* _factory)
{
    m_factory = _factory;
}

bool MenuBase::calculate(double _dt, const QList<sf::Event>& _events)
{
    Stage::calculate(_dt, _events);

    const sf::Vector2i pos = m_game->cursorPos();

    IMenuItem* currentItem = nullptr;

    for(IMenuItem* const item : qAsConst(m_items))
    {
        if(!item->isEnabled())
            continue;

        item->calculate(pos.x, pos.y, _dt);

        if(item->isActive())
            currentItem = item;
    }

    if(currentItem)
    {
        for(const sf::Event& ev : _events)
        {
            if(sf::Event::MouseButtonReleased == ev.type &&
                    sf::Mouse::Left == ev.mouseButton.button)
            {
                m_outputData.nextStage = currentItem->value();
                return false;
            }
        }
    }
    return true;
}

void MenuBase::updateGraphics()
{
    Stage::updateGraphics();

    for(IMenuItem* item : m_items)
    {
        if(item->isEnabled())
            item->activate(item->isActive());
    }
}

void MenuBase::draw(sf::RenderTarget* _target) const
{
    Stage::draw(_target);
    _target->draw(m_logo);

    for(const IMenuItem* const item : m_items)
    {
        _target->draw(*item);
    }
}

void MenuBase::addMenuItem(const QString& _text, int _val, bool _enabled)
{
    IMenuItem* item = m_factory->createItem(_text, _val, _enabled);
    m_items.append(item);
}
