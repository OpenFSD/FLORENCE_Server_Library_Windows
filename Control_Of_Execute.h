#pragma once
#include <array>

namespace FLORENCE
{
    class Control_Of_Execute
    {
    public:
        Control_Of_Execute(unsigned char* ptr_MyNumImplementedCores);
        virtual ~Control_Of_Execute();
        bool getFlag_SystemInitialised(unsigned char* ptr_MyNumImplementedCores);
        bool getFlag_ThreadInitialised(unsigned char coreId);

        void setConditionCodeOfThisThreadedCore(unsigned char coreId);

    protected:

    private:
        void setFlag_ThreadInitialised(unsigned char coreId);

        static bool flag_SystemInitialised;
        static bool flag_ThreadInitialised[4];//NUMBER OF CORES
    };
}