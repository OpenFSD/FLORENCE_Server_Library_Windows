#include "pch.h"
#include "Control_Of_Input.h"

namespace FLORENCE
{

	Control_Of_Input::Control_Of_Input()
	{

	}
	Control_Of_Input::~Control_Of_Input()
	{

	}

	void Control_Of_Input::selectSet_Input_Subset_For_Given_PraiseEventId(
		int* ptr_praiseEventId,
		FLORENCE::Server* ptr_Server
	)
	{
		switch (*ptr_praiseEventId)
		{
			//===
			//===
		case 0:
			ptr_Server->get_Data()->get_PraiseBuffer()->set_InputBuffer_SubSet(new class FLORENCE::Praise0_Input());
			break;

		case 1:

			break;
			//===
			//===

		}
	}
}