#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "Server.h"

namespace FLORENCE
{
    class framework
    {
    public:
        framework();
        virtual ~framework();
        static FLORENCE::Server* Get_Server();

    protected:

    private:
        static class FLORENCE::Server* ptr_Server;
    };
}