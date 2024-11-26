#pragma once
#include "Control_Of_ListenRespond.h"
#include "framework.h"

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

        class Control_Of_ListenRespond* Get_Control_Of_ListenRespond();

    protected:

    private:
        static class Control_Of_ListenRespond* ptr_Control_Of_ListenRespond;
    };
}