#include "pch.h"
#include "Control_Of_Concurrent.h"


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
		FLORENCE::Server* ptr_server,
		unsigned char concurrent_coreId
	)
	{
		switch (*ptr_praiseEventId)
		{
//===
//===	
		case 0:
			ptr_server->Get_Algorithms()->Get_Concurren_Array(concurrent_coreId)->Set_Algorithm_Subset(new FLORENCE::Praise0_Algorithm());
			break;

		case 1:
			//TODO for each praise
			break;
//===
//===	
		}
	}
}