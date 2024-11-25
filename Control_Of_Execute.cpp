#include "pch.h"
#include <cstddef>

namespace FLORENCE
{
	bool flag_SystemInitialised = NULL;
	bool flag_ThreadInitialised[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES

	Control_Of_Execute::Control_Of_Execute(unsigned char* ptr_MyNumImplementedCores)
	{
		this->flag_SystemInitialised = bool(true);
		this->flag_ThreadInitialised[4] = new bool[4];
		for (unsigned char index = 0; index < *ptr_MyNumImplementedCores; index++) {
			this->flag_ThreadInitialised[index] = new bool(true);
		}
	}
	
	Control_Of_Execute::~Control_Of_Execute()
	{

	}

	bool Control_Of_Execute::GetFlag_SystemInitialised(unsigned char* ptr_MyNumImplementedCores)
	{
		for (int index = 0; index < *ptr_MyNumImplementedCores; index++)
		{
			this->flag_SystemInitialised = false;
			if (this->flag_ThreadInitialised[index] == true)
			{
				this->flag_SystemInitialised = true;
			}
		}
		return this->flag_SystemInitialised;
	}

	bool Control_Of_Execute::GetFlag_ThreadInitialised(unsigned char coreId)
	{
		return this->flag_ThreadInitialised[coreId];
	}

	void Control_Of_Execute::SetConditionCodeOfThisThreadedCore(unsigned char coreId)
	{
		//Todo
		SetFlag_ThreadInitialised(coreId);
	}

	void Control_Of_Execute::SetFlag_ThreadInitialised(unsigned char coreId)
	{
		this->flag_ThreadInitialised[coreId] = false;
	}
}