#include <iostream>
#include <cmath>
#define ANS_NUM 10020
#define PRIME_NUM 65537
using namespace std;
int ans[ANS_NUM];
int  prime[PRIME_NUM];
void init()
{
	int x = 1;
	prime[0] = 2;
	for (int i = 3; i < PRIME_NUM; i += 2)
	{
		bool isprime = true;
		for (int j = 0; j < x; j++)
		{
			if (i % prime[j] == 0)
			{
				isprime = false;
				break;
			}
		}
		if (isprime)
		{
			prime[x] = i;
			cout << prime[x] << endl;
			x ++ ;
		}
	
	}

}
int main()
{
	int x = 0;
	for (int i = 2; i < ANS_NUM; i++)
	{
		int a = i / 2;
		int sum = 0;
		for (int j = 1; j <= a; j++)
		{
			if (i % j == 0)
			{
				sum += j;
			}
		}
//		cout << sum << " " << i << " " << a << endl;
		if (sum == i)
		{
			ans[x] = i;
			x ++;
		}

	}
	int n;
	while (cin >> n)
	{
		cout << n << ":";
		for (int i = 0; i < x && ans[i] <= n; i ++) 
		{
			cout << " " << ans[i];	
		}
		cout << endl;
	
	
	
	}


	return 0;
}
