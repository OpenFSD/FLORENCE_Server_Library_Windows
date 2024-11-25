// FLORENCE_Server_Windows_Lib.cpp : Defines the functions for the static library.
//
#include "pch.h"
#include "framework.h"

namespace FLORENCE
{
	// TODO: This is an example of a library function
	static void CreateServer()
	{
		FLORENCE::framework* ptr_framework = new FLORENCE::framework();
		while (ptr_framework == NULL) { /* wait untill created */ }
	}
}