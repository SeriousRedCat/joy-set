#ifndef ISTAGE_HPP
#define ISTAGE_HPP

#include <QList>
#include <QVariantList>

#include <SFML/Window/Event.hpp>

namespace sf{
    class RenderTarget;
}

struct OutputData
{
    int nextStage;
    QVariantList params;

    void clear()
    {
        nextStage = -1;
        params.clear();
    }
};

class IStage
{
    public:
        virtual ~IStage() = default;

        virtual const OutputData outputData() const = 0;

        virtual bool run(double _dt, const QList<sf::Event>& _events) = 0;
        virtual bool calculate(double _dt, const QList<sf::Event>& events) = 0;
        virtual void updateGraphics() = 0;
        virtual void draw(sf::RenderTarget* _target) const = 0;

        virtual void reset() = 0;
};

#endif // ISTAGE_HPP
