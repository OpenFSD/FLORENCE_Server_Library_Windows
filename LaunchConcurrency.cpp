#include "pch.h"
#include "LaunchConcurrency.h"

namespace FLORENCE
{
    LaunchConcurrency::LaunchConcurrency()
    {

    }

    LaunchConcurrency::~LaunchConcurrency()
    {
        delete this->ptr_Control_Of_LaunchConcurrency;
    }

    void LaunchConcurrency::concurrent_Thread_Start(
        class Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
        unsigned char* ptr_concurrent_CoreId,
        class Global* ptr_Global,
        unsigned char* ptr_NumImplementedCores
    )
    {
        ptr_Control_Of_LaunchConcurrency->launchEnable_Request(ptr_concurrent_CoreId, ptr_Global);
        ptr_Control_Of_LaunchConcurrency->launchQue_Update(ptr_NumImplementedCores);
        ptr_Control_Of_LaunchConcurrency->launchEnable_SortQue(ptr_Global, ptr_NumImplementedCores);
        ptr_Control_Of_LaunchConcurrency->launchEnable_Activate(ptr_Global);
        ptr_Control_Of_LaunchConcurrency->launchQue_Update(ptr_NumImplementedCores);
        ptr_Control_Of_LaunchConcurrency->launchEnable_SortQue(ptr_Global, ptr_NumImplementedCores);
        ptr_Control_Of_LaunchConcurrency->setFlag_PraisingLaunch(false);
    }

    void LaunchConcurrency::initialise_Control(
        class Global* ptr_Global,
        unsigned char* ptr_MyNumImplementedCores
    )
    {
        this->ptr_Control_Of_LaunchConcurrency = new Control_Of_LaunchConcurrency(ptr_Global, ptr_MyNumImplementedCores);
        while (this->ptr_Control_Of_LaunchConcurrency == NULL) { /* wait untill created */ }
    }

    void LaunchConcurrency::thread_End(
        Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
        unsigned char* ptr_concurrent_CoreId,
        class Global* ptr_Global
    )
    {
        while (ptr_Control_Of_LaunchConcurrency->getFlag_PraisingLaunch() == true)
        {

        }
        ptr_Control_Of_LaunchConcurrency->setFlag_PraisingLaunch(true);
        ptr_Control_Of_LaunchConcurrency->set_concurrent_CoreId_Index(*ptr_Control_Of_LaunchConcurrency->get_new_concurrent_CoreId_Index());
        if (*ptr_Control_Of_LaunchConcurrency->get_concurrent_CoreId_Index() == *ptr_concurrent_CoreId)
        {
            ptr_Control_Of_LaunchConcurrency->setFlag_ConcurrentCoreState(ptr_concurrent_CoreId, ptr_Global->getConst_Core_IDLE());
        }
        else
        {
            ptr_Control_Of_LaunchConcurrency->set_new_concurrent_CoreId_Index(*ptr_Control_Of_LaunchConcurrency->get_concurrent_CoreId_Index() + 1);

            if (*ptr_Control_Of_LaunchConcurrency->get_new_concurrent_CoreId_Index() == 3)//NUMBER OF CONCURNT CORES
            {
                ptr_Control_Of_LaunchConcurrency->set_new_concurrent_CoreId_Index(0);
            }
            ptr_Control_Of_LaunchConcurrency->setFlag_PraisingLaunch(false);
            thread_End(
                ptr_Control_Of_LaunchConcurrency,
                ptr_concurrent_CoreId,
                ptr_Global
            );
        }
    }

    Control_Of_LaunchConcurrency* LaunchConcurrency::get_Control_Of_LaunchConcurrency()
    {
        return this->ptr_Control_Of_LaunchConcurrency;
    }