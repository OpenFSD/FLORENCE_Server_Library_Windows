// FLORENCE_Server_Windows_Lib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "Server.h"

// TODO: This is an example of a library function
void FLORENCE_CreateServer()
{
	static class Server* ptr_Server = new Server();
}
