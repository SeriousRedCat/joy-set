#include "resourcemanager.hpp"

#include <QResource>

const QString FONT_PATH(":fonts/");
const QString TEXTURE_PATH(":graphics/");

ResourceManager::ResourceManager()
{

}

bool ResourceManager::registerFont(const QString& _name)
{
    if(m_fonts.contains(_name))
            return false;

    sf::Font sfFont;
    QResource rFont((FONT_PATH + _name));

    if(!sfFont.loadFromMemory(rFont.data(), static_cast<size_t>(rFont.size())))
        return false;

    m_fonts[_name] = std::move(sfFont);
    return true;
}

bool ResourceManager::registerTexture(const QString& _name)
{
    if(m_textures.contains(_name))
            return false;

    sf::Texture sfTexture;
    QResource rTexture((TEXTURE_PATH + _name));

    if(!sfTexture.loadFromMemory(rTexture.data(), static_cast<size_t>(rTexture.size())))
        return false;

    m_textures[_name] = std::move(sfTexture);
    return true;
}

const sf::Font& ResourceManager::font(const QString& _name) const
{
    return m_fonts.find(_name).value();
}

const sf::Texture& ResourceManager::texture(const QString& _name) const
{
    return m_textures.find(_name).value();
}
