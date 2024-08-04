#include "Control_Of_Concurrent.h"

FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ConcurrentSpace::Control_Of_Concurrent::Control_Of_Concurrent()
{

}
FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ConcurrentSpace::Control_Of_Concurrent::~Control_Of_Concurrent()
{

}

void FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ConcurrentSpace::Control_Of_Concurrent::selectSet_Algorithm_Subset_For_Given_PraiseEventId(
	int* ptr_praiseEventId,
	class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent* ptr_Concurrent
)
{
	switch (*ptr_praiseEventId)
	{
		//===
		//===	
	case 0:
		ptr_Concurrent->set_Algorithm_Subset(new class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm());
		break;

	case 1:
		//TODO for each praise
		break;
		//===
		//===	
	}
}