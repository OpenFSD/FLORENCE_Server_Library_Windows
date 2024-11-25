#include "pch.h"
#include <cstddef>

namespace FLORENCE
{
    class Control_Of_Input* ptr_Control_Of_Input = NULL;
    class Praise0_Input* ptr_praiseInputBuffer_Subset = NULL;//TODO CLASS T
    int* ptr_in_praiseEventId = NULL;

    Input::Input()
    {
        this->ptr_praiseInputBuffer_Subset = new Praise0_Input();//TODO CLASS T
        while (this->ptr_praiseInputBuffer_Subset == NULL) { /* wait untill created */ }

        this->ptr_in_praiseEventId = new int(0);
        while (this->ptr_in_praiseEventId == NULL) { /* wait untill created */ }
    }

    Input::~Input()
    {
        delete ptr_Control_Of_Input;
        delete ptr_praiseInputBuffer_Subset;
        delete ptr_in_praiseEventId;
    }

    void Input::Initialise_Control()
    {
        this->ptr_Control_Of_Input = new Control_Of_Input();
        while (this->ptr_Control_Of_Input == NULL) { /* wait untill created */ }
    }

    class Control_Of_Input* Input::Get_Control_Of_Input()
    {
        return this->ptr_Control_Of_Input;
    }

    int* Input::GetPraiseEventId()
    {
        return this->ptr_in_praiseEventId;
    }

    class Praise0_Input* Input::Get_InputBufferSubset()
    {
        return this->ptr_praiseInputBuffer_Subset;
    }

    void Input::Set_InputBuffer_SubSet(FLORENCE::Praise0_Input* value)
    {
        this->ptr_praiseInputBuffer_Subset = value;
    }

    void Input::SetPraiseEventId(int value)
    {
        this->ptr_in_praiseEventId = &value;
    }
}