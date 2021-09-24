#include <iostream>
#include "util.h"
using namespace std;

namespace sdds
{

	bool confirm()
	{
		char choice = cin.get();
		clearBuffer();
		return choice == 'Y';
	}

	void clearBuffer()
	{
		while (cin.get() != '\n');
	}
}