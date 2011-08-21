#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 0;
		int t = 0;
		int num[128];
		for (int i = 2; sum < n; ++ i)
		{
			num[t++] = i;
			sum += i;
		}
		if (sum == n)
		{

			cout << num[0];
			for (int i = 1; i < t; ++ i)
			{
				cout << " " << num[i];
			}
		}
		else
		{
			int k = 0;
			sum -= num[--t];
			for (int res = n - sum; res > 0; -- res)
				++num[t - 1 - (k ++) % t];
			cout << num[0];
			for (int i = 1; i < t; ++ i)
				cout << " " << num[i];
		}
		cout << endl;
	
	
	
	
	
	}

	return 0;

}
