// FLORENCE_Server_Windows_Lib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "Server.h"

namespace FLORENCE
{
	// TODO: This is an example of a library function
	void CreateServer()
	{
		static class FLORENCE::Server* ptr_Server = new FLORENCE::Server();
		ptr_Server->Get_Execute()->initialise_Threads(ptr_Server);
	}
}