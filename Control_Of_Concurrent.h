#pragma once
#include "framework.h"
#include "Praise0_Algorithm.h"

namespace FLORENCE
{
    class Control_Of_Concurrent
    {
    public:
        Control_Of_Concurrent();
        virtual ~Control_Of_Concurrent();
        void SelectSet_Algorithm_Subset_For_Given_PraiseEventId(
            int* ptr_praiseEventId,
            unsigned char concurrent_coreId
        );

    protected:

    private:

    };
}