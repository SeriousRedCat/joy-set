#ifndef MENUBASE_HPP
#define MENUBASE_HPP

#include "stage.hpp"

#include <QVector>
#include <SFML/Graphics/Sprite.hpp>

class IMenuItem;
class IMenuItemFactory;

class MenuBase : public Stage
{
    public:
        MenuBase(IGame* _game);

        void setMenuItemFactory(IMenuItemFactory* _factory);

        virtual void addMenuItem(const QString& _text, int _val, bool _enabled);

    protected:
        virtual bool calculate(double _dt, const QList<sf::Event> &_events) override;
        virtual void updateGraphics() override;
        virtual void draw(sf::RenderTarget* _target) const override;

        QVector<IMenuItem*> m_items;
        IMenuItemFactory* m_factory;

        sf::Sprite m_logo;
};

#endif // MENUBASE_HPP
