#ifndef IMENUITEMFACTORY_HPP
#define IMENUITEMFACTORY_HPP

#include <QString>

class IMenuItem;

class IMenuItemFactory
{
    public:
        virtual ~IMenuItemFactory() = default;

        virtual IMenuItem* createItem(const QString& _text, int _val, bool _enabled) = 0;
        virtual void release() = 0;
};

#endif // IMENUITEMFACTORY_HPP
