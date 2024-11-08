#include "pch.h"
#include "Control_Of_ListenRespond.h"

namespace FLORENCE
{
    bool Control_Of_ListenRespond::flag_IO_ThreadState = false;

    Control_Of_ListenRespond::Control_Of_ListenRespond()
    {
        this->flag_IO_ThreadState = new bool(true);
    }
    Control_Of_ListenRespond::~Control_Of_ListenRespond()
    {

    }

    bool Control_Of_ListenRespond::getFlag_IO_ThreadState()
    {
        return this->flag_IO_ThreadState;
    }

    void Control_Of_ListenRespond::setFlag_IO_ThreadState(bool value)
    {
        this->flag_IO_ThreadState = value;
    }
}