#pragma once
#include "framework.h"
#include "user_files/Praise0_Input.h"
#include "Server.h"

namespace FLORENCE
{
    class Control_Of_Input
    {
    public:
        Control_Of_Input();
        virtual ~Control_Of_Input();
        void SelectSet_Input_Subset_For_Given_PraiseEventId(
            int* ptr_praiseEventId
        );

    protected:

    private:

    };
}