#pragma once
#include "Control_Of_LaunchConcurrency.h"
#include "Global.h"

namespace FLORENCE
{
    class LaunchConcurrency
    {
    public:
        LaunchConcurrency();
        virtual ~LaunchConcurrency();

        void Concurrent_Thread_Start(
            Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
            unsigned char* ptr_concurrent_CoreId,
            Global* ptr_Global,
            unsigned char* ptr_NumImplementedCores

        );
        void Initialise_Control(
            Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        void Thread_End(
            Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
            unsigned char* ptr_concurrent_CoreId,
            Global* ptr_Global
        );
        Control_Of_LaunchConcurrency* Get_Control_Of_LaunchConcurrency();

    protected:

    private:
        class Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency;
    };
}