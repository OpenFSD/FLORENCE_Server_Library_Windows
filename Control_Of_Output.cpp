#include "pch.h"
#include "Control_Of_Output.h"


namespace FLORENCE
{
	Control_Of_Output::Control_Of_Output()
	{

	}
	Control_Of_Output::~Control_Of_Output()
	{

	}

	void Control_Of_Output::SelectSet_Output_Subset_For_Given_PraiseEventId(
		int* ptr_praiseEventId,
		unsigned char concurrent_coreId
	)
	{
		FLORENCE:Server* server = FLORENCE::framework::Get_Server();
		switch (*ptr_praiseEventId)
		{
//===
//===
		case 0:
			server->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Set_OutputBuffer_Subset(new class FLORENCE::Praise0_Output());
			break;

		case 1:

			break;
//===
//===
		}
	}
}