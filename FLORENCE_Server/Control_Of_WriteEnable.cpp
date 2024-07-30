#include "Control_Of_WriteEnable.h"

unsigned char* ptr_coreId_For_WritePraise_Index = nullptr;
int* ptr_count_CoreId_WriteActive[4] = { nullptr, nullptr, nullptr, nullptr };//NUMBER OF CORES
int* ptr_count_CoreId_WriteIdle[4] = { nullptr, nullptr, nullptr, nullptr };//NUMBER OF CORES
int* ptr_count_CoreId_WriteWait[4] = { nullptr, nullptr, nullptr, nullptr };//NUMBER OF CORES
bool ptr_flag_WriteState[4][2] = { {bool(false), bool(false)}, {bool(false), bool(false)}, {bool(false), bool(false)}, {bool(false), bool(false)} };//NUMBER OF CORES
unsigned char* ptr_new_coreId_For_WritePraise_Index = nullptr;
bool praisingWrite = bool(false);
unsigned char* ptr_que_CoreToWrite[4] = { nullptr, nullptr, nullptr, nullptr };//NUMBER OF CORES

FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::Control_Of_WriteEnable(
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
    unsigned char* ptr_MyNumImplementedCores
)
{
    unsigned char* ptr_coreId_For_WritePraise_Index = new unsigned char(0);
    int* ptr_count_CoreId_WriteActive[4] = { new int(0), new int(0), new int(0), new int(0) };//NUMBER OF CORES
    int* ptr_count_CoreId_WriteIdle[4] = { new int(0), new int(0), new int(0), new int(0) };//NUMBER OF CORES
    int* ptr_count_CoreId_WriteWait[4] = { new int(0), new int(0), new int(0), new int(0) };//NUMBER OF CORES

    bool flag_WriteState[4][2] = {
        {ptr_Global->getConst_Write_IDLE(0), ptr_Global->getConst_Write_IDLE(1)},
        {ptr_Global->getConst_Write_IDLE(0), ptr_Global->getConst_Write_IDLE(1)},
        {ptr_Global->getConst_Write_IDLE(0), ptr_Global->getConst_Write_IDLE(1)},
        {ptr_Global->getConst_Write_IDLE(0), ptr_Global->getConst_Write_IDLE(1)}
    };//NUMBER OF CORES
    unsigned char* ptr_new_coreId_For_WritePraise_Index = new unsigned char(1);
    bool praisingWrite = new bool(false);
    unsigned char* ptr_que_CoreToWrite[4] = { new unsigned char(0), new unsigned char(1), new unsigned char(2), new unsigned char(3) };//NUMBER OF CORES
}
FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::~Control_Of_WriteEnable()
{
    delete ptr_coreId_For_WritePraise_Index;
    for (int index = 0; index < 4; index++)//NUMBER OF CORES
    {
        delete ptr_count_CoreId_WriteActive[index];
        delete ptr_count_CoreId_WriteIdle[index];
        delete ptr_count_CoreId_WriteWait[index];
        delete ptr_que_CoreToWrite[index];
    }
    delete ptr_new_coreId_For_WritePraise_Index;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::writeEnable_Activate(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
    unsigned char* ptr_coreId,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
    unsigned char* ptr_MyNumImplementedCores
)
{
    for (unsigned char index = 0; index < *ptr_MyNumImplementedCores; index++)
    {
        ptr_Control_Of_WriteEnable->setFlag_writeState(ptr_coreId, index, ptr_Global->getConst_Write_WRITE(index));
    }
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::writeEnable_SortQue(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
    unsigned char* ptr_MyNumImplementedCores,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
)
{
    for (unsigned char index_A = 0; index_A < *ptr_MyNumImplementedCores - 1; index_A++)
    {
        for (unsigned char index_B = index_A + 1; index_B < *ptr_MyNumImplementedCores; index_B++)
        {
            if (ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_A), 0) == ptr_Global->getConst_Write_WRITE(0)
                && ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_A), 1) == ptr_Global->getConst_Write_WRITE(1))
            {
                if ((ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_WAIT(0)
                    && ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_B), 1) == ptr_Global->getConst_Write_WAIT(1))
                    || (ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_IDLE(0)
                        && ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_B), 1) == ptr_Global->getConst_Write_IDLE(1)))
                {
                    ptr_Control_Of_WriteEnable->writeEnable_ShiftQueValues(ptr_Control_Of_WriteEnable, &index_A, &index_B);
                }
                else if (ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_WRITE(0)
                    && ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_WRITE(1))
                {
                    if (*ptr_Control_Of_WriteEnable->get_count_WriteActive(&index_A) > *ptr_Control_Of_WriteEnable->get_count_WriteActive(&index_B))
                    {
                        ptr_Control_Of_WriteEnable->writeEnable_ShiftQueValues(ptr_Control_Of_WriteEnable, &index_A, &index_B);
                    }
                }
            }
            else if (ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_A), 0) == ptr_Global->getConst_Write_IDLE(0)
                && ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_A), 1) == ptr_Global->getConst_Write_IDLE(1))
            {
                if (ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_WAIT(0)
                    && ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_B), 1) == ptr_Global->getConst_Write_WAIT(1))
                {
                    ptr_Control_Of_WriteEnable->writeEnable_ShiftQueValues(ptr_Control_Of_WriteEnable, &index_A, &index_B);
                }
                else if (ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_IDLE(0)
                    && ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_B), 1) == ptr_Global->getConst_Write_IDLE(1))
                {
                    if (*ptr_Control_Of_WriteEnable->get_count_WriteIdle(&index_A) < *ptr_Control_Of_WriteEnable->get_count_WriteIdle(&index_B))
                    {
                        ptr_Control_Of_WriteEnable->writeEnable_ShiftQueValues(ptr_Control_Of_WriteEnable, &index_A, &index_B);
                    }
                }
            }
            else if (ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_A), 0) == ptr_Global->getConst_Write_WAIT(0)
                && ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_A), 1) == ptr_Global->getConst_Write_WAIT(1))
            {
                if (ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_B), 0) == ptr_Global->getConst_Write_WAIT(0)
                    && ptr_Control_Of_WriteEnable->getFlag_writeState(ptr_Control_Of_WriteEnable->get_que_CoreToWrite(&index_B), 1) == ptr_Global->getConst_Write_WAIT(1))
                {
                    if (*ptr_Control_Of_WriteEnable->get_count_WriteWait(&index_A) > *ptr_Control_Of_WriteEnable->get_count_WriteWait(&index_B))
                    {
                        ptr_Control_Of_WriteEnable->writeEnable_ShiftQueValues(ptr_Control_Of_WriteEnable, &index_A, &index_B);
                    }
                }
            }
        }
    }
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::writeEnable_Request(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
    unsigned char* ptr_coreId,
    unsigned char* ptr_MyNumImplementedCores,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
)
{
    while (ptr_Control_Of_WriteEnable->getFlag_readWrite_Open() == true)
    {
        ptr_Control_Of_WriteEnable->dynamicStagger(ptr_Control_Of_WriteEnable, ptr_coreId);
    }
    ptr_Control_Of_WriteEnable->setFlag_readWrite_Open(true);
    ptr_Control_Of_WriteEnable->set_coreIdForWritePraiseIndex(*ptr_Control_Of_WriteEnable->get_new_coreIdForWritePraiseIndex());
    if (*ptr_Control_Of_WriteEnable->get_coreIdForWritePraiseIndex() == *ptr_coreId)
    {
        for (unsigned char index = 0; index < 2; index++)
        {
            ptr_Control_Of_WriteEnable->setFlag_writeState(ptr_coreId, index, ptr_Global->getConst_Write_WAIT(index));
        }
        // Function exit.
    }
    else
    {
        ptr_Control_Of_WriteEnable->set_new_coreIdForWritePraiseIndex(*ptr_Control_Of_WriteEnable->get_coreIdForWritePraiseIndex() + 1);
        if (*ptr_Control_Of_WriteEnable->get_new_coreIdForWritePraiseIndex() == *ptr_MyNumImplementedCores)
        {
            ptr_Control_Of_WriteEnable->set_new_coreIdForWritePraiseIndex(0);
        }
        ptr_Control_Of_WriteEnable->setFlag_readWrite_Open(false);
        ptr_Control_Of_WriteEnable->writeEnable_Request(
            ptr_Control_Of_WriteEnable,
            ptr_coreId,
            ptr_MyNumImplementedCores,
            ptr_Global

        );
    }
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::writeQue_Update(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
    unsigned char* ptr_MyNumImplementedCores
)
{
    for (unsigned char index = 0; index < *ptr_MyNumImplementedCores; index++)
    {
        if (ptr_Control_Of_WriteEnable->getFlag_writeState(&index, 0) == false)
        {
            if (ptr_Control_Of_WriteEnable->getFlag_writeState(&index, 1) == false)
            {
                ptr_Control_Of_WriteEnable->set_count_WriteActive(&index, 0);
                ptr_Control_Of_WriteEnable->set_count_WriteIdle(&index, *ptr_Control_Of_WriteEnable->get_count_WriteIdle(&index) + 1);
                ptr_Control_Of_WriteEnable->set_count_WriteWait(&index, 0);
            }
            else if (ptr_Control_Of_WriteEnable->getFlag_writeState(&index, 1) == true)
            {
                ptr_Control_Of_WriteEnable->set_count_WriteActive(&index, 0);
                ptr_Control_Of_WriteEnable->set_count_WriteIdle(&index, 0);
                ptr_Control_Of_WriteEnable->set_count_WriteWait(&index, *ptr_Control_Of_WriteEnable->get_count_WriteWait(&index) + 1);
            }
        }
        else if (ptr_Control_Of_WriteEnable->getFlag_writeState(&index, 0) == true)
        {
            if (ptr_Control_Of_WriteEnable->getFlag_writeState(&index, 1) == false)
            {
                ptr_Control_Of_WriteEnable->set_count_WriteActive(&index, *ptr_Control_Of_WriteEnable->get_count_WriteActive(&index) + 1);
                ptr_Control_Of_WriteEnable->set_count_WriteIdle(&index, 0);
                ptr_Control_Of_WriteEnable->set_count_WriteWait(&index, 0);
            }
        }
    }
}

unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::get_coreIdForWritePraiseIndex()
{
    return ptr_coreId_For_WritePraise_Index;
}
int* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::get_count_WriteActive(unsigned char* ptr_coreId)
{
    return ptr_count_CoreId_WriteActive[*ptr_coreId];
}
int* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::get_count_WriteIdle(unsigned char* ptr_coreId)
{
    return ptr_count_CoreId_WriteIdle[*ptr_coreId];
}
int* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::get_count_WriteWait(unsigned char* ptr_coreId)
{
    return ptr_count_CoreId_WriteWait[*ptr_coreId];
}
unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::getFlag_CoreId_WriteEnable()
{
    return ptr_que_CoreToWrite[0];
}
unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::get_new_coreIdForWritePraiseIndex()
{
    return ptr_new_coreId_For_WritePraise_Index;
}
unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::get_que_CoreToWrite(unsigned char* index)
{
    return ptr_que_CoreToWrite[*index];
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::set_count_WriteActive(unsigned char* ptr_coreId, int value)
{
    ptr_count_CoreId_WriteActive[*ptr_coreId] = &value;
}
void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::set_count_WriteIdle(unsigned char* ptr_coreId, int value)
{
    ptr_count_CoreId_WriteIdle[*ptr_coreId] = &value;
}
void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::set_count_WriteWait(unsigned char* ptr_coreId, int value)
{
    ptr_count_CoreId_WriteWait[*ptr_coreId] = &value;
}
void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::setFlag_readWrite_Open(bool value)
{
    praisingWrite = value;
}
void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::setFlag_writeState(unsigned char* ptr_coreId, unsigned char index, bool value)
{
    ptr_flag_WriteState[*ptr_coreId][index] = &value;
}
void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::set_new_coreIdForWritePraiseIndex(unsigned char value)
{
    ptr_new_coreId_For_WritePraise_Index = &value;
}
void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::set_que_CoreToWrite(unsigned char* index, unsigned char value)
{
    ptr_que_CoreToWrite[*index] = &value;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::dynamicStagger(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
    unsigned char* ptr_coreId
)
{
    if (*ptr_Control_Of_WriteEnable->get_coreIdForWritePraiseIndex() == *ptr_coreId)
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

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::writeEnable_ShiftQueValues(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
    unsigned char* coreId_A,
    unsigned char* coreId_B
)
{
    int* ptr_temp_A = new int(0);
    ptr_temp_A = ptr_Control_Of_WriteEnable->get_count_WriteActive(coreId_A);
    ptr_Control_Of_WriteEnable->set_count_WriteActive(coreId_A, *ptr_Control_Of_WriteEnable->get_count_WriteActive(coreId_B));
    ptr_Control_Of_WriteEnable->set_count_WriteActive(coreId_B, *ptr_temp_A);

    ptr_temp_A = ptr_Control_Of_WriteEnable->get_count_WriteIdle(coreId_A);
    ptr_Control_Of_WriteEnable->set_count_WriteIdle(coreId_A, *ptr_Control_Of_WriteEnable->get_count_WriteIdle(coreId_B));
    ptr_Control_Of_WriteEnable->set_count_WriteIdle(coreId_B, *ptr_temp_A);

    ptr_temp_A = ptr_Control_Of_WriteEnable->get_count_WriteWait(coreId_A);
    ptr_Control_Of_WriteEnable->set_count_WriteWait(coreId_A, *ptr_Control_Of_WriteEnable->get_count_WriteWait(coreId_B));
    ptr_Control_Of_WriteEnable->set_count_WriteWait(coreId_B, *ptr_temp_A);
    delete ptr_temp_A;

    unsigned char* ptr_temp_B = new unsigned char(0);
    ptr_temp_B = ptr_Control_Of_WriteEnable->get_que_CoreToWrite(coreId_A);
    ptr_Control_Of_WriteEnable->set_que_CoreToWrite(coreId_A, *ptr_Control_Of_WriteEnable->get_que_CoreToWrite(coreId_B));
    ptr_Control_Of_WriteEnable->set_que_CoreToWrite(coreId_B, *ptr_temp_B);
    delete ptr_temp_B;
}

bool FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::getFlag_readWrite_Open()
{
    return praisingWrite;
}

bool FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::getFlag_writeState(unsigned char* ptr_coreId, unsigned char index)
{
    return flag_WriteState[*ptr_coreId][index];
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable::set_coreIdForWritePraiseIndex(unsigned char value)
{
    ptr_coreId_For_WritePraise_Index = &value;
}