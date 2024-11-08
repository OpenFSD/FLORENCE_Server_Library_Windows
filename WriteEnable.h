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
        void initialise_Control(
            Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        void write_End(
            class Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
            unsigned char* ptr_coreId,
            unsigned char* ptr_MyNumImplementedCores,
            class Global* ptr_Global
        );
        void write_Start(
            class Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
            unsigned char* ptr_coreId,
            unsigned char* ptr_MyNumImplementedCores,
            class Global* ptr_Global
        );

        Control_Of_WriteEnable* get_Control_Of_WriteEnable();

    protected:

    private:
        class Control_Of_WriteEnable* ptr_Control_Of_WriteEnable;
    };
}