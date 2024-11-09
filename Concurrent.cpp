#include "pch.h"
#include "Concurrent.h"

namespace FLORENCE
{
    class Control_Of_Concurrent* ptr_Control_Of_Concurrent = NULL;
    class Praise0_Algorithm* ptr_Algorithms_Subset = NULL;//TODO CLASS T

    Concurrent::Concurrent()
    {
        this->ptr_Algorithms_Subset = new Praise0_Algorithm();//TODO CLASS T
        while (this->ptr_Algorithms_Subset == NULL) { /* wait untill class constructed */ }
    }

    Concurrent::~Concurrent()
    {
        delete this->ptr_Control_Of_Concurrent;
        delete this->ptr_Algorithms_Subset;
    }

    void Concurrent::Initialise_Control()
    {
        this->ptr_Control_Of_Concurrent = new Control_Of_Concurrent();
        while (this->ptr_Control_Of_Concurrent == NULL) { /* wait untill class constructed */ }
    }

    void Concurrent::Thread_Concurrency(
        unsigned char concurrent_coreId,
        unsigned char* ptr_MyNumImplementedCores,
        FLORENCE::Control_Of_Concurrent* prt_Control_Of_Concurrent,
        FLORENCE::Control_Of_Data* ptr_Control_Of_Data,
        FLORENCE::Control_Of_Execute* ptr_Control_Of_Execute,
        FLORENCE::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
        FLORENCE::Control_Of_Output* ptr_Control_Of_Output,
        FLORENCE::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
        FLORENCE::Data* ptr_Data,
        FLORENCE::Global* ptr_Global,
        FLORENCE::Input* ptr_InputBuffer,
        std::vector<class FLORENCE::Input*>* ptr_InputStack,
        FLORENCE::LaunchConcurrency* ptr_LaunchConcurrency,
        FLORENCE::Output* ptr_Output,
        std::vector<class Output*>* ptr_OutputStack,
        Praise0_Algorithm* ptr_Algorithm_Subset,
        FLORENCE::Praise0_Input* ptr_Input_Subset,
        FLORENCE::Praise0_Output* ptr_Output_Subset,
        FLORENCE::WriteEnable* ptr_WriteEnable
    )
    {
        ptr_Control_Of_Execute->SetConditionCodeOfThisThreadedCore(concurrent_coreId);
        while (ptr_Control_Of_Execute->GetFlag_SystemInitialised(ptr_MyNumImplementedCores) != false)
        {
            // wait untill thread initalised
        }
        if (ptr_Control_Of_LaunchConcurrency->GetFlag_ConcurrentCoreState(&concurrent_coreId) == ptr_Global->GetConst_Core_ACTIVE())
        {
            if (ptr_Control_Of_Data->GetFlag_InputStackLoaded() == true)
            {
                ptr_WriteEnable->Write_Start(
                    ptr_Control_Of_WriteEnable,
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    ptr_Global
                );
                ptr_Control_Of_Data->PopFromStackOfInputPraises(
                    ptr_Data->Get_InputRefferenceOfCore(concurrent_coreId),
                    ptr_InputStack
                );
                if (sizeof(ptr_Data->Get_StackOfInputPraise()) <= 1)
                {
                    ptr_Control_Of_Data->SetFlag_InputStackLoaded(false);
                }
                else
                {
                    ptr_Control_Of_Data->SetFlag_InputStackLoaded(true);
                }

                prt_Control_Of_Concurrent->SelectSet_Algorithm_Subset_For_Given_PraiseEventId(
                    ptr_Data->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    concurrent_coreId
                );

                ptr_Control_Of_Output->SelectSet_Output_Subset_For_Given_PraiseEventId(
                    ptr_Data->Get_OutputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    concurrent_coreId
                );

                ptr_WriteEnable->Write_End(
                    ptr_Control_Of_WriteEnable,
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    ptr_Global
                );

                ptr_Concurrent->Do_Concurrent_Algorithm_For_PraiseEventId(
                    ptr_Data->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    ptr_Algorithm_Subset,
                    ptr_Input_Subset,
                    ptr_Output_Subset
                );
                ptr_WriteEnable->Write_Start(
                    ptr_Control_Of_WriteEnable,
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    ptr_Global
                );
                ptr_Control_Of_Data->PushToStackOfOutput(
                    ptr_OutputStack,
                    ptr_Data->Get_OutputRefferenceOfCore(concurrent_coreId)
                );
                if (sizeof(ptr_Data->Get_StackOfInputPraise()) < 1)
                {
                    ptr_Control_Of_Data->SetFlag_InputStackLoaded(false);
                }
                else
                {
                    ptr_Control_Of_Data->SetFlag_InputStackLoaded(true);
                }
                ptr_LaunchConcurrency->Thread_End(
                    ptr_Control_Of_LaunchConcurrency,
                    &concurrent_coreId,
                    ptr_Global
                );
                ptr_WriteEnable->Write_End(
                    ptr_Control_Of_WriteEnable,
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    ptr_Global
                );
            }
        }
    }

    void  Concurrent::Do_Concurrent_Algorithm_For_PraiseEventId(
        int* ptr_praiseEventId,
        class FLORENCE::Praise0_Algorithm* ptr_Algorithm_Subset,
        class FLORENCE::Praise0_Input* ptr_Input_Subset,
        class FLORENCE::Praise0_Output* ptr_Output_Subset
    )
    {
        ptr_Algorithm_Subset->Do_Praise(
            ptr_Input_Subset,
            ptr_Output_Subset
        );
    }
    class Praise0_Algorithm* Concurrent::Get_Algorithm_Subset()
    {
        return this->ptr_Algorithms_Subset;
    }

    class Control_Of_Concurrent* Concurrent::Get_Control_Of_Concurrent()
    {
        return this->ptr_Control_Of_Concurrent;
    }

    void Concurrent::Set_Algorithm_Subset(Praise0_Algorithm* value_algorithm)
    {
        this->ptr_Algorithms_Subset = value_algorithm;
    }
}