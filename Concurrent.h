#pragma once
#include "Control_Of_Concurrent.h"
#include "Praise0_Algorithm.h"
#include "Praise0_Input.h"
#include "Praise0_Output.h"

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
            unsigned char* ptr_MyNumImplementedCores
        );

        void Do_Concurrent_Algorithm_For_PraiseEventId(
            int* ptr_praiseEventId,
            Praise0_Algorithm* ptr_Algorithm_Subset,
            FLORENCE::Praise0_Input* ptr_Input_Subset,
            FLORENCE::Praise0_Output* ptr_Output_Subset
        );
        Praise0_Algorithm* Get_Algorithm_Subset();//TODO CLASS T
        Control_Of_Concurrent* Get_Control_Of_Concurrent();

        void Set_Algorithm_Subset(Praise0_Algorithm* value_algorithm);//TODO CLASS T

    protected:

    private:
        class Control_Of_Concurrent* ptr_Control_Of_Concurrent;
        class Praise0_Algorithm* ptr_Algorithms_Subset;//TODO CLASS T

    };
}