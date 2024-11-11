#include "pch.h"
#include "ListenRespond.h"

namespace FLORENCE
{
    class Control_Of_ListenRespond* ptr_Control_Of_ListenRespond = NULL;

    ListenRespond::ListenRespond()
    {

    }

    ListenRespond::~ListenRespond()
    {
        delete this->ptr_Control_Of_ListenRespond;
    }

    void ListenRespond::Initialise_Control()
    {
        this->ptr_Control_Of_ListenRespond = new class Control_Of_ListenRespond();
        while (this->ptr_Control_Of_ListenRespond == NULL) { /* wait untill class constructed */ }
    }

    void ListenRespond::Thread_IO_ListenDistribute(
        unsigned char coreId,
        unsigned char* ptr_MyNumImplementedCores,
        Concurrent* ptr_Concurrent,
        Control_Of_Concurrent* ptr_Control_Of_Concurrent,
        FLORENCE::Control_Of_Execute* ptr_Control_Of_Execute,
        FLORENCE::Control_Of_Data* ptr_Control_Of_Data,
        FLORENCE::Control_Of_Input* ptr_Control_Of_Input,
        FLORENCE::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
        Control_Of_ListenRespond* ptr_Control_Of_ListenRespond,
        FLORENCE::Control_Of_Output* ptr_Control_Of_Output,
        FLORENCE::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
        FLORENCE::Data* ptr_Data,
        FLORENCE::Global* ptr_Global,
        std::vector<class FLORENCE::Input*>* ptr_InputStack,
        FLORENCE::LaunchConcurrency* ptr_LaunchConcurrency,
        std::vector<class FLORENCE::Output*>* ptr_OutputStack,
        FLORENCE::Input* ptr_PraiseBuffer,
        FLORENCE::Praise0_Input* ptr_PraiseBuffer_Subset,
        FLORENCE::WriteEnable* ptr_WriteEnable
    )
    {
        FLORENCE::Server* server = FLORENCE::framework::Get_Server();

        ptr_Control_Of_Execute->SetConditionCodeOfThisThreadedCore(coreId);
        while (ptr_Control_Of_Execute->GetFlag_SystemInitialised(ptr_MyNumImplementedCores) != false)
        {
            // wait untill ALL threads initalised in preperation of system init.
        }
        if (ptr_Control_Of_ListenRespond->GetFlag_IO_ThreadState() == true)
        {
            ptr_WriteEnable->Write_Start(
                ptr_Control_Of_WriteEnable,
                &coreId,
                ptr_MyNumImplementedCores,
                ptr_Global
            );
            
            //TODO> client praise networking accepted and captured
            ptr_Data->Get_PraiseBuffer()->SetPraiseEventId(0);//NETWORKING TODO
            ptr_Control_Of_Input->SelectSet_Input_Subset_For_Given_PraiseEventId(
                ptr_Data->Get_PraiseBuffer()->GetPraiseEventId()                
            );
            ptr_PraiseBuffer_Subset->Set_A(new bool(false));
            ptr_PraiseBuffer_Subset->Set_B(new bool(false));
            //END TODO> client praise networking accepted and captured

            ptr_Control_Of_Data->PushToStackOfInputPraises(
                ptr_InputStack,
                ptr_PraiseBuffer
            );

            ptr_Control_Of_Data->SetFlag_InputStackLoaded(true);

            while (ptr_Control_Of_LaunchConcurrency->GetFlag_ConcurrentCoreState(ptr_Control_Of_LaunchConcurrency->Get_coreId_To_Launch()) == ptr_Global->GetConst_Core_ACTIVE()) {/* wait untill a core is free */ }
            ptr_LaunchConcurrency->Concurrent_Thread_Start(
                ptr_Control_Of_LaunchConcurrency,
                ptr_Control_Of_LaunchConcurrency->Get_coreId_To_Launch(),
                ptr_Global,
                ptr_MyNumImplementedCores
            );//Dynamic Launch

            ptr_WriteEnable->Write_End(
                ptr_Control_Of_WriteEnable,
                &coreId,
                ptr_MyNumImplementedCores,
                ptr_Global
            );

            ptr_Control_Of_ListenRespond->SetFlag_IO_ThreadState(false);//DISTRIBUTE=FALSE
        }
        else if (ptr_Control_Of_ListenRespond->GetFlag_IO_ThreadState() == false)
        {
            if (ptr_Control_Of_Data->GetFlag_OutputStackLoaded() == true)
            {
                ptr_WriteEnable->Write_Start(
                    ptr_Control_Of_WriteEnable,
                    &coreId,
                    ptr_MyNumImplementedCores,
                    ptr_Global
                );
                ptr_Control_Of_Data->PopFromStackOfOutput(
                    ptr_Data->Get_DistributeBuffer(),
                    ptr_OutputStack
                );
                if (sizeof(ptr_Data->Get_StackOfDistributeBuffer()) < 1)
                {
                    ptr_Control_Of_Data->SetFlag_OutputStackLoaded(false);
                }
                else
                {
                    ptr_Control_Of_Data->SetFlag_OutputStackLoaded(true);
                }
                //TODO> server distribute networking
                /*
                *  send registers in distribute buffer
                *  set ACK distribute sent to equal TRUE
                */
                ptr_WriteEnable->Write_End(
                    ptr_Control_Of_WriteEnable,
                    &coreId,
                    ptr_MyNumImplementedCores,
                    ptr_Global
                );
            }
            ptr_Control_Of_ListenRespond->SetFlag_IO_ThreadState(true);//LISTEN=TRUE
        }
    }

    class Control_Of_ListenRespond* ListenRespond::Get_Control_Of_ListenRespond()
    {
        return this->ptr_Control_Of_ListenRespond;
    }

}
