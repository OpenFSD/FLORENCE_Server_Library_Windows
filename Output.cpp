#include "pch.h"
#include <cstddef>


namespace FLORENCE
{
    Control_Of_Output* ptr_Control_Of_Output;
    int* Output::ptr_out_PraiseEventId = nullptr;
    Praise0_Output* praiseOutputBuffer_Subset;//ToDo buffer

    Output::Output()
    {
        this->praiseOutputBuffer_Subset = new Praise0_Output();//ToDo CLASS T
        while (this->praiseOutputBuffer_Subset == nullptr) { /* wait untill created */ }
        int* ptr_out_PraiseEventId = new int(0);
        while (this->ptr_out_PraiseEventId == nullptr) { /* wait untill created */ }
    }

    Output::~Output()
    {
        delete this->ptr_Control_Of_Output;
        delete this->praiseOutputBuffer_Subset;
        delete this->ptr_out_PraiseEventId;
    }

    void Output::Initialise_Control()
    {
        this->ptr_Control_Of_Output = new Control_Of_Output();
        while (this->ptr_Control_Of_Output == nullptr) { /* wait untill created */ }
    }

    Control_Of_Output* Output::Get_Control_Of_Output()
    {
        return this->ptr_Control_Of_Output;
    }

    Praise0_Output* Output::Get_OutputBuffer_Subset()
    {
        return this->praiseOutputBuffer_Subset;
    }

    int* Output::GetPraiseEventId()
    {
        return this->ptr_out_PraiseEventId;
    }

    void Output::Set_OutputBuffer_Subset(Praise0_Output* value)
    {
        this->praiseOutputBuffer_Subset = value;
    }

    void Output::SetPraiseEventId(int value)
    {
        this->ptr_out_PraiseEventId = &value;
    }
}
