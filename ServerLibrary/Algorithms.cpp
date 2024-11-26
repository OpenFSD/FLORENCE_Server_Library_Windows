#include "Algorithms.h"
#include <cstddef>

namespace FLORENCE
{
    class Concurrent** Algorithms::ptr_Concurrent_Array = NULL;
    class Concurrent* Algorithms::ptr_Concurrent[3] = { NULL, NULL, NULL };
    class ListenRespond* Algorithms::ptr_ListenRespond = NULL;
    class Concurrent* Algorithms::ptr_New_Concurrent = NULL;
//===
//===
    class Praise0_Algorithm* Algorithms::ptr_Praise0_Algorithm = NULL;
//===
//===

    Algorithms::Algorithms()
    {
        ptr_Concurrent[0] = new class FLORENCE::Concurrent();
        ptr_Concurrent[1] = new class FLORENCE::Concurrent();
        ptr_Concurrent[2] = new class FLORENCE::Concurrent();//NUMBER OF CONCURRENT CORES
        ptr_Concurrent_Array = ptr_Concurrent;
//===
//===
        ptr_Praise0_Algorithm = new class FLORENCE::Praise0_Algorithm();
        while (ptr_Praise0_Algorithm == NULL) { /* wait untill class constructed */ }
//===
//===
    }

    Algorithms::~Algorithms()
    {
        for (int index = 0; index < 3; index++)//NUMBER OF CONCURRENT CORES
        {
            delete ptr_Concurrent[index];
        }
        delete ptr_Concurrent_Array;
        delete ptr_ListenRespond;
        delete ptr_Praise0_Algorithm;
    }

    void Algorithms::Initialise(unsigned char* ptr_NumberOfImplementedCores)
    {
        ptr_New_Concurrent = new class FLORENCE::Concurrent();
        while (ptr_New_Concurrent == NULL) { /* wait untill created */ }
        ptr_New_Concurrent->Initialise_Control();

        for (unsigned char index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
        {
            ptr_Concurrent[index] = ptr_New_Concurrent;
        }
        delete ptr_New_Concurrent;
        ptr_Concurrent_Array = ptr_Concurrent;
        while (ptr_Concurrent_Array == NULL) { /* wait untill class constructed */ }

        ptr_ListenRespond = new class FLORENCE::ListenRespond();
        while (ptr_ListenRespond == NULL) { /* wait untill class constructed */ }
        ptr_ListenRespond->Initialise_Control();
    }

    class Concurrent* Algorithms::Get_Concurren_Array(int concurrent_coreId)
    {
        return ptr_Concurrent[concurrent_coreId];
    }

    class ListenRespond* Algorithms::Get_ListenRespond()
    {
        return ptr_ListenRespond;
    }

//===
//===
    class Praise0_Algorithm* Algorithms::Get_Praise0_Algorithm()
    {
        return ptr_Praise0_Algorithm;
    }
//===
//===
}