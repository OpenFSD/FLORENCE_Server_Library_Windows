#include "pch.h"
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

    void Execute::Initialise()
    {
        //FLORENCE::Server* FLORENCE::framework::Get_Server() = FLORENCE::framework::Get_Server();
        FLORENCE::framework::Get_Server()->Get_Algorithms()->Initialise(FLORENCE::framework::Get_Server()->Get_Global()->Get_NumCores());
    }

    void Execute::Initialise_Control(
        unsigned char* ptr_MyNumImplementedCores,
        class FLORENCE::Global* ptr_Global
    )
    {
        this->ptr_Control_Of_Execute = new class Control_Of_Execute(ptr_MyNumImplementedCores);
        while (this->ptr_Control_Of_Execute == NULL) { /* wait untill created */ }
    }

    void Execute::Initialise_Threads()
    {
        //FLORENCE::Server* FLORENCE::framework::Get_Server() = FLORENCE::framework::Get_Server();
        this->ptr_Thread_WithCoreId[0] = new std::thread(
            FLORENCE::framework::Get_Server()->Get_Algorithms()->Get_ListenRespond()->Thread_IO_ListenDistribute,
            unsigned char(0),
            FLORENCE::framework::Get_Server()->Get_Global()->Get_NumCores()
        );
        for (unsigned char index = 1; index <= *FLORENCE::framework::Get_Server()->Get_Global()->Get_NumCores(); index++)
        {
            this->ptr_Thread_WithCoreId[index] = new std::thread(
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