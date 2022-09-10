#include <iostream>
#include "MathFunc.h"
using namespace std;

double mysqrt(double x)
{
	if (x <= 0)
	{
		return 0;
	}

	double result = x;
	int i;

	// do ten iterations
	for (i = 0; i < 10; ++i)
	{
		if (result <= 0)
		{
			result = 0.1;
		}
		double delta = x - (result * result);
		result = result + 0.5 * delta / result;
		cout << "Computing sqrt of " << x << " to be "
			<< result << endl;
	}

	return result;
}
