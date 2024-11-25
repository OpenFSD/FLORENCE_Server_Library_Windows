#include "pch.h"
#include <cstddef>

namespace FLORENCE
{
    class Control_Of_Data* ptr_Control_Of_Data = NULL;
    class Input* ptr_PraiseBuffer = NULL;
    class Output* ptr_DistributeBuffer = NULL;
    class Input* ptr_InputRefferenceOfCore[3] = { NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
    class Input** ptr_InputRefferenceOfCore_Array = NULL;
    class Input* ptr_new_Input = NULL;
    class Output* ptr_new_Output = NULL;
    class Output* ptr_OutputRefferenceOfCore[3] = { NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
    class Output** ptr_OutputRefferenceOfCore_Array = NULL;
    std::vector<class Input*>* ptr_StackOfInputPraise = NULL;
    std::vector<class Output*>* ptr_StackOfDistributeBuffer = NULL;
//===
//===
    class Praise0_Input* prt_Praise0_Input = NULL;
    class Praise0_Output* prt_Praise0_Outut = NULL;
//===
//===

    Data::Data(unsigned char* ptr_NumberOfImplementedCores)
    {
        this->ptr_new_Input = new Input();
        while (this->ptr_new_Input == NULL) { /* wait untill created */ }
        this->ptr_new_Input->Initialise_Control();

        this->ptr_new_Output = new Output();
        while (this->ptr_new_Output == NULL) { /* wait untill created */ }
        this->ptr_new_Output->Initialise_Control();

        this->ptr_DistributeBuffer = this->ptr_new_Output;
        while (this->ptr_DistributeBuffer == NULL) { /* wait untill created */ }

        class Input* ptr_InputRefferenceOfCore[3] = {
            this->ptr_new_Input,
            this->ptr_new_Input,
            this->ptr_new_Input
        };//NUMBER OF CONCURRENT CORES
        for (int index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
        {
            while (this->ptr_InputRefferenceOfCore[index] == NULL) { /* wait untill created */ }
        }

        this->ptr_InputRefferenceOfCore_Array = this->ptr_InputRefferenceOfCore;
        while (this->ptr_InputRefferenceOfCore_Array == NULL) { /* wait untill created */ }

        class Output* ptr_OutputRefferenceOfCore[3] = {
            this->ptr_new_Output,
            this->ptr_new_Output,
            this->ptr_new_Output
        };//NUMBER OF CONCURRENT CORES
        for (int index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
        {
            while (this->ptr_OutputRefferenceOfCore[index] == NULL) { /* wait untill created */ }
        }

        this->ptr_OutputRefferenceOfCore_Array = this->ptr_OutputRefferenceOfCore;
        while (this->ptr_OutputRefferenceOfCore_Array == NULL) { /* wait untill created */ }

        this->ptr_StackOfInputPraise = new std::vector<class Input*>;
        while (this->ptr_StackOfInputPraise == NULL) { /* wait untill created */ }
        this->ptr_StackOfInputPraise->resize(1);
        this->ptr_StackOfInputPraise->at(0) = this->ptr_new_Input;

        this->ptr_StackOfDistributeBuffer = new std::vector<class Output*>;
        while (this->ptr_StackOfDistributeBuffer == NULL) { /* wait untill created */ }
        this->ptr_StackOfDistributeBuffer->resize(1);
        this->ptr_StackOfDistributeBuffer->at(0) = this->ptr_new_Output;

        this->ptr_PraiseBuffer = this->ptr_new_Input;
        while (this->ptr_PraiseBuffer == NULL) { /* wait untill created */ }

        //===
        //===
        this->prt_Praise0_Input = new Praise0_Input();
        while (this->prt_Praise0_Input == NULL) { /* wait untill created */ }
        this->prt_Praise0_Outut = new Praise0_Output();
        while (this->prt_Praise0_Outut == NULL) { /* wait untill created */ }
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
        this->ptr_Control_Of_Data = new Control_Of_Data();
        while (this->ptr_Control_Of_Data == NULL) { /* wait untill created */ }
    }

    class Control_Of_Data* Data::Get_Control_Of_Data()
    {
        return this->ptr_Control_Of_Data;
    }

    class Output* Data::Get_DistributeBuffer()
    {
        return this->ptr_DistributeBuffer;
    }

    class Input* Data::Get_InputRefferenceOfCore(unsigned char concurrent_coreId)
    {
        return this->ptr_InputRefferenceOfCore_Array[concurrent_coreId];
    }

    class Output* Data::Get_OutputRefferenceOfCore(unsigned char concurrent_coreId)
    {
        return this->ptr_OutputRefferenceOfCore_Array[concurrent_coreId];
    }

    std::vector<class Input*>* Data::Get_StackOfInputPraise()
    {
        return this->ptr_StackOfInputPraise;
    }

    std::vector<class Output*>* Data::Get_StackOfDistributeBuffer()
    {
        return this->ptr_StackOfDistributeBuffer;
    }

    class Input* Data::Get_PraiseBuffer()
    {
        return this->ptr_PraiseBuffer;
    }

    void Data::Set_DistributeBuffer(Output* value_Output)
    {
        this->ptr_DistributeBuffer = value_Output;
    }

    void Data::Set_InputRefferenceOfCore(unsigned char concurrent_coreId, Input* value_Input)
    {
        this->ptr_InputRefferenceOfCore_Array[concurrent_coreId] = value_Input;
    }

    void Data::Set_OutputRefferenceOfCore(unsigned char concurrent_coreId, Output* value_Output)
    {
        this->ptr_OutputRefferenceOfCore_Array[concurrent_coreId] = value_Output;
    }

    void Data::Set_PraiseBuffer(Input* value_Input)
    {
        this->ptr_PraiseBuffer = value_Input;
    }
}