#include "pch.h"
#include "Control_Of_WriteEnable.h"

namespace FLORENCE
{

    unsigned char* Control_Of_WriteEnable::ptr_coreId_For_WritePraise_Index = nullptr;
    int* Control_Of_WriteEnable::ptr_count_CoreId_WriteActive[4] = { nullptr, nullptr, nullptr, nullptr };//NUMBER OF CORES
    int* Control_Of_WriteEnable::ptr_count_CoreId_WriteIdle[4] = { nullptr, nullptr, nullptr, nullptr };//NUMBER OF CORES
    int* Control_Of_WriteEnable::ptr_count_CoreId_WriteWait[4] = { nullptr, nullptr, nullptr, nullptr };//NUMBER OF CORES
    bool Control_Of_WriteEnable::flag_WriteState[4][2] = { {bool(false), bool(false)}, {bool(false), bool(false)}, {bool(false), bool(false)}, {bool(false), bool(false)} };//NUMBER OF CORES
    unsigned char* Control_Of_WriteEnable::ptr_new_coreId_For_WritePraise_Index = nullptr;
    bool Control_Of_WriteEnable::praisingWrite = bool(false);
    unsigned char* Control_Of_WriteEnable::ptr_que_CoreToWrite[4] = { nullptr, nullptr, nullptr, nullptr };//NUMBER OF CORES

    Control_Of_WriteEnable::Control_Of_WriteEnable(
        FLORENCE::Global* ptr_Global,
        unsigned char* ptr_MyNumImplementedCores
    )
    {
        /*
        ptr_coreId_For_WritePraise_Index = new unsigned char(0);
        ptr_count_CoreId_WriteActive[4] = { new int(0), new int(0), new int(0), new int(0) };//NUMBER OF CORES
        ptr_count_CoreId_WriteIdle[4] = { new int(0), new int(0), new int(0), new int(0) };//NUMBER OF CORES
        ptr_count_CoreId_WriteWait[4] = { new int(0), new int(0), new int(0), new int(0) };//NUMBER OF CORES
        */

        flag_WriteState[0][0] = ptr_Global->getConst_Write_IDLE(0);
        flag_WriteState[0][1] = ptr_Global->getConst_Write_IDLE(1);
        flag_WriteState[1][0] = ptr_Global->getConst_Write_IDLE(0);
        flag_WriteState[1][1] = ptr_Global->getConst_Write_IDLE(1);
        flag_WriteState[2][0] = ptr_Global->getConst_Write_IDLE(0);
        flag_WriteState[2][1] = ptr_Global->getConst_Write_IDLE(1);
        flag_WriteState[3][0] = ptr_Global->getConst_Write_IDLE(0);
        flag_WriteState[3][1] = ptr_Global->getConst_Write_IDLE(1);

        //NUMBER OF CORES
        /**
        ptr_new_coreId_For_WritePraise_Index = new unsigned char(1);
        praisingWrite = bool(false);
        ptr_que_CoreToWrite[4] = { new unsigned char(0), new unsigned char(1), new unsigned char(2), new unsigned char(3) };//NUMBER OF CORES
        */
    }

    Control_Of_WriteEnable::~Control_Of_WriteEnable()
    {
        /*
        delete ptr_coreId_For_WritePraise_Index;
        for (int index = 0; index < 4; index++)//NUMBER OF CORES
        {
            delete ptr_count_CoreId_WriteActive[index];
            delete ptr_count_CoreId_WriteIdle[index];
            delete ptr_count_CoreId_WriteWait[index];
            delete ptr_que_CoreToWrite[index];
        }
        delete ptr_new_coreId_For_WritePraise_Index;
        */
    }

    void Control_Of_WriteEnable::writeEnable_Activate(
        unsigned char* ptr_coreId,
        FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
        unsigned char* ptr_MyNumImplementedCores
    )
    {
        for (unsigned char index = 0; index < *ptr_MyNumImplementedCores; index++)
        {
            setFlag_writeState(ptr_coreId, index, ptr_Global->getConst_Write_WRITE(index));
        }
    }

    void Control_Of_WriteEnable::writeEnable_SortQue(
        unsigned char* ptr_MyNumImplementedCores,
        FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
    )
    {
        for (unsigned char index_A = 0; index_A < *ptr_MyNumImplementedCores - 1; index_A++)
        {
            for (unsigned char index_B = index_A + 1; index_B < *ptr_MyNumImplementedCores; index_B++)
            {
                if (getFlag_writeState(get_que_CoreToWrite(&index_A), 0) == ptr_Global->getConst_Write_WRITE(0)
                    && getFlag_writeState(get_que_CoreToWrite(&index_A), 1) == ptr_Global->getConst_Write_WRITE(1))
                {
                    if ((getFlag_writeState(get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_WAIT(0)
                        && getFlag_writeState(get_que_CoreToWrite(&index_B), 1) == ptr_Global->getConst_Write_WAIT(1))
                        || (getFlag_writeState(get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_IDLE(0)
                            && getFlag_writeState(get_que_CoreToWrite(&index_B), 1) == ptr_Global->getConst_Write_IDLE(1)))
                    {
                        writeEnable_ShiftQueValues(&index_A, &index_B);
                    }
                    else if (getFlag_writeState(get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_WRITE(0)
                        && getFlag_writeState(get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_WRITE(1))
                    {
                        if (*get_count_WriteActive(&index_A) > *get_count_WriteActive(&index_B))
                        {
                            writeEnable_ShiftQueValues(&index_A, &index_B);
                        }
                    }
                }
                else if (getFlag_writeState(get_que_CoreToWrite(&index_A), 0) == ptr_Global->getConst_Write_IDLE(0)
                    && getFlag_writeState(get_que_CoreToWrite(&index_A), 1) == ptr_Global->getConst_Write_IDLE(1))
                {
                    if (getFlag_writeState(get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_WAIT(0)
                        && getFlag_writeState(get_que_CoreToWrite(&index_B), 1) == ptr_Global->getConst_Write_WAIT(1))
                    {
                        writeEnable_ShiftQueValues(&index_A, &index_B);
                    }
                    else if (getFlag_writeState(get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_IDLE(0)
                        && getFlag_writeState(get_que_CoreToWrite(&index_B), 1) == ptr_Global->getConst_Write_IDLE(1))
                    {
                        if (*get_count_WriteIdle(&index_A) < *get_count_WriteIdle(&index_B))
                        {
                            writeEnable_ShiftQueValues(&index_A, &index_B);
                        }
                    }
                }
                else if (getFlag_writeState(get_que_CoreToWrite(&index_A), 0) == ptr_Global->getConst_Write_WAIT(0)
                    && getFlag_writeState(get_que_CoreToWrite(&index_A), 1) == ptr_Global->getConst_Write_WAIT(1))
                {
                    if (getFlag_writeState(get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_WAIT(0)
                        && getFlag_writeState(get_que_CoreToWrite(&index_B), 1) == ptr_Global->getConst_Write_WAIT(1))
                    {
                        if (*get_count_WriteWait(&index_A) > *get_count_WriteWait(&index_B))
                        {
                            writeEnable_ShiftQueValues(&index_A, &index_B);
                        }
                    }
                }
            }
        }
    }

    void Control_Of_WriteEnable::writeEnable_Request(
        unsigned char* ptr_coreId,
        unsigned char* ptr_MyNumImplementedCores,
        FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
    )
    {
        while (getFlag_readWrite_Open() == true)
        {
            dynamicStagger(ptr_coreId);
        }
        setFlag_readWrite_Open(true);
        set_coreIdForWritePraiseIndex(*get_new_coreIdForWritePraiseIndex());
        if (*get_coreIdForWritePraiseIndex() == *ptr_coreId)
        {
            for (unsigned char index = 0; index < 2; index++)
            {
                setFlag_writeState(ptr_coreId, index, ptr_Global->getConst_Write_WAIT(index));
            }
            // Function exit.
        }
        else
        {
            set_new_coreIdForWritePraiseIndex(*get_coreIdForWritePraiseIndex() + 1);
            if (*get_new_coreIdForWritePraiseIndex() == *ptr_MyNumImplementedCores)
            {
                set_new_coreIdForWritePraiseIndex(0);
            }
            setFlag_readWrite_Open(false);
            writeEnable_Request(
                ptr_coreId,
                ptr_MyNumImplementedCores,
                ptr_Global

            );
        }
    }

    void Control_Of_WriteEnable::writeQue_Update(
        unsigned char* ptr_MyNumImplementedCores
    )
    {
        for (unsigned char index = 0; index < *ptr_MyNumImplementedCores; index++)
        {
            if (getFlag_writeState(&index, 0) == false)
            {
                if (getFlag_writeState(&index, 1) == false)
                {
                    set_count_WriteActive(&index, 0);
                    set_count_WriteIdle(&index, *get_count_WriteIdle(&index) + 1);
                    set_count_WriteWait(&index, 0);
                }
                else if (getFlag_writeState(&index, 1) == true)
                {
                    set_count_WriteActive(&index, 0);
                    set_count_WriteIdle(&index, 0);
                    set_count_WriteWait(&index, *get_count_WriteWait(&index) + 1);
                }
            }
            else if (getFlag_writeState(&index, 0) == true)
            {
                if (getFlag_writeState(&index, 1) == false)
                {
                    set_count_WriteActive(&index, *get_count_WriteActive(&index) + 1);
                    set_count_WriteIdle(&index, 0);
                    set_count_WriteWait(&index, 0);
                }
            }
        }
    }

    unsigned char* Control_Of_WriteEnable::get_coreIdForWritePraiseIndex()
    {
        return ptr_coreId_For_WritePraise_Index;
    }
    int* Control_Of_WriteEnable::get_count_WriteActive(unsigned char* ptr_coreId)
    {
        return ptr_count_CoreId_WriteActive[*ptr_coreId];
    }
    int* Control_Of_WriteEnable::get_count_WriteIdle(unsigned char* ptr_coreId)
    {
        return ptr_count_CoreId_WriteIdle[*ptr_coreId];
    }
    int* Control_Of_WriteEnable::get_count_WriteWait(unsigned char* ptr_coreId)
    {
        return ptr_count_CoreId_WriteWait[*ptr_coreId];
    }
    unsigned char* Control_Of_WriteEnable::getFlag_CoreId_WriteEnable()
    {
        return ptr_que_CoreToWrite[0];
    }
    unsigned char* Control_Of_WriteEnable::get_new_coreIdForWritePraiseIndex()
    {
        return ptr_new_coreId_For_WritePraise_Index;
    }
    unsigned char* Control_Of_WriteEnable::get_que_CoreToWrite(unsigned char* index)
    {
        return ptr_que_CoreToWrite[*index];
    }

    void Control_Of_WriteEnable::set_count_WriteActive(unsigned char* ptr_coreId, int value)
    {
        ptr_count_CoreId_WriteActive[*ptr_coreId] = &value;
    }
    void Control_Of_WriteEnable::set_count_WriteIdle(unsigned char* ptr_coreId, int value)
    {
        ptr_count_CoreId_WriteIdle[*ptr_coreId] = &value;
    }
    void Control_Of_WriteEnable::set_count_WriteWait(unsigned char* ptr_coreId, int value)
    {
        ptr_count_CoreId_WriteWait[*ptr_coreId] = &value;
    }
    void Control_Of_WriteEnable::setFlag_readWrite_Open(bool value)
    {
        praisingWrite = value;
    }
    void Control_Of_WriteEnable::setFlag_writeState(unsigned char* ptr_coreId, unsigned char index, bool value)
    {
        flag_WriteState[*ptr_coreId][index] = &value;
    }
    void Control_Of_WriteEnable::set_new_coreIdForWritePraiseIndex(unsigned char value)
    {
        ptr_new_coreId_For_WritePraise_Index = &value;
    }
    void Control_Of_WriteEnable::set_que_CoreToWrite(unsigned char* index, unsigned char value)
    {
        ptr_que_CoreToWrite[*index] = &value;
    }

    void Control_Of_WriteEnable::dynamicStagger(
        unsigned char* ptr_coreId
    )
    {
        if (*get_coreIdForWritePraiseIndex() == *ptr_coreId)
        {
            //exit early
        }
        else
        {
            int* ptr_count = new int(0);
            while (*ptr_count < 20)//TODO record till flag change
            {
                ptr_count = ptr_count + 1;
            }
            delete ptr_count;
        }
    }

    void Control_Of_WriteEnable::writeEnable_ShiftQueValues(
        unsigned char* coreId_A,
        unsigned char* coreId_B
    )
    {
        int* ptr_temp_A = new int(0);
        ptr_temp_A = get_count_WriteActive(coreId_A);
        set_count_WriteActive(coreId_A, *get_count_WriteActive(coreId_B));
        set_count_WriteActive(coreId_B, *ptr_temp_A);

        ptr_temp_A = get_count_WriteIdle(coreId_A);
        set_count_WriteIdle(coreId_A, *get_count_WriteIdle(coreId_B));
        set_count_WriteIdle(coreId_B, *ptr_temp_A);

        ptr_temp_A = get_count_WriteWait(coreId_A);
        set_count_WriteWait(coreId_A, *get_count_WriteWait(coreId_B));
        set_count_WriteWait(coreId_B, *ptr_temp_A);
        delete ptr_temp_A;

        unsigned char* ptr_temp_B = new unsigned char(0);
        ptr_temp_B = get_que_CoreToWrite(coreId_A);
        set_que_CoreToWrite(coreId_A, *get_que_CoreToWrite(coreId_B));
        set_que_CoreToWrite(coreId_B, *ptr_temp_B);
        delete ptr_temp_B;
    }

    bool Control_Of_WriteEnable::getFlag_readWrite_Open()
    {
        return praisingWrite;
    }

    bool Control_Of_WriteEnable::getFlag_writeState(unsigned char* ptr_coreId, unsigned char index)
    {
        return flag_WriteState[*ptr_coreId][index];
    }

    void Control_Of_WriteEnable::set_coreIdForWritePraiseIndex(unsigned char value)
    {
        ptr_coreId_For_WritePraise_Index = &value;
    }
}