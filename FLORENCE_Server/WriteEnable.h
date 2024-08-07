#pragma once
#include "Control_Of_WriteEnable.h"
#include "Global.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace ExecuteSpace
            {
                class WriteEnable
                {
                public:
                    WriteEnable();
                    virtual ~WriteEnable();
                    static void initialise_Control(
                        class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
                        unsigned char* ptr_MyNumImplementedCores
                    );
                    static void write_End(
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
                        unsigned char* ptr_coreId,
                        unsigned char* ptr_MyNumImplementedCores,
                        class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
                    );
                    static void write_Start(
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
                        unsigned char* ptr_coreId,
                        unsigned char* ptr_MyNumImplementedCores,
                        class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
                    );

                    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* get_Control_Of_WriteEnable();

                protected:

                private:
                    static class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable;
                };
            }
        }
    }
}