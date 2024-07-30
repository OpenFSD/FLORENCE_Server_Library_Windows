#include "WriteEnable.h"

class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable = nullptr;

FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable::WriteEnable(
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global_pass,
    unsigned char* ptr_MyNumImplementedCores
)
{
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable = new class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable(ptr_Global_pass, ptr_MyNumImplementedCores);
}

FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable::~WriteEnable()
{
    delete ptr_Control_Of_WriteEnable;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable::write_End(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
    unsigned char* ptr_coreId,
    unsigned char* ptr_MyNumImplementedCores,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
)
{
    for (unsigned char index = 0; index < 2; index++)
    {
        ptr_Control_Of_WriteEnable->setFlag_writeState(ptr_coreId, index, ptr_Global->getConst_Write_IDLE(index));
    }
    ptr_Control_Of_WriteEnable->set_new_coreIdForWritePraiseIndex(*ptr_Control_Of_WriteEnable->get_coreIdForWritePraiseIndex() + 1);
    if (int(*ptr_Control_Of_WriteEnable->get_new_coreIdForWritePraiseIndex()) == 3)
    {
        ptr_Control_Of_WriteEnable->set_new_coreIdForWritePraiseIndex(0);
    }
    ptr_Control_Of_WriteEnable->writeQue_Update(
        ptr_Control_Of_WriteEnable,
        ptr_MyNumImplementedCores
    );
    ptr_Control_Of_WriteEnable->writeEnable_SortQue(
        ptr_Control_Of_WriteEnable,
        ptr_MyNumImplementedCores,
        ptr_Global
    );
    ptr_Control_Of_WriteEnable->setFlag_readWrite_Open(false);
}
void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable::write_Start(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
    unsigned char* ptr_coreId,
    unsigned char* ptr_MyNumImplementedCores,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* ptr_WriteEnable
)
{
    ptr_Control_Of_WriteEnable->writeEnable_Request(
        ptr_Control_Of_WriteEnable,
        ptr_coreId,
        ptr_MyNumImplementedCores,
        ptr_Global
    );
    ptr_Control_Of_WriteEnable->writeQue_Update(
        ptr_Control_Of_WriteEnable,
        ptr_MyNumImplementedCores
    );
    ptr_Control_Of_WriteEnable->writeEnable_SortQue(
        ptr_Control_Of_WriteEnable,
        ptr_MyNumImplementedCores,
        ptr_Global
    );
    ptr_Control_Of_WriteEnable->writeEnable_Activate(
        ptr_Control_Of_WriteEnable,
        ptr_coreId,
        ptr_Global,
        ptr_MyNumImplementedCores
    );
}

class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable::get_Control_Of_WriteEnable()
{
    return ptr_Control_Of_WriteEnable;
}