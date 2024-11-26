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
            Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        void Write_End(
            Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
            unsigned char* ptr_coreId,
            unsigned char* ptr_MyNumImplementedCores,
            Global* ptr_Global
        );
        void Write_Start(
            Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
            unsigned char* ptr_coreId,
            unsigned char* ptr_MyNumImplementedCores,
            Global* ptr_Global
        );

        Control_Of_WriteEnable* Get_Control_Of_WriteEnable();

    protected:

    private:
        Control_Of_WriteEnable* ptr_Control_Of_WriteEnable;
    };
}