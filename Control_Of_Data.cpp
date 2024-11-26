#include "Control_Of_Data.h"

namespace FLORENCE
{
    bool Control_Of_Data::flag_InputStackLoaded = false;
    bool Control_Of_Data::flag_OutputStackLoaded = false;

    Control_Of_Data::Control_Of_Data()
    {
        flag_InputStackLoaded = bool(false);
        flag_OutputStackLoaded = bool(false);
    }
    Control_Of_Data::~Control_Of_Data()
    {

    }

    void Control_Of_Data::Load_Input_Subset_For_PraiseEventId(int* ptr_praiseEventId)
    {
        switch (*ptr_praiseEventId)
        {
        case 0:

            break;

        }
    }

    void FLORENCE::Control_Of_Data::PopFromStackOfInputPraises(
        class FLORENCE::Input* referenceForCore,
        std::vector<class FLORENCE::Input*>* ptr_inputStack
    )
    {
        referenceForCore = ptr_inputStack->at(0);
        referenceForCore->SetPraiseEventId(*ptr_inputStack->at(1)->GetPraiseEventId());
        referenceForCore->Set_InputBuffer_SubSet(ptr_inputStack->at(1)->Get_InputBufferSubset());
        ptr_inputStack->erase(ptr_inputStack->begin() + 1);
    }

    void Control_Of_Data::PopFromStackOfOutput(
        class FLORENCE::Output* distributeBuffer,
        std::vector<class FLORENCE::Output*>* ptr_outputStack
    )
    {
        distributeBuffer->SetPraiseEventId(*ptr_outputStack->at(1)->GetPraiseEventId());
        distributeBuffer->Set_OutputBuffer_Subset(ptr_outputStack->at(1)->Get_OutputBuffer_Subset());
        ptr_outputStack->erase(ptr_outputStack->begin() + 1);
    }

    void Control_Of_Data::PushToStackOfInputPraises(
        std::vector<class FLORENCE::Input*>* ptr_InputStack,
        class FLORENCE::Input* ptr_PraiseBuffer
    )
    {
        ptr_InputStack->push_back(ptr_InputStack->at(0));
        ptr_InputStack->at((ptr_InputStack->size() - 1))->SetPraiseEventId(
            *ptr_PraiseBuffer->GetPraiseEventId()
        );
        ptr_InputStack->at((ptr_InputStack->size() - 1))->Set_InputBuffer_SubSet(
            ptr_PraiseBuffer->Get_InputBufferSubset()
        );
    }

    void Control_Of_Data::PushToStackOfOutput(
        std::vector<class FLORENCE::Output*>* ptr_outputStack,
        class FLORENCE::Output* ptr_referenceForCore
    )
    {
        ptr_outputStack->push_back(ptr_outputStack->at(0));
        ptr_outputStack->at((ptr_outputStack->size() - 1))->SetPraiseEventId(
            *ptr_referenceForCore->GetPraiseEventId()
        );
        ptr_outputStack->at((ptr_outputStack->size() - 1))->Set_OutputBuffer_Subset(
            ptr_referenceForCore->Get_OutputBuffer_Subset()
        );
    }

    bool Control_Of_Data::GetFlag_InputStackLoaded()
    {
        return flag_InputStackLoaded;
    }
    bool Control_Of_Data::GetFlag_OutputStackLoaded()
    {
        return flag_OutputStackLoaded;
    }


    void Control_Of_Data::SetFlag_InputStackLoaded(bool value)
    {
        flag_InputStackLoaded = value;
    }
    void Control_Of_Data::SetFlag_OutputStackLoaded(bool value)
    {
        flag_OutputStackLoaded = value;
    }
}