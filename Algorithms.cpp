#include "pch.h"
#include <cstddef>

namespace FLORENCE
{
    Concurrent** ptr_Concurrent_Array = NULL;
    Concurrent* ptr_Concurrent[3] = { NULL, NULL, NULL };
    ListenRespond* ptr_ListenRespond = NULL;
    Concurrent* ptr_New_Concurrent = NULL;
//===
//===
    Praise0_Algorithm* ptr_Praise0_Algorithm = NULL;
//===
//===

    Algorithms::Algorithms()
    {
//===
//===
        this->ptr_Praise0_Algorithm = new Praise0_Algorithm();
        while (this->ptr_Praise0_Algorithm == NULL) { /* wait untill class constructed */ }
//===
//===
    }

    Algorithms::~Algorithms()
    {
        for (int index = 0; index < 3; index++)//NUMBER OF CONCURRENT CORES
        {
            delete this->ptr_Concurrent[index];
        }
        delete this->ptr_Concurrent_Array;
        delete this->ptr_ListenRespond;
        delete this->ptr_Praise0_Algorithm;
    }

    void Algorithms::Initialise(unsigned char* ptr_NumberOfImplementedCores)
    {
        this->ptr_New_Concurrent = new Concurrent();
        while (this->ptr_New_Concurrent == NULL) { /* wait untill created */ }
        this->ptr_New_Concurrent->Initialise_Control();

        this->ptr_Concurrent[3] = new Concurrent[3];//NUMBER OF CONCURRENT CORES
        for (unsigned char index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
        {
            this->ptr_Concurrent[index] = this->ptr_New_Concurrent;
        }
        delete this->ptr_New_Concurrent;
        this->ptr_Concurrent_Array = this->ptr_Concurrent;
        while (this->ptr_Concurrent_Array == NULL) { /* wait untill class constructed */ }

        this->ptr_ListenRespond = new ListenRespond();
        while (this->ptr_ListenRespond == NULL) { /* wait untill class constructed */ }
        this->ptr_ListenRespond->Initialise_Control();
    }

    Concurrent* Algorithms::Get_Concurren_Array(int concurrent_coreId)
    {
        return this->ptr_Concurrent[concurrent_coreId];
    }

    ListenRespond* Algorithms::Get_ListenRespond()
    {
        return this->ptr_ListenRespond;
    }

//===
//===
    Praise0_Algorithm* Algorithms::Get_Praise0_Algorithm()
    {
        return this->ptr_Praise0_Algorithm;
    }
//===
//===
}