#ifndef PHYSICALSTAGE_HPP
#define PHYSICALSTAGE_HPP

#include <Box2D/Box2D.h>

#include "stage.hpp"

class PhysicalStage : public Stage
{
    public:
        enum Frame
        {
            TOP = 1,
            RIGHT = 2,
            BOTTOM = 4,
            LEFT = 8
        };

        PhysicalStage(IGame* _game, double _pixPerMeter, const b2Vec2& _gravity);
        virtual ~PhysicalStage() override;

        b2World* world() const;

        virtual bool calculate(double _dt, const QList<sf::Event> &_events) override;

        sf::Vector2f world2Screen(double _x, double _y) const;
        b2Vec2 screen2World(double _x, double _y) const;

        double pixelsPerMeter() const;

    protected:
        virtual void createFrame(int _frame);

        b2World* m_world;
        const double m_pixPerMeter;
        const b2Vec2 m_worldSize;

        b2Body* m_frame;
};

#endif // PHYSICALSTAGE_HPP
