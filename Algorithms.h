#pragma once
#include <array>
#include "Concurrent.h"
#include "ListenRespond.h"
#include "Praise0_Algorithm.h"

namespace FLORENCE
{
    class Algorithms
    {
    public:
        Algorithms();
        virtual ~Algorithms();
        Concurrent* Get_Concurren_Array(int concurrent_coreId);
        ListenRespond* Get_ListenRespond();
        void Initialise(unsigned char* ptr_NumberOfImplementedCores);

//===
//===
        class Praise0_Algorithm* Get_Praise0_Algorithm();
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
        class Praise0_Algorithm* ptr_Praise0_Algorithm;
//===
//===
    };
}