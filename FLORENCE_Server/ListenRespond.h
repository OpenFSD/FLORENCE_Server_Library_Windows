#include "Control_Of_Execute.h"
#include "Control_Of_Data.h"
#include "Control_Of_LaunchConcurrency.h"
#include "Control_Of_ListenRespond.h"
#include "Control_Of_WriteEnable.h"
#include "Data.h"
#include "Global.h"
#include "Input.h"
#include "LaunchConcurrency.h"
#pragma once
#include "Output.h"
#include "user_files/Praise0_Input.h"
#include <vector>
#include "WriteEnable.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace AlgorithmsSpace
            {
                class ListenRespond
                {
                public:
                    ListenRespond();
                    virtual ~ListenRespond();
                    static void thread_IO_ListenDistribute(
                        unsigned char ptr_coreId,
                        unsigned char* ptr_MyNumImplementedCores,
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute* ptr_Control_Of_Execute,
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_Data* ptr_Control_Of_Data,
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
                        class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond* ptr_Control_Of_ListenRespond,
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
                        class FLORENCE::FrameworkSpace::ServerSpace::Data* ptr_Data,
                        class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
                        std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* ptr_InputStack,
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency* ptr_LaunchConcurrency,
                        std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* ptr_OutputStack,
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_PraiseBuffer,
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_PraiseBuffer_Subset,
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* ptr_WriteEnable
                    );

                    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond* get_Control_Of_ListenRespond();

                protected:

                private:
                    static class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond* ptr_Control_Of_ListenRespond;
                };
            }
        }
    }
}