#include "Data.h"
#include <cstddef>

namespace FLORENCE
{
    class Control_Of_Data* Data::ptr_Control_Of_Data = NULL;
    class Input* Data::ptr_PraiseBuffer = NULL;
    class Output* Data::ptr_DistributeBuffer = NULL;
    class Input* Data::ptr_InputRefferenceOfCore[3] = { NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
    class Input** Data::ptr_InputRefferenceOfCore_Array = NULL;
    class Input* Data::ptr_new_Input = NULL;
    class Output* Data::ptr_new_Output = NULL;
    class Output* Data::ptr_OutputRefferenceOfCore[3] = { NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
    class Output** Data::ptr_OutputRefferenceOfCore_Array = NULL;
    std::vector<class FLORENCE::Input*>* Data::ptr_StackOfInputPraise = NULL;
    std::vector<class FLORENCE::Output*>* Data::ptr_StackOfDistributeBuffer = NULL;
//===
//===
    class Praise0_Input* Data::prt_Praise0_Input = NULL;
    class Praise0_Output* Data::prt_Praise0_Outut = NULL;
//===
//===

    Data::Data(unsigned char* ptr_NumberOfImplementedCores)
    {
        ptr_new_Input = new class FLORENCE::Input();
        while (ptr_new_Input == NULL) { /* wait untill created */ }
        ptr_new_Input->Initialise_Control();

        ptr_new_Output = new class FLORENCE::Output();
        while (ptr_new_Output == NULL) { /* wait untill created */ }
        ptr_new_Output->Initialise_Control();

        ptr_DistributeBuffer = ptr_new_Output;
        while (ptr_DistributeBuffer == NULL) { /* wait untill created */ }

        class FLORENCE::Input* ptr_InputRefferenceOfCore[3] = {
            ptr_new_Input,
            ptr_new_Input,
            ptr_new_Input
        };//NUMBER OF CONCURRENT CORES
        for (int index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
        {
            while (ptr_InputRefferenceOfCore[index] == NULL) { /* wait untill created */ }
        }

        ptr_InputRefferenceOfCore_Array = ptr_InputRefferenceOfCore;
        while (ptr_InputRefferenceOfCore_Array == NULL) { /* wait untill created */ }

        class FLORENCE::Output* ptr_OutputRefferenceOfCore[3] = {
            ptr_new_Output,
            ptr_new_Output,
            ptr_new_Output
        };//NUMBER OF CONCURRENT CORES
        for (int index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
        {
            while (ptr_OutputRefferenceOfCore[index] == NULL) { /* wait untill created */ }
        }

        ptr_OutputRefferenceOfCore_Array = ptr_OutputRefferenceOfCore;
        while (ptr_OutputRefferenceOfCore_Array == NULL) { /* wait untill created */ }

        ptr_StackOfInputPraise = new std::vector<class FLORENCE::Input*>;
        while (ptr_StackOfInputPraise == NULL) { /* wait untill created */ }
        ptr_StackOfInputPraise->resize(1);
        ptr_StackOfInputPraise->at(0) = ptr_new_Input;

        ptr_StackOfDistributeBuffer = new std::vector<class FLORENCE::Output*>;
        while (ptr_StackOfDistributeBuffer == NULL) { /* wait untill created */ }
        ptr_StackOfDistributeBuffer->resize(1);
        ptr_StackOfDistributeBuffer->at(0) = ptr_new_Output;

        ptr_PraiseBuffer = ptr_new_Input;
        while (ptr_PraiseBuffer == NULL) { /* wait untill created */ }

//===
//===
        prt_Praise0_Input = new class FLORENCE::Praise0_Input();
        while (prt_Praise0_Input == NULL) { /* wait untill created */ }
        prt_Praise0_Outut = new class FLORENCE::Praise0_Output();
        while (prt_Praise0_Outut == NULL) { /* wait untill created */ }
//===
//===
        delete ptr_new_Input;
        delete ptr_new_Output;
    }

    Data::~Data()
    {
        delete ptr_Control_Of_Data;
        delete ptr_DistributeBuffer;
        for (int index = 0; index < 3; index++)
        {
            delete ptr_InputRefferenceOfCore[index];
            delete ptr_OutputRefferenceOfCore[index];
        }
        delete ptr_StackOfInputPraise;
        delete ptr_StackOfDistributeBuffer;
        delete ptr_PraiseBuffer;
    }

    void Data::Initialise_Control()
    {
        ptr_Control_Of_Data = new FLORENCE::Control_Of_Data();
        while (ptr_Control_Of_Data == NULL) { /* wait untill created */ }
    }

    class Control_Of_Data* Data::Get_Control_Of_Data()
    {
        return ptr_Control_Of_Data;
    }

    class Output* Data::Get_DistributeBuffer()
    {
        return ptr_DistributeBuffer;
    }

    class Input* Data::Get_InputRefferenceOfCore(unsigned char concurrent_coreId)
    {
        return ptr_InputRefferenceOfCore_Array[concurrent_coreId];
    }

    class Output* Data::Get_OutputRefferenceOfCore(unsigned char concurrent_coreId)
    {
        return ptr_OutputRefferenceOfCore_Array[concurrent_coreId];
    }

    std::vector<class FLORENCE::Input*>* Data::Get_StackOfInputPraise()
    {
        return ptr_StackOfInputPraise;
    }

    std::vector<class FLORENCE::Output*>* Data::Get_StackOfDistributeBuffer()
    {
        return ptr_StackOfDistributeBuffer;
    }

    class Input* Data::Get_PraiseBuffer()
    {
        return ptr_PraiseBuffer;
    }

    void Data::Set_DistributeBuffer(class FLORENCE::Output* value_Output)
    {
        ptr_DistributeBuffer = value_Output;
    }

    void Data::Set_InputRefferenceOfCore(unsigned char concurrent_coreId, class FLORENCE::Input* value_Input)
    {
        ptr_InputRefferenceOfCore_Array[concurrent_coreId] = value_Input;
    }

    void Data::Set_OutputRefferenceOfCore(unsigned char concurrent_coreId, class FLORENCE::Output* value_Output)
    {
        ptr_OutputRefferenceOfCore_Array[concurrent_coreId] = value_Output;
    }

    void Data::Set_PraiseBuffer(class FLORENCE::Input* value_Input)
    {
        ptr_PraiseBuffer = value_Input;
    }
}