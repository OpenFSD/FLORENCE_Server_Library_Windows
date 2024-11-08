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

        void concurrent_Thread_Start(
            class Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
            unsigned char* ptr_concurrent_CoreId,
            class Global* ptr_Global,
            unsigned char* ptr_NumImplementedCores

        );
        void initialise_Control(
            class Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        void thread_End(
            class Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
            unsigned char* ptr_concurrent_CoreId,
            class Global* ptr_Global
        );
        class Control_Of_LaunchConcurrency* get_Control_Of_LaunchConcurrency();

    protected:

    private:
        class Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency;
    };
}