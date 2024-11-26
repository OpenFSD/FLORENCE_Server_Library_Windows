#include "LaunchConcurrency.h"
#include <cstddef>

namespace FLORENCE
{
    class Control_Of_LaunchConcurrency* LaunchConcurrency::ptr_Control_Of_LaunchConcurrency = NULL;

    LaunchConcurrency::LaunchConcurrency()
    {
        ptr_Control_Of_LaunchConcurrency = NULL;
    }

    LaunchConcurrency::~LaunchConcurrency()
    {
        delete ptr_Control_Of_LaunchConcurrency;
    }

    void LaunchConcurrency::Concurrent_Thread_Start(
        class FLORENCE::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
        unsigned char* ptr_concurrent_CoreId,
        class FLORENCE::Global* ptr_Global,
        unsigned char* ptr_NumImplementedCores
    )
    {
        ptr_Control_Of_LaunchConcurrency->LaunchEnable_Request(ptr_concurrent_CoreId, ptr_Global);
        ptr_Control_Of_LaunchConcurrency->LaunchQue_Update(ptr_NumImplementedCores);
        ptr_Control_Of_LaunchConcurrency->LaunchEnable_SortQue(ptr_Global, ptr_NumImplementedCores);
        ptr_Control_Of_LaunchConcurrency->LaunchEnable_Activate(ptr_Global);
        ptr_Control_Of_LaunchConcurrency->LaunchQue_Update(ptr_NumImplementedCores);
        ptr_Control_Of_LaunchConcurrency->LaunchEnable_SortQue(ptr_Global, ptr_NumImplementedCores);
        ptr_Control_Of_LaunchConcurrency->SetFlag_PraisingLaunch(false);
    }

    void LaunchConcurrency::Initialise_Control(
        class FLORENCE::Global* ptr_Global,
        unsigned char* ptr_MyNumImplementedCores
    )
    {
        ptr_Control_Of_LaunchConcurrency = new class FLORENCE::Control_Of_LaunchConcurrency(ptr_Global, ptr_MyNumImplementedCores);
        while (ptr_Control_Of_LaunchConcurrency == NULL) { /* wait untill created */ }
    }

    void LaunchConcurrency::Thread_End(
        class FLORENCE::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
        unsigned char* ptr_concurrent_CoreId,
        class FLORENCE::Global* ptr_Global
    )
    {
        while (ptr_Control_Of_LaunchConcurrency->GetFlag_PraisingLaunch() == true)
        {

        }
        ptr_Control_Of_LaunchConcurrency->SetFlag_PraisingLaunch(true);
        ptr_Control_Of_LaunchConcurrency->Set_concurrent_CoreId_Index(*ptr_Control_Of_LaunchConcurrency->Get_new_concurrent_CoreId_Index());
        if (*ptr_Control_Of_LaunchConcurrency->Get_concurrent_CoreId_Index() == *ptr_concurrent_CoreId)
        {
            ptr_Control_Of_LaunchConcurrency->SetFlag_ConcurrentCoreState(ptr_concurrent_CoreId, ptr_Global->GetConst_Core_IDLE());
        }
        else
        {
            ptr_Control_Of_LaunchConcurrency->Set_new_concurrent_CoreId_Index(*ptr_Control_Of_LaunchConcurrency->Get_concurrent_CoreId_Index() + 1);

            if (*ptr_Control_Of_LaunchConcurrency->Get_new_concurrent_CoreId_Index() == 3)//NUMBER OF CONCURNT CORES
            {
                ptr_Control_Of_LaunchConcurrency->Set_new_concurrent_CoreId_Index(0);
            }
            ptr_Control_Of_LaunchConcurrency->SetFlag_PraisingLaunch(false);
            Thread_End(
                ptr_Control_Of_LaunchConcurrency,
                ptr_concurrent_CoreId,
                ptr_Global
            );
        }
    }

    class Control_Of_LaunchConcurrency* LaunchConcurrency::Get_Control_Of_LaunchConcurrency()
    {
        return ptr_Control_Of_LaunchConcurrency;
    }
}