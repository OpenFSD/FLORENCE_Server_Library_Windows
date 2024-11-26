#pragma once
#include <array>
#include <vector>
#include "Control_Of_Data.h"
#include "Input.h"
#include "Output.h"
#include "Praise0_Input.h"
#include "Praise0_Output.h"

namespace FLORENCE
{
    class Data
    {
    public:
        Data(unsigned char* ptr_NumberOfImplementedCores);
        virtual ~Data();
        void Initialise_Control();
        class Control_Of_Data* Get_Control_Of_Data();
        class Output* Get_DistributeBuffer();
        class Input* Get_InputRefferenceOfCore(unsigned char concurrent_coreId);
        class Output* Get_OutputRefferenceOfCore(unsigned char concurrent_coreId);
        std::vector<class Input*>* Get_StackOfInputPraise();
        std::vector<class Output*>* Get_StackOfDistributeBuffer();
        class Input* Get_PraiseBuffer();

        void Set_DistributeBuffer(class Output* value_Output);
        void Set_InputRefferenceOfCore(unsigned char concurrent_coreId, class Input* value_Input);
        void Set_OutputRefferenceOfCore(unsigned char concurrent_coreId, class Output* value_Output);
        void Set_PraiseBuffer(class Input* value_Input);

    protected:

    private:
        class Control_Of_Data* ptr_Control_Of_Data;
        class Input* ptr_PraiseBuffer;
        class Output* ptr_DistributeBuffer;
        class Input* ptr_InputRefferenceOfCore[3];//NUMBER OF CONCURRENT CORES
        class Input** ptr_InputRefferenceOfCore_Array;
        class Input* ptr_new_Input;
        class Output* ptr_new_Output;
        class Output* ptr_OutputRefferenceOfCore[3];//NUMBER OF CONCURRENT CORES
        class Output** ptr_OutputRefferenceOfCore_Array;
        std::vector<class Input*>* ptr_StackOfInputPraise;
        std::vector<class Output*>* ptr_StackOfDistributeBuffer;
//===
//===
        class Praise0_Input* prt_Praise0_Input;
        class Praise0_Output* prt_Praise0_Outut;
//===
//===

    };
}
