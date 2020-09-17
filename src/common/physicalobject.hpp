#ifndef PHYSICALOBJECT_HPP
#define PHYSICALOBJECT_HPP

#include <QVector>

#include "Box2D/Box2D.h"

class PhysicalObject
{
    public:
        PhysicalObject(b2World* _world);

        virtual b2Body* addPart(const b2BodyDef& _bdef, const b2FixtureDef& _fdef);

    protected:
        b2World* m_world;
        QVector<b2Body*> m_bodies;
};

#endif // PHYSICALOBJECT_HPP
