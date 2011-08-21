#include <iostream>
#include <math.h>
using namespace std;
int power(int a, int b)
{
	int base = 1;
	for (int i = 0; i < b; i++)
	{
		base *= a;
	}
	return base;
}
int main()
{
	int n;


	while (cin >> n && n)
	{
		int x, N;
		x = N = -1;
		for (int i = 2; ; i++ )
		{
			int a = pow(n, 1.0 / i) + 1e-8;
			if (a == n)
			{
				x = a;	
				N = i;
				break;
			}
		
			if (a == 1)
			{
				break;
			}
		
		}
	
		if (x != -1 && N != -1 && n != 1)
		{
			cout << x << " " << N << endl;
		}
		else 
		{
			cout << "0 0" << endl;
		}
	
	
	
	
	}




	return 0;
}
