#include "pch.h"

namespace FLORENCE
{
	bool praise0_Result = false;

	Praise0_Output::Praise0_Output()
	{
		this->praise0_Result = bool(false);
	}

	Praise0_Output::~Praise0_Output()
	{

	}

	bool Praise0_Output::GetResultForPraise_0()
	{
		return praise0_Result;
	}

	void Praise0_Output::SetResultForPraise_0(bool value)
	{
		praise0_Result = value;
	}
}