#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <QMap>

#include "physicalobject.hpp"
#include "drawable.hpp"

class PhysicalStage;

class GameObject : public PhysicalObject, public Drawable
{
    public:
        GameObject(PhysicalStage* _stage);

        virtual void updateGraphics();

        template<typename DT>
        void assignSprite(b2Fixture* _fixture, DT* _sprite)
        {
            m_fixture2Transformable[_fixture] = _sprite;
            m_drawables.push_back(_sprite);
        }

    protected:
        QMap<b2Fixture*, sf::Transformable*> m_fixture2Transformable;
        PhysicalStage* m_stage;
};

#endif // GAMEOBJECT_HPP
