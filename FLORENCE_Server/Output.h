#pragma once
#include "Control_Of_Output.h"
#include "user_files/Praise0_Output.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace DataSpace
            {
                class Output
                {
                public:
                    Output();
                    virtual ~Output();
                    static void initialise_Control();
                    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output* get_Control_Of_Output();
                    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* get_OutputBuffer_Subset();//TODO CLASS T
                    int* getPraiseEventId();

                    void set_OutputBuffer_Subset(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* value);
                    void setPraiseEventId(int value);

                protected:

                private:
                    static class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output* ptr_Control_Of_Output;
                    static int* ptr_out_PraiseEventId;
                    static class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* praiseOutputBuffer_Subset;//ToDo buffer
                };
            }
        }
    }
}