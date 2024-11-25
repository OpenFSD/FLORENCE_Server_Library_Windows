#pragma once
#include "framework.h"
#include "Praise0_Output.h"
#include "Server.h"

namespace FLORENCE
{
    class Control_Of_Output
    {
    public:
        Control_Of_Output();
        virtual ~Control_Of_Output();
        void SelectSet_Output_Subset_For_Given_PraiseEventId(
            int* ptr_praiseEventId,
            unsigned char concurrent_coreId
        );

    protected:

    private:

    };
}