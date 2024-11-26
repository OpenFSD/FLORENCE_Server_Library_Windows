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
            class Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
            unsigned char* ptr_concurrent_CoreId,
            class Global* ptr_Global,
            unsigned char* ptr_NumImplementedCores

        );
        void Initialise_Control(
            class Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        void Thread_End(
            class Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
            unsigned char* ptr_concurrent_CoreId,
            class Global* ptr_Global
        );
        class Control_Of_LaunchConcurrency* Get_Control_Of_LaunchConcurrency();

    protected:

    private:
        static class Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency;
    };
}