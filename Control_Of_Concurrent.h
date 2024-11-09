#pragma once
#include "Framework.h"
#include "user_files/Praise0_Algorithm.h"
#include "user_files/Praise0_Input.h"
#include "user_files/Praise0_Output.h"
#include "Server.h"

namespace FLORENCE
{
    class Control_Of_Concurrent
    {
    public:
        Control_Of_Concurrent();
        virtual ~Control_Of_Concurrent();
        void SelectSet_Algorithm_Subset_For_Given_PraiseEventId(
            int* ptr_praiseEventId,
            FLORENCE::Server* ptr_server,
            unsigned char concurrent_coreId
        );

    protected:

    private:

    };
}