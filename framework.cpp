#include "framework.h"
#include <cstddef>

namespace FLORENCE
{
	class FLORENCE::Server* framework::ptr_Server = NULL;

	framework::framework()
	{
		ptr_Server = new class FLORENCE::Server();
		while (ptr_Server == NULL) { /* wait untill created */ }
		ptr_Server->Get_Execute()->Initialise();
		ptr_Server->Get_Execute()->Initialise_Threads();
	}

	framework::~framework()
	{

	}

	FLORENCE::Server* framework::Get_Server()
	{
		return ptr_Server;
	}

}