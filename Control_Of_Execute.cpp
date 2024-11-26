#include "Control_Of_Execute.h"
#include <cstddef>

namespace FLORENCE
{
	bool Control_Of_Execute::flag_SystemInitialised = NULL;
	bool Control_Of_Execute::flag_ThreadInitialised[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES

	Control_Of_Execute::Control_Of_Execute(unsigned char* ptr_MyNumImplementedCores)
	{
		flag_SystemInitialised = bool(true);
		bool flag_ThreadInitialised[4] = { bool(true), bool(true), bool(true), bool(true) };//NUMBER OF CORES
		for (unsigned char index = 0; index < *ptr_MyNumImplementedCores; index++) {
			flag_ThreadInitialised[index] = new bool(true);
		}
	}
	
	Control_Of_Execute::~Control_Of_Execute()
	{

	}

	bool Control_Of_Execute::GetFlag_SystemInitialised(unsigned char* ptr_MyNumImplementedCores)
	{
		for (int index = 0; index < *ptr_MyNumImplementedCores; index++)
		{
			flag_SystemInitialised = false;
			if (flag_ThreadInitialised[index] == true)
			{
				flag_SystemInitialised = true;
			}
		}
		return flag_SystemInitialised;
	}

	bool Control_Of_Execute::GetFlag_ThreadInitialised(unsigned char coreId)
	{
		return flag_ThreadInitialised[coreId];
	}

	void Control_Of_Execute::SetConditionCodeOfThisThreadedCore(unsigned char coreId)
	{
		//Todo
		SetFlag_ThreadInitialised(coreId);
	}

	void Control_Of_Execute::SetFlag_ThreadInitialised(unsigned char coreId)
	{
		flag_ThreadInitialised[coreId] = false;
	}
}