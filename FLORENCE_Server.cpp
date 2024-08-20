﻿// FLORENCE_Server.cpp : Defines the entry point for the application.
//
#include "FLORENCE_Server.h"

namespace FLORENCE
{
    int main()
    {
        ptr_Framework = new class FLORENCE::Framework();
        while (ptr_Framework == nullptr) { /* wait untill created */ }
        ptr_Framework->get_Server()->get_Execute()->initialise_Threads();
        return 0;
    }

    static class FLORENCE::Framework* Get_framework()
    {
        return ptr_Framework;
    }
}