#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	int temp1, temp2;
	int ansx, ansy;
	int len;
	int distance = 214748364;
	while (cin >> temp1 >> temp2)
	{
		if ((len = (temp1 - x) * (temp1 - x) + (temp2 - y) * (temp2 - y)) < distance) distance = len, ansx = temp1, ansy = temp2;
	}

	cout << ansx << " " << ansy << endl;




	return 0;
}
