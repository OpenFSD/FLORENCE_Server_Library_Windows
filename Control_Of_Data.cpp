#include "pch.h"
#include "Control_Of_Data.h"

namespace FLORENCE
{
    bool Control_Of_Data::flag_InputStackLoaded = false;
    bool Control_Of_Data::flag_OutputStackLoaded = false;

    Control_Of_Data::Control_Of_Data()
    {
        this->flag_InputStackLoaded = bool(false);
        this->flag_OutputStackLoaded = bool(false);
    }
    Control_Of_Data::~Control_Of_Data()
    {

    }

    void Control_Of_Data::load_Input_Subset_For_PraiseEventId(int* ptr_praiseEventId)
    {
        switch (*ptr_praiseEventId)
        {
        case 0:

            break;

        }
    }

    void Control_Of_Data::popFromStackOfInputPraises(
        FLORENCE::Input* referenceForCore,
        std::vector<FLORENCE::Input*>* ptr_inputStack
    )
    {
        referenceForCore = ptr_inputStack->at(0);
        referenceForCore->setPraiseEventId(*ptr_inputStack->at(1)->getPraiseEventId());
        referenceForCore->set_InputBuffer_SubSet(ptr_inputStack->at(1)->get_InputBufferSubset());
        ptr_inputStack->erase(ptr_inputStack->begin() + 1);
    }

    void Control_Of_Data::popFromStackOfOutput(
        FLORENCE::Output* distributeBuffer,
        std::vector<FLORENCE::Output*>* ptr_outputStack
    )
    {
        distributeBuffer->setPraiseEventId(*ptr_outputStack->at(1)->getPraiseEventId());
        distributeBuffer->set_OutputBuffer_Subset(ptr_outputStack->at(1)->get_OutputBuffer_Subset());
        ptr_outputStack->erase(ptr_outputStack->begin() + 1);
    }

    void Control_Of_Data::pushToStackOfInputPraises(
        std::vector<FLORENCE::Input*>* ptr_InputStack,
        FLORENCE::Input* ptr_PraiseBuffer
    )
    {
        ptr_InputStack->push_back(ptr_InputStack->at(0));
        ptr_InputStack->at((ptr_InputStack->size() - 1))->setPraiseEventId(
            *ptr_PraiseBuffer->getPraiseEventId()
        );
        ptr_InputStack->at((ptr_InputStack->size() - 1))->set_InputBuffer_SubSet(
            ptr_PraiseBuffer->get_InputBufferSubset()
        );
    }

    void Control_Of_Data::pushToStackOfOutput(
        std::vector<FLORENCE::Output*>* ptr_outputStack,
        FLORENCE::Output* ptr_referenceForCore
    )
    {
        ptr_outputStack->push_back(ptr_outputStack->at(0));
        ptr_outputStack->at((ptr_outputStack->size() - 1))->setPraiseEventId(
            *ptr_referenceForCore->getPraiseEventId()
        );
        ptr_outputStack->at((ptr_outputStack->size() - 1))->set_OutputBuffer_Subset(
            ptr_referenceForCore->get_OutputBuffer_Subset()
        );
    }

    bool Control_Of_Data::getFlag_InputStackLoaded()
    {
        return flag_InputStackLoaded;
    }
    bool Control_Of_Data::getFlag_OutputStackLoaded()
    {
        return this->flag_OutputStackLoaded;
    }


    void Control_Of_Data::setFlag_InputStackLoaded(bool value)
    {
        this->flag_InputStackLoaded = value;
    }
    void Control_Of_Data::setFlag_OutputStackLoaded(bool value)
    {
        this->flag_OutputStackLoaded = value;
    }
}