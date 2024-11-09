#pragma once
#include "Algorithms.h"
#include "Data.h"
#include "Execute.h"
#include "Global.h"

namespace FLORENCE
{
    class Server
    {
    public:
        Server();
        virtual ~Server();
        class Algorithms* Get_Algorithms();
        class Data* Get_Data();
        class Execute* Get_Execute();
        class Global* Get_Global();

    protected:

    private:
        class Algorithms* ptr_Algorithms;
        class Data* ptr_Data;
        class Execute* ptr_Execute;
        class Global* ptr_Global;
    };
}