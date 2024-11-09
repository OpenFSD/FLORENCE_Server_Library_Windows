#pragma once
#include <array>
#include <thread>

#include "Control_Of_Execute.h"
#include "Framework.h"
#include "Global.h"
#include "LaunchConcurrency.h"
#include "Server.h"
#include "WriteEnable.h"

namespace FLORENCE
{
    class Execute
    {
    public:
        Execute(
            class Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        virtual ~Execute();
        void Initialise_Control(
            unsigned char* ptr_MyNumImplementedCores,
            class Global* ptr_Global
        );
        void Initialise_Threads(FLORENCE::Server* ptr_Server);
        class Control_Of_Execute* Get_Control_Of_Execute();
        class LaunchConcurrency* Get_LaunchConcurrency();
        class WriteEnable* Get_WriteEnable();

    protected:

    private:
        class Control_Of_Execute* ptr_Control_Of_Execute;
        class LaunchConcurrency* ptr_LaunchConcurrency;
        std::thread* ptr_Thread_WithCoreId[4];//NUMBER OF CORES
        class WriteEnable* ptr_WriteEnable;
    };
}