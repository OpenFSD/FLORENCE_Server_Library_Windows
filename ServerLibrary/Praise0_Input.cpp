#include "Praise0_Input.h"

namespace FLORENCE
{
	bool FLORENCE::Praise0_Input::a = false;
	bool FLORENCE::Praise0_Input::b = false;

	Praise0_Input::Praise0_Input()
	{
		a = bool(false);
		b = bool(false);
	}

	Praise0_Input::~Praise0_Input()
	{
	}

	bool Praise0_Input::Get_A()
	{
		return a;
	}

	bool Praise0_Input::Get_B()
	{
		return b;
	}

	void Praise0_Input::Set_A(bool value)
	{
		a = value;
	}

	void Praise0_Input::Set_B(bool value)
	{
		b = value;
	}
}