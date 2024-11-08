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
        class Algorithms* get_Algorithms();
        class Data* get_Data();
        class Execute* get_Execute();
        class Global* get_Global();

    protected:

    private:
        class Algorithms* ptr_Algorithms;
        class Data* ptr_Data;
        class Execute* ptr_Execute;
        class Global* ptr_Global;
    };
}