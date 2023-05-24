#include <iostream>
#include "Manager.h"
#include "SavingsManager.h"
#include "FinancialManager.h"
#include "ExpenseManager.h"

int main()
{
	Manager& manager = Manager::getInstance();

	bool isRun = true;
	while ( isRun )
	{
		manager.Render();
		manager.Update( &isRun );
	}

	return 0;
}
