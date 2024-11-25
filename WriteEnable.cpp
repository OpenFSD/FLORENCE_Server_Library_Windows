#include "pch.h"
#include <cstddef>

namespace FLORENCE
{
    Control_Of_WriteEnable* ptr_Control_Of_WriteEnable = NULL;

    WriteEnable::WriteEnable()
    {

    }

    WriteEnable::~WriteEnable()
    {
        delete this->ptr_Control_Of_WriteEnable;
    }

    void WriteEnable::Initialise_Control(
        FLORENCE::Global* ptr_Global,
        unsigned char* ptr_MyNumImplementedCores
    )
    {
        this->ptr_Control_Of_WriteEnable = new FLORENCE::Control_Of_WriteEnable(ptr_Global, ptr_MyNumImplementedCores);
        while (this->ptr_Control_Of_WriteEnable == NULL) { /* wait untill created */ }
    }

    void WriteEnable::Write_End(
        FLORENCE::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
        unsigned char* ptr_coreId,
        unsigned char* ptr_MyNumImplementedCores,
        FLORENCE::Global* ptr_Global
    )
    {
        for (unsigned char index = 0; index < 2; index++)
        {
            ptr_Control_Of_WriteEnable->SetFlag_writeState(ptr_coreId, index, ptr_Global->GetConst_Write_IDLE(index));
        }
        ptr_Control_Of_WriteEnable->Set_new_coreIdForWritePraiseIndex(*ptr_Control_Of_WriteEnable->Get_coreIdForWritePraiseIndex() + 1);
        if (int(*ptr_Control_Of_WriteEnable->Get_new_coreIdForWritePraiseIndex()) == 3)
        {
            ptr_Control_Of_WriteEnable->Set_new_coreIdForWritePraiseIndex(0);
        }
        ptr_Control_Of_WriteEnable->WriteQue_Update(
            ptr_MyNumImplementedCores
        );
        ptr_Control_Of_WriteEnable->WriteEnable_SortQue(
            ptr_MyNumImplementedCores,
            ptr_Global
        );
        ptr_Control_Of_WriteEnable->SetFlag_readWrite_Open(false);
    }
    void WriteEnable::Write_Start(
        Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
        unsigned char* ptr_coreId,
        unsigned char* ptr_MyNumImplementedCores,
        FLORENCE::Global* ptr_Global
    )
    {
        ptr_Control_Of_WriteEnable->WriteEnable_Request(
            ptr_coreId,
            ptr_MyNumImplementedCores,
            ptr_Global
        );
        ptr_Control_Of_WriteEnable->WriteQue_Update(
            ptr_MyNumImplementedCores
        );
        ptr_Control_Of_WriteEnable->WriteEnable_SortQue(
            ptr_MyNumImplementedCores,
            ptr_Global
        );
        ptr_Control_Of_WriteEnable->WriteEnable_Activate(
            ptr_coreId,
            ptr_Global,
            ptr_MyNumImplementedCores
        );
    }

    Control_Of_WriteEnable* WriteEnable::Get_Control_Of_WriteEnable()
    {
        return this->ptr_Control_Of_WriteEnable;
    }
}