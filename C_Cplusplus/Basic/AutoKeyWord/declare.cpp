#include <iostream>
using namespace std;

int main()
{
// 'K' là kiểu char => cKteam kiểu char
	auto cKteam = 'K';
	cout << "type of cKteam: " << typeid(cKteam).name() << endl;

// 1 là kiểu int => nKteam kiểu int
	auto nKteam = 1;
	cout << "type of nKteam: " << typeid(nKteam).name() << endl;

	// 1.0F là kiểu float => fKteam kiểu float
	auto fKteam = 1.0F;
	cout << "type of fKteam: " << typeid(fKteam).name() << endl;

	// 1.0 là kiểu double => dKteam kiểu double
	auto dKteam = 1.0;
	cout << "type of dKteam: " << typeid(dKteam).name() << endl;

	return 0;
}
