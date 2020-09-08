#ifndef ISTAGEFACTORY_HPP
#define ISTAGEFACTORY_HPP

class IStage;

#include <QVariantList>

class IStageFactory
{
    public:
        virtual ~IStageFactory() = default;

        virtual IStage* createStage() = 0;
        virtual bool releaseStage() = 0;

        virtual void setInputData(const QVariantList& _params) = 0;
};

#endif // ISTAGEFACTORY_HPP
