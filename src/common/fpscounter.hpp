#ifndef FPSCOUNTER_HPP
#define FPSCOUNTER_HPP

#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>

class FPSCounter : public sf::Text
{
    public:
        FPSCounter();

        void update(double _dt);

    private:
        void updateText(unsigned int fps);

        double m_elapsedTime;
        unsigned int m_fps;
};

#endif // FPSCOUNTER_HPP
