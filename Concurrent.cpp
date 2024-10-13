#include "Concurrent.h"

namespace FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace
{
    class Control_Of_Concurrent* ptr_Control_Of_Concurrent = NULL;
    class Praise0_Algorithm* ptr_Algorithms_Subset = NULL;//TODO CLASS T

    Concurrent::Concurrent()
    {
        this->ptr_Algorithms_Subset = new class Praise0_Algorithm();//TODO CLASS T
        while (this->ptr_Algorithms_Subset == NULL) { /* wait untill class constructed */ }
    }

    Concurrent::~Concurrent()
    {
        delete ptr_Control_Of_Concurrent;
        delete ptr_Algorithms_Subset;
    }

    void Concurrent::initialise_Control()
    {
        this->ptr_Control_Of_Concurrent = new Concurrent::Control_Of_Concurrent();
        while (this->ptr_Control_Of_Concurrent == NULL) { /* wait untill class constructed */ }
    }

    void Concurrent::thread_Concurrency(
        unsigned char concurrent_coreId,
        unsigned char* ptr_MyNumImplementedCores,
        FLORENCE::Framework::Server::Algorithms::Concurrent* ptr_Concurrent,
        Control_Of_Concurrent* prt_Control_Of_Concurrent,
        FLORENCE::Framework::Server::Data::Control_Of_Data* ptr_Control_Of_Data,
        FLORENCE::Framework::Server::Execute::Control_Of_Execute* ptr_Control_Of_Execute,
        FLORENCE::Framework::Server::Execute::LaunchConcurrency::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
        FLORENCE::Framework::Server::Data::Output::Control_Of_Output* ptr_Control_Of_Output,
        FLORENCE::Framework::Server::Execute::WriteEnable::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
        FLORENCE::Framework::Server::Data* ptr_Data,
        FLORENCE::Framework::Server::Global* ptr_Global,
        FLORENCE::Framework::Server::Data::Input* ptr_InputBuffer,
        std::vector<FLORENCE::Framework::Server::Data::Input*>* ptr_InputStack,
        FLORENCE::Framework::Server::Execute::LaunchConcurrency* ptr_LaunchConcurrency,
        FLORENCE::Framework::Server::Data::Output* ptr_Output,
        std::vector<FLORENCE::Framework::Server::Data::Output*>* ptr_OutputStack,
        FLORENCE::Framework::Server::Algorithms::Praise0_Algorithm* ptr_Algorithm_Subset,//TODO CLASS T
        FLORENCE::Framework::Server::Data::Praise0_Input* ptr_Input_Subset,//TODO CLASS T
        FLORENCE::Framework::Server::Data::Praise0_Output* ptr_Output_Subset,//TODO CLASS T
        FLORENCE::Framework::Server::Execute::WriteEnable* ptr_WriteEnable
    )
    {
        ptr_Control_Of_Execute->setConditionCodeOfThisThreadedCore(concurrent_coreId);
        while (ptr_Control_Of_Execute->getFlag_SystemInitialised(ptr_MyNumImplementedCores) != false)
        {
            // wait untill thread initalised
        }
        if (ptr_Control_Of_LaunchConcurrency->getFlag_ConcurrentCoreState(&concurrent_coreId) == ptr_Global->getConst_Core_ACTIVE())
        {
            if (ptr_Control_Of_Data->getFlag_InputStackLoaded() == true)
            {
                ptr_WriteEnable->write_Start(
                    ptr_Control_Of_WriteEnable,
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    ptr_Global
                );
                ptr_Control_Of_Data->popFromStackOfInputPraises(
                    ptr_Data->get_InputRefferenceOfCore(concurrent_coreId),
                    ptr_InputStack
                );
                if (sizeof(ptr_Data->get_StackOfInputPraise()) <= 1)
                {
                    ptr_Control_Of_Data->setFlag_InputStackLoaded(false);
                }
                else
                {
                    ptr_Control_Of_Data->setFlag_InputStackLoaded(true);
                }

                prt_Control_Of_Concurrent->selectSet_Algorithm_Subset_For_Given_PraiseEventId(
                    ptr_Data->get_InputRefferenceOfCore(concurrent_coreId)->getPraiseEventId(),
                    concurrent_coreId
                );

                ptr_Control_Of_Output->selectSet_Output_Subset_For_Given_PraiseEventId(
                    ptr_Data->get_OutputRefferenceOfCore(concurrent_coreId)->getPraiseEventId(),
                    concurrent_coreId
                );

                ptr_WriteEnable->write_End(
                    ptr_Control_Of_WriteEnable,
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    ptr_Global
                );

                ptr_Concurrent->do_Concurrent_Algorithm_For_PraiseEventId(
                    ptr_Data->get_InputRefferenceOfCore(concurrent_coreId)->getPraiseEventId(),
                    ptr_Algorithm_Subset,
                    ptr_Input_Subset,
                    ptr_Output_Subset
                );
                ptr_WriteEnable->write_Start(
                    ptr_Control_Of_WriteEnable,
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    ptr_Global
                );
                ptr_Control_Of_Data->pushToStackOfOutput(
                    ptr_OutputStack,
                    ptr_Data->get_OutputRefferenceOfCore(concurrent_coreId)
                );
                if (sizeof(ptr_Data->get_StackOfInputPraise()) < 1)
                {
                    ptr_Control_Of_Data->setFlag_InputStackLoaded(false);
                }
                else
                {
                    ptr_Control_Of_Data->setFlag_InputStackLoaded(true);
                }
                ptr_LaunchConcurrency->thread_End(
                    ptr_Control_Of_LaunchConcurrency,
                    &concurrent_coreId,
                    ptr_Global
                );
                ptr_WriteEnable->write_End(
                    ptr_Control_Of_WriteEnable,
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    ptr_Global
                );
            }
        }
    }

    void  Concurrent::do_Concurrent_Algorithm_For_PraiseEventId(
        int* ptr_praiseEventId,
        class FLORENCE::Framework::Server::Algorithms::Praise0_Algorithm* ptr_Algorithm_Subset,
        class FLORENCE::Framework::Server::Data::Praise0_Input* ptr_Input_Subset,
        class FLORENCE::Framework::Server::Data::Praise0_Output* ptr_Output_Subset
    )
    {
        ptr_Algorithm_Subset->do_Praise(
            ptr_Input_Subset,
            ptr_Output_Subset
        );
    }
    class Praise0_Algorithm* Concurrent::get_Algorithm_Subset()
    {
        return this->ptr_Algorithms_Subset;
    }

    class Control_Of_Concurrent* Concurrent::get_Control_Of_Concurrent()
    {
        return this->ptr_Control_Of_Concurrent;
    }

    void Concurrent::set_Algorithm_Subset(Praise0_Algorithm* value_algorithm)
    {
        this->ptr_Algorithms_Subset = value_algorithm;
    }
}