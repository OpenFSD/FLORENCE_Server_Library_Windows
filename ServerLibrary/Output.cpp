#include "Output.h"
#include <cstddef>


namespace FLORENCE
{
    class Control_Of_Output* Output::ptr_Control_Of_Output = NULL;
    int* Output::ptr_out_PraiseEventId = NULL;
    class Praise0_Output* Output::praiseOutputBuffer_Subset = NULL;//ToDo buffer

    Output::Output()
    {
        praiseOutputBuffer_Subset = new class FLORENCE::Praise0_Output();//ToDo CLASS T
        while (praiseOutputBuffer_Subset == NULL) { /* wait untill created */ }
        
        int* ptr_out_PraiseEventId = new int(0);
        while (ptr_out_PraiseEventId == NULL) { /* wait untill created */ }
    }

    Output::~Output()
    {
        delete ptr_Control_Of_Output;
        delete praiseOutputBuffer_Subset;
        delete ptr_out_PraiseEventId;
    }

    void Output::Initialise_Control()
    {
        ptr_Control_Of_Output = new class FLORENCE::Control_Of_Output();
        while (ptr_Control_Of_Output == nullptr) { /* wait untill created */ }
    }

    class Control_Of_Output* Output::Get_Control_Of_Output()
    {
        return ptr_Control_Of_Output;
    }

    class Praise0_Output* Output::Get_OutputBuffer_Subset()
    {
        return praiseOutputBuffer_Subset;
    }

    int* Output::GetPraiseEventId()
    {
        return ptr_out_PraiseEventId;
    }

    void Output::Set_OutputBuffer_Subset(class FLORENCE::Praise0_Output* value)
    {
        praiseOutputBuffer_Subset = value;
    }

    void Output::SetPraiseEventId(int value)
    {
        ptr_out_PraiseEventId = &value;
    }
}
