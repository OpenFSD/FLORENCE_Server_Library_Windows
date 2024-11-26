#pragma once
#include <array>
#include <thread>
#include "Control_Of_Execute.h"
#include "Global.h"
#include "LaunchConcurrency.h"
#include "WriteEnable.h"
#include "framework.h"

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
        void Initialise();
        void Initialise_Control(
            unsigned char* ptr_MyNumImplementedCores,
            class Global* ptr_Global
        );
        void Initialise_Threads();
        class Control_Of_Execute* Get_Control_Of_Execute();
        class LaunchConcurrency* Get_LaunchConcurrency();
        class WriteEnable* Get_WriteEnable();

    protected:

    private:
        static class Control_Of_Execute* ptr_Control_Of_Execute;
        static class LaunchConcurrency* ptr_LaunchConcurrency;
        static std::thread* ptr_Thread_WithCoreId[4];//NUMBER OF CORES
        static class WriteEnable* ptr_WriteEnable;
    };
}