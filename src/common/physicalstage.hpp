#ifndef PHYSICALSTAGE_HPP
#define PHYSICALSTAGE_HPP

#include <Box2D/Box2D.h>

#include "stage.hpp"

class PhysicalStage : public Stage
{
    public:
        PhysicalStage(IGame* _game, double _pixPerMeter, const b2Vec2& _gravity);
        virtual ~PhysicalStage() override;

        virtual bool calculate(double _dt, const QList<sf::Event> &_events) override;

    protected:
        b2World* m_world;
        const double m_pixPerMeter;
        const b2Vec2 m_worldSize;
};

#endif // PHYSICALSTAGE_HPP
