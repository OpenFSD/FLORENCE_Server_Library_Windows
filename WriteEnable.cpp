#include "pch.h"
#include "WriteEnable.h"

namespace FLORENCE
{
    class Control_Of_WriteEnable* ptr_Control_Of_WriteEnable = NULL;

    WriteEnable::WriteEnable()
    {

    }

    WriteEnable::~WriteEnable()
    {
        delete this->ptr_Control_Of_WriteEnable;
    }

    void WriteEnable::initialise_Control(
        class FLORENCE::Global* ptr_Global,
        unsigned char* ptr_MyNumImplementedCores
    )
    {
        this->ptr_Control_Of_WriteEnable = new Control_Of_WriteEnable(ptr_Global, ptr_MyNumImplementedCores);
        while (this->ptr_Control_Of_WriteEnable == NULL) { /* wait untill created */ }
    }

    void WriteEnable::write_End(
        class Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
        unsigned char* ptr_coreId,
        unsigned char* ptr_MyNumImplementedCores,
        class FLORENCE::Global* ptr_Global
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
            ptr_MyNumImplementedCores
        );
        ptr_Control_Of_WriteEnable->writeEnable_SortQue(
            ptr_MyNumImplementedCores,
            ptr_Global
        );
        ptr_Control_Of_WriteEnable->setFlag_readWrite_Open(false);
    }
    void WriteEnable::write_Start(
        class Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
        unsigned char* ptr_coreId,
        unsigned char* ptr_MyNumImplementedCores,
        class FLORENCE::Global* ptr_Global
    )
    {
        ptr_Control_Of_WriteEnable->writeEnable_Request(
            ptr_coreId,
            ptr_MyNumImplementedCores,
            ptr_Global
        );
        ptr_Control_Of_WriteEnable->writeQue_Update(
            ptr_MyNumImplementedCores
        );
        ptr_Control_Of_WriteEnable->writeEnable_SortQue(
            ptr_MyNumImplementedCores,
            ptr_Global
        );
        ptr_Control_Of_WriteEnable->writeEnable_Activate(
            ptr_coreId,
            ptr_Global,
            ptr_MyNumImplementedCores
        );
    }

    class Control_Of_WriteEnable* WriteEnable::get_Control_Of_WriteEnable()
    {
        return this->ptr_Control_Of_WriteEnable;
    }
}