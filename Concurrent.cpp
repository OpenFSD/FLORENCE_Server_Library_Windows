#include "Concurrent.h"
#include <cstddef>

namespace FLORENCE
{
    class Control_Of_Concurrent* Concurrent::ptr_Control_Of_Concurrent = NULL;
    class Praise0_Algorithm* Concurrent::ptr_Algorithms_Subset = NULL;//TODO CLASS T

    Concurrent::Concurrent()
    {
        ptr_Control_Of_Concurrent = NULL;

        ptr_Algorithms_Subset = new class FLORENCE::Praise0_Algorithm();//TODO CLASS T
        while (ptr_Algorithms_Subset == NULL) { /* wait untill class constructed */ }
    }

    Concurrent::~Concurrent()
    {
        delete ptr_Control_Of_Concurrent;
        delete ptr_Algorithms_Subset;
    }

    void Concurrent::Initialise_Control()
    {
        ptr_Control_Of_Concurrent = new class FLORENCE::Control_Of_Concurrent();
        while (ptr_Control_Of_Concurrent == NULL) { /* wait untill class constructed */ }
    }

    void Concurrent::Thread_Concurrency(unsigned char concurrent_coreId, unsigned char* ptr_MyNumImplementedCores)
    {
        FLORENCE::framework::Get_Server()->Get_Execute()->Get_Control_Of_Execute()->SetConditionCodeOfThisThreadedCore(concurrent_coreId);
        while (FLORENCE::framework::Get_Server()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised(ptr_MyNumImplementedCores) != false)
        {
            // wait untill thread initalised
        }
        if (FLORENCE::framework::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->GetFlag_ConcurrentCoreState(&concurrent_coreId) == FLORENCE::framework::Get_Server()->Get_Global()->GetConst_Core_ACTIVE())
        {
            if (FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->GetFlag_InputStackLoaded() == true)
            {
                FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Write_Start(
                    FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Get_Control_Of_WriteEnable(),
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    FLORENCE::framework::Get_Server()->Get_Global()
                );
                FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->PopFromStackOfInputPraises(
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId),
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_StackOfInputPraise()
                );
                if (sizeof(FLORENCE::framework::Get_Server()->Get_Data()->Get_StackOfInputPraise()) <= 1)
                {
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->SetFlag_InputStackLoaded(false);
                }
                else
                {
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->SetFlag_InputStackLoaded(true);
                }

                FLORENCE::framework::Get_Server()->Get_Algorithms()->Get_Concurren_Array(concurrent_coreId)->Get_Control_Of_Concurrent()->SelectSet_Algorithm_Subset_For_Given_PraiseEventId(
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    concurrent_coreId
                );

                FLORENCE::framework::Get_Server()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Get_Control_Of_Output()->SelectSet_Output_Subset_For_Given_PraiseEventId(
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    concurrent_coreId
                );

                 FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Write_End(
                    FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Get_Control_Of_WriteEnable(),
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    FLORENCE::framework::Get_Server()->Get_Global()
                );

                FLORENCE::framework::Get_Server()->Get_Algorithms()->Get_Concurren_Array(int(concurrent_coreId))->Do_Concurrent_Algorithm_For_PraiseEventId(
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    FLORENCE::framework::Get_Server()->Get_Algorithms()->Get_Concurren_Array(int(concurrent_coreId))->Get_Algorithm_Subset(),
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_InputRefferenceOfCore(int(concurrent_coreId))->Get_InputBufferSubset(),
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_OutputRefferenceOfCore(int(concurrent_coreId))->Get_OutputBuffer_Subset()
                );
                FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Write_Start(
                    FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Get_Control_Of_WriteEnable(),
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    FLORENCE::framework::Get_Server()->Get_Global()
                );
                FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->PushToStackOfOutput(
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_StackOfDistributeBuffer(),
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)
                );
                if (sizeof(FLORENCE::framework::Get_Server()->Get_Data()->Get_StackOfInputPraise()) < 1)
                {
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->SetFlag_InputStackLoaded(false);
                }
                else
                {
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->SetFlag_InputStackLoaded(true);
                }
                FLORENCE::framework::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Thread_End(
                    FLORENCE::framework::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency(),
                    &concurrent_coreId,
                    FLORENCE::framework::Get_Server()->Get_Global()
                );
                FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Write_End(
                    FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Get_Control_Of_WriteEnable(),
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    FLORENCE::framework::Get_Server()->Get_Global()
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
        return ptr_Algorithms_Subset;
    }

    class Control_Of_Concurrent* Concurrent::Get_Control_Of_Concurrent()
    {
        return ptr_Control_Of_Concurrent;
    }

    void Concurrent::Set_Algorithm_Subset(class FLORENCE::Praise0_Algorithm* value_algorithm)
    {
        ptr_Algorithms_Subset = value_algorithm;
    }
}