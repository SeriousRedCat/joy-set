#ifndef MENUITEMFACTORY_HPP
#define MENUITEMFACTORY_HPP

#include "imenuitemfactory.hpp"
#include "imenuitem.hpp"

#include <SFML/Graphics/Font.hpp>

template<class ITEM, typename = typename std::enable_if_t<std::is_base_of<IMenuItem, ITEM>::value>>
class MenuItemFactory : public IMenuItemFactory
{
    public:
        MenuItemFactory(const sf::Font& _font, unsigned int _x, unsigned int _y,
                        unsigned int _interval):
            m_x(_x),
            m_y(_y),
            m_interval(_interval),
            m_font(_font),
            m_currentTop(_y) {

        }
        virtual ~MenuItemFactory() override = default;



        virtual IMenuItem* createItem(const QString& _text, int _val, bool _enabled) override
        {
            return createItemImpl(_text, _val, _enabled);
        }

        ITEM* createItemImpl(const QString& _text, int _val, bool _enabled)
        {
            ITEM* item = new ITEM(_val, _enabled);
            item->setStyle(sf::Text::Bold);
            item->setOutlineThickness(1);
            item->setCharacterSize(30);
            item->setFont(m_font);
            item->setString(_text.toStdString());
            item->setFillColor(sf::Color(_enabled ? 0xFF0000FF : 0x646464FF));
            item->setOutlineColor(sf::Color::Green);

            sf::FloatRect textRect = item->getLocalBounds();
            item->setOrigin(textRect.left + textRect.width * 0.5f,
                            textRect.top + textRect.height * 0.5f);

            item->setPosition(m_x, m_currentTop);
            m_currentTop += (textRect.height + m_interval);
            return item;
        }

    protected:
        const unsigned int m_x;
        const unsigned int m_y;
        const unsigned int m_interval;
        const sf::Font m_font;

        unsigned int m_currentTop;

};
#endif // MENUITEMFACTORY_HPP
