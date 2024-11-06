#include "pch.h"
#include "Algorithms.h"

namespace FLORENCE
{
    class Concurrent** ptr_Concurrent_Array = NULL;
    class Concurrent* ptr_Concurrent[3] = { NULL, NULL, NULL };
    class ListenRespond* ptr_ListenRespond = NULL;
    class Concurrent* ptr_New_Concurrent = NULL;
//===
//===
    class Praise0_Algorithm* ptr_Praise0_Algorithms = NULL;
//===
//===

    Algorithms::Algorithms(unsigned char* ptr_NumberOfImplementedCores)
    {
        this->ptr_New_Concurrent = new Concurrent();
        this->ptr_New_Concurrent->initialise_Control();

        * ptr_Concurrent[3] = {
            this->ptr_New_Concurrent,
            this->ptr_New_Concurrent,
            this->ptr_New_Concurrent
        };//NUMBER OF CONCURRENT CORES
        delete this->ptr_New_Concurrent;

        this->ptr_Concurrent_Array = this->ptr_Concurrent;
        while (this->ptr_Concurrent_Array == NULL) { /* wait untill class constructed */ }

        this->ptr_ListenRespond = new ListenRespond();
        while (this->ptr_ListenRespond == NULL) { /* wait untill class constructed */ }
        this->ptr_ListenRespond->initialise_Control();
//===
//===
        this->ptr_Praise0_Algorithms = new Praise0_Algorithm();
        while (this->ptr_Praise0_Algorithms == NULL) { /* wait untill class constructed */ }
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
        delete this->ptr_Praise0_Algorithms;
    }

    class Concurrent* Algorithms::get_Concurren_Array(unsigned char concurrent_coreId)
    {
        return this->ptr_Concurrent[concurrent_coreId];
    }

    class ListenRespond* Algorithms::get_ListenRespond()
    {
        return this->ptr_ListenRespond;
    }

//===
//===
    class Praise0_Algorithm* Algorithms::get_Praise0_Algorithm()
    {
        return this->ptr_Praise0_Algorithms;
    }
//===
//===
}