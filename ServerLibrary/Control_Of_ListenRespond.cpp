#include "Control_Of_ListenRespond.h"

namespace FLORENCE
{
    bool Control_Of_ListenRespond::flag_IO_ThreadState = false;

    Control_Of_ListenRespond::Control_Of_ListenRespond()
    {
        flag_IO_ThreadState = new bool(true);
    }
    Control_Of_ListenRespond::~Control_Of_ListenRespond()
    {

    }

    bool Control_Of_ListenRespond::GetFlag_IO_ThreadState()
    {
        return flag_IO_ThreadState;
    }

    void Control_Of_ListenRespond::SetFlag_IO_ThreadState(bool value)
    {
        flag_IO_ThreadState = value;
    }
}