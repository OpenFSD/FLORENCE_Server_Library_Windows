#include "pch.h"
#include "Execute.h"
#include <cstddef>

namespace FLORENCE
{
    class Control_Of_Execute* ptr_Control_Of_Execute = NULL;
    class LaunchConcurrency* ptr_LaunchConcurrency = NULL;
    std::thread* ptr_Thread_WithCoreId[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
    class WriteEnable* ptr_WriteEnable = NULL;

    Execute::Execute(
        class Global* ptr_Global,
        unsigned char* ptr_MyNumImplementedCores
    )
    {
        this->ptr_Control_Of_Execute = new Control_Of_Execute();
        while (this->ptr_Control_Of_Execute == NULL) { /* wait untill created */ }

        this->ptr_LaunchConcurrency = new class LaunchConcurrency();
        while (this->ptr_LaunchConcurrency == NULL) { /* wait untill created */ }
        this->ptr_LaunchConcurrency->initialise_Control(ptr_Global, ptr_MyNumImplementedCores);

        this->ptr_Thread_WithCoreId[4] = { NULL, NULL, NULL, NULL };
        for (int index = 0; index < 4; index++)
        {
            while (this->ptr_Thread_WithCoreId[index] == NULL) { /* wait untill created */ }
        }

        this->ptr_WriteEnable = new class WriteEnable();
        while (this->ptr_WriteEnable == NULL) { /* wait untill created */ }
        this->ptr_WriteEnable->initialise_Control(ptr_Global, ptr_MyNumImplementedCores);
    }

Execute::~Execute()
{
    delete this->ptr_Control_Of_Execute;
    delete this->ptr_LaunchConcurrency;
    delete this->ptr_WriteEnable;
    for (int index = 0; index < 4; index++)
    {
        delete this->ptr_Thread_WithCoreId[index];
    }//NUMBER OF CORES
}

void Execute::initialise_Threads(FLORENCE::Framework* framework)
{
    ptr_Thread_WithCoreId[0] = new std::thread(
        framework->get_Server()->get_Algorithms()->get_ListenRespond()->thread_IO_ListenDistribute,
        unsigned char(0),
        framework->get_Server()->get_Global()->get_NumCores(),
        framework->get_Server()->get_Execute()->get_Control_Of_Execute(),
        framework->get_Server()->get_Data()->get_Control_Of_Data(),
        framework->get_Server()->get_Execute()->get_LaunchConcurrency(),
        framework->get_Server()->get_Algorithms()->get_ListenRespond()->get_Control_Of_ListenRespond(),
        framework->get_Server()->get_Execute()->get_WriteEnable(),
        framework->get_Server()->get_Data(),
        framework->get_Server()->get_Global(),
        framework->get_Server()->get_Data()->get_StackOfInputPraise(),
        framework->get_Server()->get_Execute()->get_LaunchConcurrency(),
        framework->get_Server()->get_Data()->get_StackOfDistributeBuffer(),
        framework->get_Server()->get_Data()->get_PraiseBuffer(),
        framework->get_Server()->get_Data()->get_PraiseBuffer()->get_InputBufferSubset(),
        framework->get_Server()->get_Execute()->get_WriteEnable()
    );
    for (unsigned char index = 1; index <= *framework->get_Server()->get_Global()->get_NumCores(); index++)
    {
        ptr_Thread_WithCoreId[index] = new std::thread(
            framework->get_Server()->get_Algorithms()->get_Concurren_Array(index)->thread_Concurrency,
            unsigned char(index),
            framework->get_Server()->get_Global()->get_NumCores(),
            framework->get_Server()->get_Algorithms()->get_Concurren_Array(index),
            framework->get_Server()->get_Algorithms()->get_Concurren_Array(index)->get_Control_Of_Concurrent(),
            framework->get_Server()->get_Data()->get_Control_Of_Data(),
            framework->get_Server()->get_Execute()->get_Control_Of_Execute(),
            framework->get_Server()->get_Execute()->get_LaunchConcurrency(),
            framework->get_Server()->get_Execute()->get_WriteEnable(),
            framework->get_Server()->get_Data(),
            framework->get_Server()->get_Global(),
            framework->get_Server()->get_Data()->get_PraiseBuffer(),
            framework->get_Server()->get_Data()->get_StackOfInputPraise(),
            framework->get_Server()->get_Execute()->get_LaunchConcurrency(),
            framework->get_Server()->get_Data()->get_DistributeBuffer(),
            framework->get_Server()->get_Data()->get_StackOfDistributeBuffer(),
            framework->get_Server()->get_Algorithms()->get_Concurren_Array(index)->get_Algorithm_Subset(),
            framework->get_Server()->get_Data()->get_PraiseBuffer()->get_InputBufferSubset(),
            framework->get_Server()->get_Data()->get_DistributeBuffer()->get_OutputBuffer_Subset(),
            framework->get_Server()->get_Execute()->get_WriteEnable()
        );
    }
    while (framework->get_Server()->get_Execute()->get_Control_Of_Execute()->getFlag_SystemInitialised(framework->get_Server()->get_Global()->get_NumCores()) != false)
    {

    }
}
}