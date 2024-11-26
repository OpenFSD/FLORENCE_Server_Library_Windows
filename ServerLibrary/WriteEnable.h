#pragma once
#include "Control_Of_WriteEnable.h"
#include "Global.h"

namespace FLORENCE
{
    class WriteEnable
    {
    public:
        WriteEnable();
        virtual ~WriteEnable();
        void Initialise_Control(
            class Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        void Write_End(
            class Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
            unsigned char* ptr_coreId,
            unsigned char* ptr_MyNumImplementedCores,
            class Global* ptr_Global
        );
        void Write_Start(
            class Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
            unsigned char* ptr_coreId,
            unsigned char* ptr_MyNumImplementedCores,
            class Global* ptr_Global
        );

        class Control_Of_WriteEnable* Get_Control_Of_WriteEnable();

    protected:

    private:
        static class Control_Of_WriteEnable* ptr_Control_Of_WriteEnable;
    };
}