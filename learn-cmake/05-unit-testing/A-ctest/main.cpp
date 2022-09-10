// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include "Config.h"

// Should we include the MathFunc header?
#ifdef USE_MYMATH
#include "MathFunc.h"
#endif

using namespace std;

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "Missing a number argument...!" << endl;
		return 1;
	}

	cout << argv[0] << " Version " << demo_ctest_VERSION_MAJOR << "."
		<< demo_ctest_VERSION_MINOR << endl;
	
	// convert input to double
	const double inputValue = stod(argv[1]);

	//which square root Function should we use?
#ifdef USE_MYMATH
	cout << "Using internal library" << endl;
	const double outputValue = mysqrt(inputValue);
#else
	cout << "Using external cmath library" << endl;
	const double outputValue = sqrt(inputValue);
#endif

	cout << "The square root of  " << inputValue << " is " << outputValue
		<< endl;

	return 0;
}
