#include "pch.h"
#include <cstddef>
#include "framework.h"

namespace FLORENCE
{
	class FLORENCE::Server* ptr_Server = NULL;

	framework::framework()
	{
		this->ptr_Server = new FLORENCE::Server();
		while (this->ptr_Server == NULL) { /* wait untill created */ }
		this->ptr_Server->Get_Execute()->Initialise_Threads();
	}

	framework::~framework()
	{

	}

	FLORENCE::Server* framework::Get_Server()
	{
		return ptr_Server;
	}

}