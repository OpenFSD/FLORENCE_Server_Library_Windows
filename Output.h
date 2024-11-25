#pragma once
#include "Control_Of_Output.h"
#include "Praise0_Output.h"

namespace FLORENCE
{
    class Output
    {
    public:
        Output();
        virtual ~Output();
        void Initialise_Control();
        Control_Of_Output* Get_Control_Of_Output();
        Praise0_Output* Get_OutputBuffer_Subset();//TODO CLASS T
        int* GetPraiseEventId();

        void Set_OutputBuffer_Subset(class Praise0_Output* value);
        void SetPraiseEventId(int value);

    protected:

    private:
        Control_Of_Output* ptr_Control_Of_Output;
        Praise0_Output* praiseOutputBuffer_Subset;//ToDo buffer
        static int* ptr_out_PraiseEventId;
    };
}