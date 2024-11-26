#pragma once
#include <array>

namespace FLORENCE
{
    class Global
    {
    public:
        Global();
        ~Global();
        bool GetConst_Core_IDLE();
        bool GetConst_Core_ACTIVE();
        unsigned char* Get_NumCores();
        bool GetConst_Write_IDLE(unsigned char index);
        bool GetConst_Write_WAIT(unsigned char index);
        bool GetConst_Write_WRITE(unsigned char index);

    protected:

    private:
        static bool flag_write_IDLE[2];
        static bool flag_write_WAIT[2];
        static bool flag_write_WRITE[2];
        static bool flag_core_IDLE;
        static bool flag_core_ACTIVE;
        static unsigned char* ptr_num_Implemented_Cores;
    };
}
