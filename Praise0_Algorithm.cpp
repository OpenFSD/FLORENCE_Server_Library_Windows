#include "pch.h"
#include <cstddef>

namespace FLORENCE
{
    Praise0_Algorithm::Praise0_Algorithm()
    {
    }

    Praise0_Algorithm::~Praise0_Algorithm()
    {
    }

    void Praise0_Algorithm::Do_Praise(
        FLORENCE::Praise0_Input* ptr_In_SubSet,
        FLORENCE::Praise0_Output* ptr_Out_SubSet
    )
    {
        bool result = false;
        if (ptr_In_SubSet->Get_A() == true && ptr_In_SubSet->Get_B() == true)
        {
            ptr_Out_SubSet->SetResultForPraise_0(true);
        }
        else if (ptr_In_SubSet->Get_A() == true && ptr_In_SubSet->Get_B() == false)
        {
            ptr_Out_SubSet->SetResultForPraise_0(false);
        }
        else if (ptr_In_SubSet->Get_A() == false && ptr_In_SubSet->Get_B() == true)
        {
            ptr_Out_SubSet->SetResultForPraise_0(false);
        }
        else if (ptr_In_SubSet->Get_A() == false && ptr_In_SubSet->Get_B() == false)
        {
            ptr_Out_SubSet->SetResultForPraise_0(false);
        }
    }
}