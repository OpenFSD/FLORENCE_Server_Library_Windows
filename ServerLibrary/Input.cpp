#include "Input.h"
#include <cstddef>

namespace FLORENCE
{
    class Control_Of_Input* Input::ptr_Control_Of_Input = NULL;
    class Praise0_Input* Input::ptr_praiseInputBuffer_Subset = NULL;//TODO CLASS T
    int* Input::ptr_in_praiseEventId = NULL;

    Input::Input()
    {
        ptr_praiseInputBuffer_Subset = new class FLORENCE::Praise0_Input();//TODO CLASS T
        while (ptr_praiseInputBuffer_Subset == NULL) { /* wait untill created */ }

        ptr_in_praiseEventId = new int(0);
        while (ptr_in_praiseEventId == NULL) { /* wait untill created */ }
    }

    Input::~Input()
    {
        delete ptr_Control_Of_Input;
        delete ptr_praiseInputBuffer_Subset;
        delete ptr_in_praiseEventId;
    }

    void Input::Initialise_Control()
    {
        ptr_Control_Of_Input = new class FLORENCE::Control_Of_Input();
        while (ptr_Control_Of_Input == NULL) { /* wait untill created */ }
    }

    class Control_Of_Input* Input::Get_Control_Of_Input()
    {
        return ptr_Control_Of_Input;
    }

    int* Input::GetPraiseEventId()
    {
        return ptr_in_praiseEventId;
    }

    class Praise0_Input* Input::Get_InputBufferSubset()
    {
        return ptr_praiseInputBuffer_Subset;
    }

    void Input::Set_InputBuffer_SubSet(class FLORENCE::Praise0_Input* value)
    {
        ptr_praiseInputBuffer_Subset = value;
    }

    void Input::SetPraiseEventId(int value)
    {
        ptr_in_praiseEventId = &value;
    }
}