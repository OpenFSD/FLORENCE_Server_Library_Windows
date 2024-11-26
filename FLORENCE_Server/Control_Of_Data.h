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
        void PopFromStackOfInputPraises(
            class Input* referenceForCore,
            std::vector<class Input*>* ptr_inputStack
        );
        void PopFromStackOfOutput(
            class Output* distributeBuffer,
            std::vector<class Output*>* ptr_outputStack
        );
        void PushToStackOfInputPraises(
            std::vector<class Input*>* ptr_InputStack,
            class Input* ptr_PraiseBuffer
        );
        void PushToStackOfOutput(
            std::vector<class Output*>* ptr_outputStack,
            class Output* ptr_referenceForCore
        );

        bool GetFlag_InputStackLoaded();
        bool GetFlag_OutputStackLoaded();

        void SetFlag_InputStackLoaded(bool value);
        void SetFlag_OutputStackLoaded(bool value);

    protected:

    private:
        void Load_Input_Subset_For_PraiseEventId(int* ptr_praiseEventId);

        static bool flag_InputStackLoaded;
        static bool flag_OutputStackLoaded;
    };
}