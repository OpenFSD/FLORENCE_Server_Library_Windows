#pragma once
#include "Praise0_Input.h"
#include "Praise0_Output.h"

namespace FLORENCE
{
    class Praise0_Algorithm
    {
    public:
        Praise0_Algorithm();
        virtual ~Praise0_Algorithm();
        void Do_Praise(
            class FLORENCE::Praise0_Input* ptr_In_SubSet,
            class FLORENCE::Praise0_Output* ptr_Out_SubSet
        );

    protected:

    private:

    };
}