#pragma once
#include <vector>
#include "Input.h"
#include "Output.h"

namespace FLORENCE
{
    class Control_Of_Data
    {
    public:
        Control_Of_Data();
        virtual ~Control_Of_Data();
        void popFromStackOfInputPraises(
            class Input* referenceForCore,
            std::vector<class Input*>* ptr_inputStack
        );
        void popFromStackOfOutput(
            class Output* distributeBuffer,
            std::vector<class Output*>* ptr_outputStack
        );
        void pushToStackOfInputPraises(
            std::vector<class Input*>* ptr_InputStack,
            class Input* ptr_PraiseBuffer
        );
        void pushToStackOfOutput(
            std::vector<class Output*>* ptr_outputStack,
            class Output* ptr_referenceForCore
        );

        bool getFlag_InputStackLoaded();
        bool getFlag_OutputStackLoaded();

        void setFlag_InputStackLoaded(bool value);
        void setFlag_OutputStackLoaded(bool value);

    protected:

    private:
        void load_Input_Subset_For_PraiseEventId(int* ptr_praiseEventId);

        static bool flag_InputStackLoaded;
        static bool flag_OutputStackLoaded;
    };
}