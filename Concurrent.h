#pragma once
#include "Algorithms.h"
#include "Concurrent.h"
#include "Control_Of_Concurrent.h"
#include "Control_Of_Data.h"
#include "Control_Of_Execute.h"
#include "Control_Of_LaunchConcurrency.h"
#include "Control_Of_Output.h"
#include "Control_Of_WriteEnable.h"
#include "Data.h"
#include "Global.h"
#include "Input.h"
#include "LaunchConcurrency.h"
#include "Output.h"
#include "user_files/Praise0_Algorithm.h"
#include "user_files/Praise0_Input.h"
#include "user_files/Praise0_Output.h"
#include "WriteEnable.h"

namespace FLORENCE
{
    class Concurrent
    {
    public:
        Concurrent();
        virtual ~Concurrent();
        void Initialise_Control();
        static void Thread_Concurrency(
            unsigned char concurrent_coreId,
            unsigned char* ptr_MyNumImplementedCores,
            FLORENCE::Algorithms* ptr_Algorithms,
            FLORENCE::Control_Of_Concurrent* ptr_Control_Of_Concurrent,
            FLORENCE::Control_Of_Data* ptr_Control_Of_Data,
            FLORENCE::Control_Of_Execute* ptr_Control_Of_Execute,
            FLORENCE::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
            FLORENCE::Control_Of_Output* ptr_Control_Of_Output,
            FLORENCE::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
            FLORENCE::Data* ptr_Data,
            FLORENCE::Global* ptr_Global,
            FLORENCE::Input* ptr_InputBuffer,
            std::vector<class FLORENCE::Input*>* ptr_InputStack,
            FLORENCE::LaunchConcurrency* ptr_LaunchConcurrency,
            FLORENCE::Output* ptr_Output,
            std::vector<class Output*>* ptr_OutputStack,
            Praise0_Algorithm* ptr_Algorithm_Subset,
            FLORENCE::Praise0_Input* ptr_Input_Subset,
            FLORENCE::Praise0_Output* ptr_Output_Subset,
            FLORENCE::WriteEnable* ptr_WriteEnable
        );

        void Do_Concurrent_Algorithm_For_PraiseEventId(
            int* ptr_praiseEventId,
            Praise0_Algorithm* ptr_Algorithm_Subset,
            FLORENCE::Praise0_Input* ptr_Input_Subset,
            FLORENCE::Praise0_Output* ptr_Output_Subset
        );
        Praise0_Algorithm* Get_Algorithm_Subset();//TODO CLASS T
        class Control_Of_Concurrent* Get_Control_Of_Concurrent();

        void Set_Algorithm_Subset(Praise0_Algorithm* value_algorithm);//TODO CLASS T

    protected:

    private:
        class Control_Of_Concurrent* ptr_Control_Of_Concurrent;
        class Praise0_Algorithm* ptr_Algorithms_Subset;//TODO CLASS T

    };
}