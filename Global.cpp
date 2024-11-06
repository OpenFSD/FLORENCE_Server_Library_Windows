#include "pch.h"
#include "Global.h"
#include <cstddef>

namespace FLORENCE
{
    bool flag_core_ACTIVE = NULL;
    bool flag_core_IDLE = NULL;
    bool flag_write_IDLE[2] = { NULL, NULL };
    bool flag_write_WAIT[2] = { NULL, NULL };
    bool flag_write_WRITE[2] = { NULL, NULL };
    unsigned char num_Implemented_Cores = NULL;

    Global::Global()
    {
        bool false_core_ACTIVE = new bool(true);
        bool false_core_IDLE = new bool(false);
        bool false_write_IDLE[2] = { bool(false), bool(false) };
        bool false_write_WAIT[2] = { bool(false), bool(true) };
        bool false_write_WRITE[2] = { bool(true), bool(false) };
        unsigned char num_Implemented_Cores = unsigned char(4);//NUMBER OF CORES
    }

    Global::~Global()
    {
        delete ptr_num_Implemented_Cores;
    }

    bool Global::getConst_Core_ACTIVE()
    {
        return flag_core_ACTIVE;
    }
    bool Global::getConst_Core_IDLE()
    {
        return flag_core_IDLE;
    }
    unsigned char Global::get_NumCores()
    {
        return num_Implemented_Cores;
    }
    bool Global::getConst_Write_IDLE(unsigned char index)
    {
        return flag_write_IDLE[index];
    }
    bool Global::getConst_Write_WAIT(unsigned char index)
    {
        return flag_write_WAIT[index];
    }
    bool Global::getConst_Write_WRITE(unsigned char index)
    {
        return flag_write_WRITE[index];
    }
}