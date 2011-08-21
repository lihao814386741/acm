#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	while (cin >> n && n)
	{
		bool isoutput = false;
		for (int i = 2; i <= n; i ++)
		{
			int a = pow(n, 1.0 / i) + 1e-8;
			if ((int)(pow(a, i * 1.0) + 1e-8) == n)
			{
				cout << a << " " << i << endl;
				isoutput = true;
				break;
			}
		
		}
		if (!isoutput)
		{
			cout << "0 0" << endl;
		}
	
	
	}





	return 0;
}
