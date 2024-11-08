#pragma once
#include <array>
#include "Global.h"

namespace FLORENCE
{
    class Control_Of_LaunchConcurrency
    {
    public:
        Control_Of_LaunchConcurrency(
            FLORENCE::Global* ptr_Global,
            unsigned char* ptr_NumImplementedCores
        );
        virtual ~Control_Of_LaunchConcurrency();

        void launchEnable_Activate(
            FLORENCE::Global* ptr_Global
        );
        void launchEnable_Request(
            unsigned char* concurrent_CoreId,
            FLORENCE::Global* ptr_Global
        );
        void launchEnable_SortQue(
            FLORENCE::Global* ptr_Global,
            unsigned char* ptr_NumImplementedCores
        );
        void launchQue_Update(
            unsigned char* ptr_NumImplementedCores
        );

        unsigned char* get_concurrent_CoreId_Index();
        unsigned char* get_coreId_To_Launch();
        bool getFlag_ConcurrentCoreState(unsigned char* concurrent_CoreId);
        bool getFlag_PraisingLaunch();
        unsigned char* get_new_concurrent_CoreId_Index();

        void set_concurrent_CoreId_Index(unsigned char index);
        void setFlag_ConcurrentCoreState(unsigned char* concurrent_CoreId, bool value);
        void setFlag_PraisingLaunch(bool value);
        void set_new_concurrent_CoreId_Index(unsigned char index);


    protected:

    private:
        void dynamicStagger(
            unsigned char* ptr_coreId
        );
        void launchEnable_ShiftQueValues(
            unsigned char* concurrent_CoreId_A,
            unsigned char* concurrent_CoreId_B
        );

        int* get_count_LaunchActive_For(unsigned char* concurrent_CoreId);
        int* get_count_LaunchIdle_For(unsigned char* concurrent_CoreId);
        unsigned char* getFlag_CoreId_Of_CoreToLaunch();
        unsigned char* get_que_CoreToLaunch(unsigned char* index);

        void set_count_LaunchActive_For(unsigned char* concurrent_CoreId, int value);
        void set_count_LaunchIdle_For(unsigned char* concurrent_CoreId, int value);
        void set_que_CoreToLaunch(unsigned char* concurrent_CoreId, unsigned char value);

        static bool flag_praisingLaunch;
        static bool flag_ConcurrentCoreState[3];//NUMBER OF CONCURRENT CORES
        static unsigned char* ptr_concurrent_CoreId_Index;
        static int* ptr_count_LaunchActive_For[3];//NUMBER OF CONCURRENT CORES
        static int* ptr_count_LaunchIdle_For[3];//NUMBER OF CONCURRENT CORES
        static unsigned char* ptr_new_concurrent_CoreId_Index;
        static unsigned char* ptr_que_CoreToLaunch[3];//NUMBER OF CONCURRENT CORES
    };
}