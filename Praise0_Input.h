#pragma once

namespace FLORENCE
{
	class Praise0_Input
	{
	public:
		Praise0_Input();
		virtual ~Praise0_Input();
		bool Get_A();
		bool Get_B();
		void Set_A(bool value);
		void Set_B(bool value);

	protected:

	private:
		static bool a;
		static bool b;
	};
}