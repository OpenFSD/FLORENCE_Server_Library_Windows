#pragma once
#include "Output.h"
#include "user_files/Praise0_Output.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace DataSpace
            {
                namespace OutputSpace
                {
                    class Control_Of_Output
                    {
                    public:
                        Control_Of_Output();
                        virtual ~Control_Of_Output();
                        static void selectSet_Output_Subset_For_Given_PraiseEventId(
                            int* ptr_praiseEventId,
                            class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_Output
                        );

                    protected:

                    private:

                    };
                }
            }
        }
    }
}