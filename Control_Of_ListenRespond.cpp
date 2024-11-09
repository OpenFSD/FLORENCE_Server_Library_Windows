#include "pch.h"
#include "Control_Of_ListenRespond.h"

namespace FLORENCE
{
    bool flag_IO_ThreadState = false;

    Control_Of_ListenRespond::Control_Of_ListenRespond()
    {
        this->flag_IO_ThreadState = new bool(true);
    }
    Control_Of_ListenRespond::~Control_Of_ListenRespond()
    {

    }

    bool Control_Of_ListenRespond::GetFlag_IO_ThreadState()
    {
        return this->flag_IO_ThreadState;
    }

    void Control_Of_ListenRespond::SetFlag_IO_ThreadState(bool value)
    {
        this->flag_IO_ThreadState = value;
    }
}