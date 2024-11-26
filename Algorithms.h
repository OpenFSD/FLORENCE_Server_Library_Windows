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
        class Concurrent* Get_Concurren_Array(int concurrent_coreId);
        class ListenRespond* Get_ListenRespond();
        void Initialise(unsigned char* ptr_NumberOfImplementedCores);

//===
//===
        class Praise0_Algorithm* Get_Praise0_Algorithm();
//===
//===

    protected:

    private:
        static class Concurrent** ptr_Concurrent_Array;
        static class Concurrent* ptr_Concurrent[3];
        static class ListenRespond* ptr_ListenRespond;
        static class Concurrent* ptr_New_Concurrent;
//===
//===
        static class Praise0_Algorithm* ptr_Praise0_Algorithm;
//===
//===
    };
}