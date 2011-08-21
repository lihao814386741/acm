#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n && n)
	{
		if (n % 3 == 0) cout << "EVEN" << endl;
		else cout << "ODD" << endl;
	}
	return 0;
}
