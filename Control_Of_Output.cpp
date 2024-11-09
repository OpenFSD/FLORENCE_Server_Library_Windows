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
		FLORENCE::Server* ptr_Server,
		unsigned char concurrent_coreId
	)
	{
		switch (*ptr_praiseEventId)
		{
//===
//===
		case 0:
			ptr_Server->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Set_OutputBuffer_Subset(new class FLORENCE::Praise0_Output());
			break;

		case 1:

			break;
//===
//===
		}
	}
}