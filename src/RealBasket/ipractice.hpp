#ifndef IPRACTICE_HPP
#define IPRACTICE_HPP

enum class EnFixtureType
{
    COMMON = 0x0001,
    BALL = 0x0002,
    POINT_SENSOR = 0x0004
};

class IPractice
{
    public:
        virtual ~IPractice() = default;

        virtual double basketHeight() const = 0;
};

#endif // IPRACTICE_H
