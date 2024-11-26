#include "Execute.h"
#include <cstddef>

namespace FLORENCE
{
    class Control_Of_Execute* Execute::ptr_Control_Of_Execute = NULL;
    class LaunchConcurrency* Execute::ptr_LaunchConcurrency = NULL;
    std::thread* Execute::ptr_Thread_WithCoreId[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
    class WriteEnable* Execute::ptr_WriteEnable = NULL;

    Execute::Execute(
        Global* ptr_Global,
        unsigned char* ptr_MyNumImplementedCores
    )
    {
        ptr_Control_Of_Execute = NULL;

        ptr_LaunchConcurrency = new class FLORENCE::LaunchConcurrency();
        while (ptr_LaunchConcurrency == NULL) { /* wait untill created */ }
        ptr_LaunchConcurrency->Initialise_Control(ptr_Global, ptr_MyNumImplementedCores);

        ptr_Thread_WithCoreId[4] = { NULL };//NUMBER OF CORES

        ptr_WriteEnable = new class FLORENCE::WriteEnable();
        while (ptr_WriteEnable == NULL) { /* wait untill created */ }
        ptr_WriteEnable->Initialise_Control(ptr_Global, ptr_MyNumImplementedCores);
    }

    Execute::~Execute()
    {
        delete ptr_Control_Of_Execute;
        delete ptr_LaunchConcurrency;
        delete ptr_WriteEnable;
        for (int index = 0; index < 4; index++)
        {
            delete ptr_Thread_WithCoreId[index];
        }//NUMBER OF CORES
    }

    void Execute::Initialise()
    {
        FLORENCE::framework::Get_Server()->Get_Algorithms()->Initialise(FLORENCE::framework::Get_Server()->Get_Global()->Get_NumCores());
    }

    void Execute::Initialise_Control(
        unsigned char* ptr_MyNumImplementedCores,
        FLORENCE::Global* ptr_Global
    )
    {
        ptr_Control_Of_Execute = new class FLORENCE::Control_Of_Execute(ptr_MyNumImplementedCores);
        while (ptr_Control_Of_Execute == NULL) { /* wait untill created */ }
    }

    void Execute::Initialise_Threads()
    {
        ptr_Thread_WithCoreId[0] = new std::thread(
            FLORENCE::framework::Get_Server()->Get_Algorithms()->Get_ListenRespond()->Thread_IO_ListenDistribute,
            unsigned char(0),
            FLORENCE::framework::Get_Server()->Get_Global()->Get_NumCores()
        );
        for (unsigned char index = 1; index <= *FLORENCE::framework::Get_Server()->Get_Global()->Get_NumCores(); index++)
        {
            ptr_Thread_WithCoreId[index] = new std::thread(
                FLORENCE::framework::Get_Server()->Get_Algorithms()->Get_Concurren_Array(int(index))->Thread_Concurrency,
                unsigned char(index),
                FLORENCE::framework::Get_Server()->Get_Global()->Get_NumCores()
            );
        }
        while (FLORENCE::framework::Get_Server()->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised(FLORENCE::framework::Get_Server()->Get_Global()->Get_NumCores()) != false)
        {

        }
    }

    class Control_Of_Execute* Execute::Get_Control_Of_Execute()
    {
        return ptr_Control_Of_Execute;
    }

    class LaunchConcurrency* Execute::Get_LaunchConcurrency()
    {
        return ptr_LaunchConcurrency;
    }

    class WriteEnable* Execute::Get_WriteEnable()
    {
        return ptr_WriteEnable;
    }
}