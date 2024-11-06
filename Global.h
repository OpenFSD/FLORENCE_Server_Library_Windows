#pragma once
#include <array>

namespace FLORENCE
{
    class Global
    {
    public:
        Global();
        ~Global();
        bool getConst_Core_IDLE();
        bool getConst_Core_ACTIVE();
        unsigned char get_NumCores();
        bool getConst_Write_IDLE(unsigned char index);
        bool getConst_Write_WAIT(unsigned char index);
        bool getConst_Write_WRITE(unsigned char index);

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
