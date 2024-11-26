#pragma once
#include <vector>
#include "Control_Of_ListenRespond.h"

namespace FLORENCE
{
    class ListenRespond
    {
    public:
        ListenRespond();
        virtual ~ListenRespond();
        void Initialise_Control();
        static void Thread_IO_ListenDistribute(
            unsigned char coreId,
            unsigned char* ptr_MyNumImplementedCores
        );

        Control_Of_ListenRespond* Get_Control_Of_ListenRespond();

    protected:

    private:
        class Control_Of_ListenRespond* ptr_Control_Of_ListenRespond;
    };
}