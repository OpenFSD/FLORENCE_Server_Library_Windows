#include "ListenRespond.h"
#include <cstddef>

namespace FLORENCE
{
    class Control_Of_ListenRespond* ListenRespond::ptr_Control_Of_ListenRespond = NULL;

    ListenRespond::ListenRespond()
    {
        ptr_Control_Of_ListenRespond = NULL;
    }

    ListenRespond::~ListenRespond()
    {
        delete ptr_Control_Of_ListenRespond;
    }

    void ListenRespond::Initialise_Control()
    {
        ptr_Control_Of_ListenRespond = new class Control_Of_ListenRespond();
        while (ptr_Control_Of_ListenRespond == NULL) { /* wait untill class constructed */ }
    }

    void ListenRespond::Thread_IO_ListenDistribute(
        unsigned char coreId,
        unsigned char* ptr_MyNumImplementedCores
    )
    {
        FLORENCE::framework::Get_Server()->Get_Execute()->Get_Control_Of_Execute()->SetConditionCodeOfThisThreadedCore(coreId);
        while (FLORENCE::framework::Get_Server()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised(ptr_MyNumImplementedCores) != false)
        {
            // wait untill ALL threads initalised in preperation of system init.
        }
        switch (FLORENCE::framework::Get_Server()->Get_Algorithms()->Get_ListenRespond()->Get_Control_Of_ListenRespond()->GetFlag_IO_ThreadState())
        {
            case true:
            {
                FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Write_Start(
                    FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Get_Control_Of_WriteEnable(),
                    &coreId,
                    ptr_MyNumImplementedCores,
                    FLORENCE::framework::Get_Server()->Get_Global()
                );

                //TODO> client praise networking accepted and captured
                FLORENCE::framework::Get_Server()->Get_Data()->Get_PraiseBuffer()->SetPraiseEventId(0);//NETWORKING TODO
                FLORENCE::framework::Get_Server()->Get_Data()->Get_PraiseBuffer()->Set_InputBuffer_SubSet(
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_PraiseBuffer()->Get_InputBufferSubset()
                );
                FLORENCE::framework::Get_Server()->Get_Data()->Get_PraiseBuffer()->Get_InputBufferSubset()->Set_A(new bool(false));
                FLORENCE::framework::Get_Server()->Get_Data()->Get_PraiseBuffer()->Get_InputBufferSubset()->Set_B(new bool(false));
                //END TODO> client praise networking accepted and captured

                FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->PushToStackOfInputPraises(
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_StackOfInputPraise(),
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_PraiseBuffer()
                );

                FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->SetFlag_InputStackLoaded(true);

                while (FLORENCE::framework::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->GetFlag_ConcurrentCoreState(
                    FLORENCE::framework::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch()) == FLORENCE::framework::Get_Server()->Get_Global()->GetConst_Core_ACTIVE()
                    ) {/* wait untill a core is free */
                }

                FLORENCE::framework::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Concurrent_Thread_Start(
                    FLORENCE::framework::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency(),
                    FLORENCE::framework::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch(),
                    FLORENCE::framework::Get_Server()->Get_Global(),
                    ptr_MyNumImplementedCores
                );//Dynamic Launch

                FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Write_End(
                    FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Get_Control_Of_WriteEnable(),
                    &coreId,
                    ptr_MyNumImplementedCores,
                    FLORENCE::framework::Get_Server()->Get_Global()
                );

                FLORENCE::framework::Get_Server()->Get_Algorithms()->Get_ListenRespond()->Get_Control_Of_ListenRespond()->SetFlag_IO_ThreadState(false);//DISTRIBUTE=FALSE
                break;
            }
            case false:
            {
                if (FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->GetFlag_OutputStackLoaded() == true)
                {
                    FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Write_Start(
                        FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Get_Control_Of_WriteEnable(),
                        &coreId,
                        ptr_MyNumImplementedCores,
                        FLORENCE::framework::Get_Server()->Get_Global()
                    );
                    FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->PopFromStackOfOutput(
                        FLORENCE::framework::Get_Server()->Get_Data()->Get_DistributeBuffer(),
                        FLORENCE::framework::Get_Server()->Get_Data()->Get_StackOfDistributeBuffer()
                    );
                    if (sizeof(FLORENCE::framework::Get_Server()->Get_Data()->Get_StackOfDistributeBuffer()) < 1)
                    {
                        FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->SetFlag_OutputStackLoaded(false);
                    }
                    else
                    {
                        FLORENCE::framework::Get_Server()->Get_Data()->Get_Control_Of_Data()->SetFlag_OutputStackLoaded(true);
                    }
                    //TODO> FLORENCE::framework::Get_Server() distribute networking
                    /*
                    *  send registers in distribute buffer
                    *  set ACK distribute sent to equal TRUE
                    */
                    FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Write_End(
                        FLORENCE::framework::Get_Server()->Get_Execute()->Get_WriteEnable()->Get_Control_Of_WriteEnable(),
                        &coreId,
                        ptr_MyNumImplementedCores,
                        FLORENCE::framework::Get_Server()->Get_Global()
                    );
                }
                FLORENCE::framework::Get_Server()->Get_Algorithms()->Get_ListenRespond()->Get_Control_Of_ListenRespond()->SetFlag_IO_ThreadState(true);//LISTEN=TRUE
                break;
            }
        }
    }

    class Control_Of_ListenRespond* ListenRespond::Get_Control_Of_ListenRespond()
    {
        return ptr_Control_Of_ListenRespond;
    }
}
