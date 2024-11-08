#pragma once
#include <array>
#include "Concurrent.h"
#include "ListenRespond.h"
#include "user_files/Praise0_Algorithm.h"

namespace FLORENCE
{
    class Algorithms
    {
    public:
        Algorithms(unsigned char* ptr_NumberOfImplementedCores);
        virtual ~Algorithms();
        class Concurrent* get_Concurren_Array(unsigned char concurrent_coreId);
        class ListenRespond* get_ListenRespond();

//===
//===
        class Praise0_Algorithm* get_Praise0_Algorithm();
//===
//===

    protected:

    private:
        class Concurrent** ptr_Concurrent_Array;
        class Concurrent* ptr_Concurrent[3];
        class ListenRespond* ptr_ListenRespond;
        class Concurrent* ptr_New_Concurrent;
//===
//===
        class Praise0_Algorithm* ptr_Praise0_Algorithms;
//===
//===



    };
}