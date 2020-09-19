#ifndef POINTSINFOTEXT_HPP
#define POINTSINFOTEXT_HPP

#include <SFML/Graphics/Text.hpp>
#include <QEasingCurve>

class PointsInfoText : public sf::Text
{
    public:
        PointsInfoText(const sf::Font &font, double _points, int _x, int _y_start, int _y_end, double _time, double _time_to_start);

        void init();

        void calculate(double _dt);

        bool isDone() const;

    protected:
        double m_currentTime;
        const int m_x;
        const double m_startY;
        const double m_endY;
        const double m_timeAll;
        const double m_timeStart;

        QEasingCurve m_curve;

        bool m_done;
};

#endif // POINTSINFOTEXT_HPP
