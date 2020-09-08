#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <QMap>
#include <QString>

#include "SFML/Graphics/Font.hpp"

class ResourceManager
{
    public:
        ResourceManager();

        bool registerFont(const QString& _name);
        bool registerTexture(const QString& _name);

        const sf::Font& font(const QString& _name) const;
        const sf::Texture& texture(const QString& _name) const;

    private:
        QMap<QString, sf::Font> m_fonts;
        QMap<QString, sf::Texture> m_textures;
};

#endif // RESOURCEMANAGER_HPP
