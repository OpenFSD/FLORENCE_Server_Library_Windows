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
        class FLORENCE::Global* ptr_Global,
        unsigned char* ptr_MyNumImplementedCores
    )
    {
        this->ptr_LaunchConcurrency = new class LaunchConcurrency();
        while (this->ptr_LaunchConcurrency == NULL) { /* wait untill created */ }
        this->ptr_LaunchConcurrency->Initialise_Control(ptr_Global, ptr_MyNumImplementedCores);

        this->ptr_WriteEnable = new class WriteEnable();
        while (this->ptr_WriteEnable == NULL) { /* wait untill created */ }
        this->ptr_WriteEnable->Initialise_Control(ptr_Global, ptr_MyNumImplementedCores);
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

    void Execute::Initialise_Threads()
    {
        FLORENCE::Server* server = FLORENCE::framework::Get_Server();
        ptr_Thread_WithCoreId[0] = new std::thread(
            server->Get_Algorithms()->Get_ListenRespond()->Thread_IO_ListenDistribute,
            unsigned char(0),
            server->Get_Global()->Get_NumCores(),
            server->Get_Execute()->Get_Control_Of_Execute(),
            server->Get_Data()->Get_Control_Of_Data(),
            server->Get_Execute()->Get_LaunchConcurrency(),
            server->Get_Algorithms()->Get_ListenRespond()->Get_Control_Of_ListenRespond(),
            server->Get_Execute()->Get_WriteEnable(),
            server->Get_Data(),
            server->Get_Global(),
            server->Get_Data()->Get_StackOfInputPraise(),
            server->Get_Execute()->Get_LaunchConcurrency(),
            server->Get_Data()->Get_StackOfDistributeBuffer(),
            server->Get_Data()->Get_PraiseBuffer(),
            server->Get_Data()->Get_PraiseBuffer()->Get_InputBufferSubset(),
            server->Get_Execute()->Get_WriteEnable()
        );
        for (unsigned char index = 1; index <= *server->Get_Global()->Get_NumCores(); index++)
        {
            ptr_Thread_WithCoreId[index] = new std::thread(
                server->Get_Algorithms()->Get_Concurren_Array(index)->Thread_Concurrency,
                unsigned char(index),
                server->Get_Global()->Get_NumCores(),
                server->Get_Algorithms()->Get_Concurren_Array(index),
                server->Get_Algorithms()->Get_Concurren_Array(index)->Get_Control_Of_Concurrent(),
                server->Get_Data()->Get_Control_Of_Data(),
                server->Get_Execute()->Get_Control_Of_Execute(),
                server->Get_Execute()->Get_LaunchConcurrency(),
                server->Get_Execute()->Get_WriteEnable(),
                server->Get_Data(),
                server->Get_Global(),
                server->Get_Data()->Get_PraiseBuffer(),
                server->Get_Data()->Get_StackOfInputPraise(),
                server->Get_Execute()->Get_LaunchConcurrency(),
                server->Get_Data()->Get_DistributeBuffer(),
                server->Get_Data()->Get_StackOfDistributeBuffer(),
                server->Get_Algorithms()->Get_Concurren_Array(index)->Get_Algorithm_Subset(),
                server->Get_Data()->Get_PraiseBuffer()->Get_InputBufferSubset(),
                server->Get_Data()->Get_DistributeBuffer()->Get_OutputBuffer_Subset(),
                server->Get_Execute()->Get_WriteEnable()
            );
        }
        while (server->Get_Execute()->Get_Control_Of_Execute()->GetFlag_SystemInitialised(server->Get_Global()->Get_NumCores()) != false)
        {

        }
    }

    void Execute::Initialise_Control(
        unsigned char* ptr_MyNumImplementedCores,
        class FLORENCE::Global* ptr_Global
    )
    {
        this->ptr_Control_Of_Execute = new class Control_Of_Execute(ptr_MyNumImplementedCores);
        while (this->ptr_Control_Of_Execute == NULL) { /* wait untill created */ }
    }

    class Control_Of_Execute* Execute::Get_Control_Of_Execute()
    {
        return this->ptr_Control_Of_Execute;
    }

    class LaunchConcurrency* Execute::Get_LaunchConcurrency()
    {
        return this->ptr_LaunchConcurrency;
    }

    class WriteEnable* Execute::Get_WriteEnable()
    {
        return this->ptr_WriteEnable;
    }
}