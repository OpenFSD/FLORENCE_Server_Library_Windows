#pragma once
#include "Control_Of_Input.h"
#include "user_files/Praise0_Input.h"

namespace FLORENCE
{
    class Input
    {
    public:
        Input();
        virtual ~Input();
        void initialise_Control();
        class Control_Of_Input* get_Control_Of_Input();
        class Praise0_Input* get_InputBufferSubset();//TODO CLASS T
        int* getPraiseEventId();

        void set_InputBuffer_SubSet(class Praise0_Input* value);//TODO CLASS T
        void setPraiseEventId(int value);

    protected:

    private:
        class Control_Of_Input* ptr_Control_Of_Input;
        class Praise0_Input* ptr_praiseInputBuffer_Subset;//TODO CLASS T
        static int* ptr_in_praiseEventId;

    };
}