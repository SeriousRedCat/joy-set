#ifndef STAGEFACTORY_HPP
#define STAGEFACTORY_HPP

#include "istagefactory.hpp"

class IGame;

template<class STAGE>
class StageFactory : public IStageFactory
{
    public:
        StageFactory(IGame* _game, bool _keepStage):
            m_keepStage(_keepStage),
            m_initialized(false),
            m_game(_game),
            m_stage(nullptr)
            {}

        virtual ~StageFactory() override
        {
            if(m_stage)
                delete m_stage;
        }

        virtual IStage* createStage() override
        {
            if(m_stage && !m_keepStage)
            {
                delete m_stage;
                m_stage = nullptr;
            }

            if(!m_stage)
            {
                m_stage = new STAGE(m_game);
            }
            else
                m_stage->reset();
            return m_stage;
        }

        virtual bool releaseStage() override
        {
            if(!m_keepStage)
            {
                delete m_stage;
                m_stage = nullptr;
                return true;
            }
            return false;
        }

        virtual void setInputData(const QVariantList& _params) override
        {
            Q_UNUSED(_params)
        }

    protected:        
        template<typename T = STAGE,
                 typename = std::enable_if_t<std::is_base_of<IStage, T>::value>>
        STAGE* createStagePriv()
        {
            return static_cast<T*>(StageFactory<T>::createStage());
        }

        const bool m_keepStage;
        bool m_initialized;

        IGame* m_game;
        IStage* m_stage;
};

#endif // STAGEFACTORY_HPP
