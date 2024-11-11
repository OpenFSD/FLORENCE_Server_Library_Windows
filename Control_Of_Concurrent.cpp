#include "pch.h"
#include "Control_Of_Concurrent.h"
#include <cstddef>

namespace FLORENCE
{

	Control_Of_Concurrent::Control_Of_Concurrent()
	{

	}
	Control_Of_Concurrent::~Control_Of_Concurrent()
	{

	}

	void Control_Of_Concurrent::SelectSet_Algorithm_Subset_For_Given_PraiseEventId(
		int* ptr_praiseEventId,
		unsigned char concurrent_coreId
	)
	{
		FLORENCE::Server* server = FLORENCE::framework::Get_Server();
		switch (*ptr_praiseEventId)
		{
//===
//===	
		case 0:
			server->Get_Algorithms()->Get_Concurren_Array(concurrent_coreId)->Set_Algorithm_Subset(new FLORENCE::Praise0_Algorithm());
			break;

		case 1:
			//TODO for each praise
			break;
//===
//===	
		}
	}
}