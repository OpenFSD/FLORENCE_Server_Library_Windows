#pragma once
#include <vector>

#include "Concurrent.h"
#include "Control_Of_Concurrent.h"
#include "Control_Of_Execute.h"
#include "Control_Of_Data.h"
#include "Control_Of_Input.h"
#include "Control_Of_LaunchConcurrency.h"
#include "Control_Of_ListenRespond.h"
#include "Control_Of_Output.h"
#include "Control_Of_WriteEnable.h"
#include "Data.h"
#include "Global.h"
#include "Input.h"
#include "LaunchConcurrency.h"
#include "Output.h"
#include "Praise0_Input.h"
#include "WriteEnable.h"

namespace FLORENCE
{
    class ListenRespond
    {
    public:
        ListenRespond();
        virtual ~ListenRespond();
        void Initialise_Control();
        static void Thread_IO_ListenDistribute(
            unsigned char coreId,
            unsigned char* ptr_MyNumImplementedCores,
            class Concurrent* ptr_Concurrent,
            class Control_Of_Concurrent* ptr_Control_Of_Concurrent,
            class Control_Of_Execute* ptr_Control_Of_Execute,
            class Control_Of_Data* ptr_Control_Of_Data,
            class Control_Of_Input* ptr_Control_Of_Input,
            class Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
            class Control_Of_ListenRespond* ptr_Control_Of_ListenRespond,
            class Control_Of_Output* ptr_Control_Of_Output,
            class Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
            class Data* ptr_Data,
            class Global* ptr_Global,
            std::vector<class Input*>* ptr_InputStack,
            class LaunchConcurrency* ptr_LaunchConcurrency,
            std::vector<class Output*>* ptr_OutputStack,
            class Input* ptr_PraiseBuffer,
            class Praise0_Input* ptr_PraiseBuffer_Subset,
            class WriteEnable* ptr_WriteEnable
        );

        class Control_Of_ListenRespond* Get_Control_Of_ListenRespond();

    protected:

    private:
        class Control_Of_ListenRespond* ptr_Control_Of_ListenRespond;
    };
}