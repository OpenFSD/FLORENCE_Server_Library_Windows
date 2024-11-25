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
        static class Server* Get_Server();

    protected:

    private:
        static class Server* ptr_Server;
    };
}