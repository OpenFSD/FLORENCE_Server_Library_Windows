#include "Control_Of_Data.h"

using FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_DataSpace;

bool flag_InputStackLoaded = false;
bool flag_OutputStackLoaded = false;

Control_Of_Data()
{
    bool flag_InputStackLoaded = bool(false);
    bool flag_OutputStackLoaded = bool(false);
}
~Control_Of_Data()
{

}

void load_Input_Subset_For_PraiseEventId(int* ptr_praiseEventId)
{
    switch (*ptr_praiseEventId)
    {
    case 0:

        break;

    }
}
void popFromStackOfInputPraises(
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* referenceForCore,
    std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* ptr_inputStack
)
{
    referenceForCore = ptr_inputStack->at(0);
    referenceForCore->setPraiseEventId(*ptr_inputStack->at(1)->getPraiseEventId());
    referenceForCore->set_InputBuffer_SubSet(ptr_inputStack->at(1)->get_InputBufferSubset());
    ptr_inputStack->erase(ptr_inputStack->begin() + 1);
}
void popFromStackOfOutput(
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* distributeBuffer,
    std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* ptr_outputStack
)
{
    distributeBuffer->setPraiseEventId(*ptr_outputStack->at(1)->getPraiseEventId());
    distributeBuffer->set_OutputBuffer_Subset(ptr_outputStack->at(1)->get_OutputBuffer_Subset());
    ptr_outputStack->erase(ptr_outputStack->begin() + 1);
}
void pushToStackOfInputPraises(
    std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* ptr_InputStack,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_PraiseBuffer
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

void pushToStackOfOutput(
    std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* ptr_outputStack,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_referenceForCore
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

bool getFlag_InputStackLoaded()
{
    return flag_InputStackLoaded;
}
bool getFlag_OutputStackLoaded()
{
    return flag_OutputStackLoaded;
}


void setFlag_InputStackLoaded(bool value)
{
    flag_InputStackLoaded = value;
}
void setFlag_OutputStackLoaded(bool value)
{
    flag_OutputStackLoaded = value;
}


