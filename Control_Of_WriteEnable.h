#pragma once
#include "Global.h"

namespace FLORENCE
{
    class Control_Of_WriteEnable
    {
    public:
        Control_Of_WriteEnable(
            FLORENCE::Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        ~Control_Of_WriteEnable();
        void writeEnable_Activate(
            unsigned char* ptr_coreId,
            FLORENCE::Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        void writeEnable_SortQue(
            unsigned char* ptr_MyNumImplementedCores,
            FLORENCE::Global* ptr_Global
        );
        void writeEnable_Request(
            unsigned char* ptr_coreId,
            unsigned char* ptr_MyNumImplementedCores,
            FLORENCE::Global* ptr_Global
        );
        void writeQue_Update(
            unsigned char* ptr_MyNumImplementedCores
        );

        unsigned char* get_coreIdForWritePraiseIndex();
        int* get_count_WriteActive(unsigned char* ptr_coreId);
        int* get_count_WriteIdle(unsigned char* ptr_coreId);
        int* get_count_WriteWait(unsigned char* ptr_coreId);
        unsigned char* getFlag_CoreId_WriteEnable();
        unsigned char* get_new_coreIdForWritePraiseIndex();
        unsigned char* get_que_CoreToWrite(unsigned char* ptr_coreId);

        void set_count_WriteActive(unsigned char* ptr_coreId, int value);
        void set_count_WriteIdle(unsigned char* ptr_coreId, int value);
        void set_count_WriteWait(unsigned char* ptr_coreId, int value);
        void setFlag_readWrite_Open(bool value);
        void setFlag_writeState(unsigned char* ptr_coreId, unsigned char index, bool value);
        void set_new_coreIdForWritePraiseIndex(unsigned char value);
        void set_que_CoreToWrite(unsigned char* index, unsigned char value);

    protected:

    private:
        void dynamicStagger(
            unsigned char* ptr_coreId
        );
        void writeEnable_ShiftQueValues(
            unsigned char* concurrent_CoreId_A,
            unsigned char* concurrent_CoreId_B
        );

        bool getFlag_readWrite_Open();
        bool getFlag_writeState(unsigned char* ptr_coreId, unsigned char index);

        void set_coreIdForWritePraiseIndex(unsigned char value);

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