#pragma once
#include "Global.h"

namespace FLORENCE
{
    class Control_Of_WriteEnable
    {
    public:
        Control_Of_WriteEnable(
            class FLORENCE::Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        ~Control_Of_WriteEnable();
        void WriteEnable_Activate(
            unsigned char* ptr_coreId,
            class FLORENCE::Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        void WriteEnable_SortQue(
            unsigned char* ptr_MyNumImplementedCores,
            class FLORENCE::Global* ptr_Global
        );
        void WriteEnable_Request(
            unsigned char* ptr_coreId,
            unsigned char* ptr_MyNumImplementedCores,
            class FLORENCE::Global* ptr_Global
        );
        void WriteQue_Update(
            unsigned char* ptr_MyNumImplementedCores
        );

        unsigned char* Get_coreIdForWritePraiseIndex();
        int* Get_count_WriteActive(unsigned char* ptr_coreId);
        int* Get_count_WriteIdle(unsigned char* ptr_coreId);
        int* Get_count_WriteWait(unsigned char* ptr_coreId);
        unsigned char* GetFlag_CoreId_WriteEnable();
        unsigned char* Get_new_coreIdForWritePraiseIndex();
        unsigned char* Get_que_CoreToWrite(unsigned char* ptr_coreId);

        void Set_count_WriteActive(unsigned char* ptr_coreId, int value);
        void Set_count_WriteIdle(unsigned char* ptr_coreId, int value);
        void Set_count_WriteWait(unsigned char* ptr_coreId, int value);
        void SetFlag_readWrite_Open(bool value);
        void SetFlag_writeState(unsigned char* ptr_coreId, unsigned char index, bool value);
        void Set_new_coreIdForWritePraiseIndex(unsigned char value);
        void Set_que_CoreToWrite(unsigned char* index, unsigned char value);

    protected:

    private:
        void DynamicStagger(
            unsigned char* ptr_coreId
        );
        void WriteEnable_ShiftQueValues(
            unsigned char* concurrent_CoreId_A,
            unsigned char* concurrent_CoreId_B
        );

        bool GetFlag_readWrite_Open();
        bool GetFlag_writeState(unsigned char* ptr_coreId, unsigned char index);

        void Set_coreIdForWritePraiseIndex(unsigned char value);

        static unsigned char* ptr_coreId_For_WritePraise_Index;
        static int* ptr_count_CoreId_WriteActive[4];//NUMBER OF CORES
        static int* ptr_count_CoreId_WriteIdle[4];//NUMBER OF CORES
        static int* ptr_count_CoreId_WriteWait[4];//NUMBER OF CORES
        static bool flag_WriteState[4][2];//NUMBER OF CORES
        static unsigned char* ptr_new_coreId_For_WritePraise_Index;
        static bool praisingWrite;
        static unsigned char* ptr_que_CoreToWrite[4];//NUMBER OF CORES
    };
}