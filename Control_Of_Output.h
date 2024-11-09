#pragma once
#include "Framework.h"
#include "user_files/Praise0_Output.h"
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
            FLORENCE::Server* ptr_Server,
            unsigned char concurrent_coreId
        );

    protected:

    private:

    };
}