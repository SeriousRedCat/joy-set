#ifndef MENUITEMFACTORY_HPP
#define MENUITEMFACTORY_HPP

#include "imenuitemfactory.hpp"
#include "imenuitem.hpp"

#include <SFML/Graphics/Font.hpp>

template<class ITEM,
         typename = typename std::enable_if_t<std::is_base_of<IMenuItem, ITEM>::value>>
class MenuItemFactory : public IMenuItemFactory
{
    public:
        MenuItemFactory(const sf::Font& _font, unsigned int _x, unsigned int _y,
                        unsigned int _interval):
            m_x(_x),
            m_y(_y),
            m_interval(_interval),
            m_font(_font),
            m_baseTop(_y),
            m_currentTop(_y) {

        }
        virtual ~MenuItemFactory() override = default;

        virtual IMenuItem* createItem(const QString& _text, int _val, bool _enabled) override
        {
            return createItemImpl(_text, _val, _enabled);
        }

        virtual void release() override
        {
            m_currentTop = m_baseTop;
        }

    protected:
        ITEM* createItemImpl(const QString& _text, int _val, bool _enabled)
        {
            ITEM* item = new ITEM(_val, _enabled);
            item->init(_text, m_font);
            item->setPosition(m_x, m_currentTop);
            const sf::FloatRect textRect = item->getLocalBounds();
            item->setOrigin(textRect.left + textRect.width * 0.5f,
                            textRect.top + textRect.height * 0.5f);
            m_currentTop += (textRect.height + m_interval);
            return item;
        }

        const unsigned int m_x;
        const unsigned int m_y;
        const unsigned int m_interval;
        const sf::Font m_font;

        const unsigned int m_baseTop;

        unsigned int m_currentTop;

};
#endif // MENUITEMFACTORY_HPP
