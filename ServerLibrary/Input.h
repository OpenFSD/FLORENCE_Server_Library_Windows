#pragma once
#include "Control_Of_Input.h"
#include "Praise0_Input.h"

namespace FLORENCE
{
    class Input
    {
    public:
        Input();
        virtual ~Input();
        void Initialise_Control();
        class Control_Of_Input* Get_Control_Of_Input();
        class Praise0_Input* Get_InputBufferSubset();//TODO CLASS T
        int* GetPraiseEventId();

        void Set_InputBuffer_SubSet(class Praise0_Input* value);//TODO CLASS T
        void SetPraiseEventId(int value);

    protected:

    private:
        static class Control_Of_Input* ptr_Control_Of_Input;
        static class Praise0_Input* ptr_praiseInputBuffer_Subset;//TODO CLASS T
        static int* ptr_in_praiseEventId;

    };
}