#pragma once
#include "Control_Of_Input.h"
#include "user_files/Praise0_Input.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace DataSpace
            {
                class Input
                {
                public:
                    Input();
                    virtual ~Input();
                    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input* get_Control_Of_Input();
                    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* get_InputBufferSubset();//TODO CLASS T
                    int* getPraiseEventId();

                    void set_InputBuffer_SubSet(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* value);//TODO CLASS T
                    void setPraiseEventId(int value);

                protected:

                private:
                    static class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input* ptr_Control_Of_Input;
                    static int* ptr_in_praiseEventId;
                    static class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_praiseInputBuffer_Subset;//TODO CLASS T
                };
            }
        }
    }
}