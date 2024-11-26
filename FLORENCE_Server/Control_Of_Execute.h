#pragma once
#include <array>

namespace FLORENCE
{
    class Control_Of_Execute
    {
    public:
        Control_Of_Execute(unsigned char* ptr_MyNumImplementedCores);
        virtual ~Control_Of_Execute();
        bool GetFlag_SystemInitialised(unsigned char* ptr_MyNumImplementedCores);
        bool GetFlag_ThreadInitialised(unsigned char coreId);

        void SetConditionCodeOfThisThreadedCore(unsigned char coreId);

    protected:

    private:
        void SetFlag_ThreadInitialised(unsigned char coreId);

        static bool flag_SystemInitialised;
        static bool flag_ThreadInitialised[4];//NUMBER OF CORES
    };
}