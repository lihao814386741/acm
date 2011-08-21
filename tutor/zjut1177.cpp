#include <iostream>
using namespace std;
int gcd(int x, int y)
{
	while (x != y)
	{
		if (x > y)
		{
			x = x - y;
		}
		else 
		{
			y = y - x;
		}
	}
	return x;
}

int main()
{
	int a, b;


	while (cin >> a >> b)
	{
		cout << gcd(a, b) << endl;
	
	
	}



	return 0;
}


