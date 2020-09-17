#ifndef STAGE_HPP
#define STAGE_HPP

#include "istage.hpp"
#include "fpscounter.hpp"

class IGame;

class Stage : public IStage
{
    public:
        Stage(IGame* _game);
        virtual ~Stage() override = default;

        virtual const OutputData outputData() const override;

        virtual bool run(double _dt, const QList<sf::Event> &_events) override;

        virtual bool calculate(double _dt, const QList<sf::Event>& events) override;
        virtual void updateGraphics() override;
        virtual void draw(sf::RenderTarget* _target) const override;

        virtual void reset() override;

        virtual IGame * game() const override;

    protected:
        IGame* m_game;
        FPSCounter m_fpsCounter;
        OutputData m_outputData;
};

#endif // STAGE_HPP
