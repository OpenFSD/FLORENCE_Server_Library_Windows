#pragma once
#include <array>
#include "Global.h"

namespace FLORENCE
{
    class Control_Of_LaunchConcurrency
    {
    public:
        Control_Of_LaunchConcurrency(
            class FLORENCE::Global* ptr_Global,
            unsigned char* ptr_NumImplementedCores
        );
        virtual ~Control_Of_LaunchConcurrency();

        void LaunchEnable_Activate(
            class FLORENCE::Global* ptr_Global
        );
        void LaunchEnable_Request(
            unsigned char* concurrent_CoreId,
            class FLORENCE::Global* ptr_Global
        );
        void LaunchEnable_SortQue(
            class FLORENCE::Global* ptr_Global,
            unsigned char* ptr_NumImplementedCores
        );
        void LaunchQue_Update(
            unsigned char* ptr_NumImplementedCores
        );

        unsigned char* Get_concurrent_CoreId_Index();
        unsigned char* Get_coreId_To_Launch();
        bool GetFlag_ConcurrentCoreState(unsigned char* concurrent_CoreId);
        bool GetFlag_PraisingLaunch();
        unsigned char* Get_new_concurrent_CoreId_Index();

        void Set_concurrent_CoreId_Index(unsigned char index);
        void SetFlag_ConcurrentCoreState(unsigned char* concurrent_CoreId, bool value);
        void SetFlag_PraisingLaunch(bool value);
        void Set_new_concurrent_CoreId_Index(unsigned char index);


    protected:

    private:
        void DynamicStagger(
            unsigned char* ptr_coreId
        );
        void LaunchEnable_ShiftQueValues(
            unsigned char* concurrent_CoreId_A,
            unsigned char* concurrent_CoreId_B
        );

        int* Get_count_LaunchActive_For(unsigned char* concurrent_CoreId);
        int* Get_count_LaunchIdle_For(unsigned char* concurrent_CoreId);
        unsigned char* GetFlag_CoreId_Of_CoreToLaunch();
        unsigned char* Get_que_CoreToLaunch(unsigned char* index);

        void Set_count_LaunchActive_For(unsigned char* concurrent_CoreId, int value);
        void Set_count_LaunchIdle_For(unsigned char* concurrent_CoreId, int value);
        void Set_que_CoreToLaunch(unsigned char* concurrent_CoreId, unsigned char value);

        static bool flag_praisingLaunch;
        static bool flag_ConcurrentCoreState[3];//NUMBER OF CONCURRENT CORES
        static unsigned char* ptr_concurrent_CoreId_Index;
        static int* ptr_count_LaunchActive_For[3];//NUMBER OF CONCURRENT CORES
        static int* ptr_count_LaunchIdle_For[3];//NUMBER OF CONCURRENT CORES
        static unsigned char* ptr_new_concurrent_CoreId_Index;
        static unsigned char* ptr_que_CoreToLaunch[3];//NUMBER OF CONCURRENT CORES
    };
}