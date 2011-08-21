#include <iostream>
using namespace std;
#define prime_num 10010
int prime[prime_num + 5];
int c[prime_num];
int count = 0;
int lowbit(int n)
{
	return n & (-n);
}
void addnum(int pos, int num)
{
	while (pos < count) {
		c[pos] += num;
		pos += lowbit(pos);
	}
}
int getsum(int low, int high)
{
	int sum1, sum2;
	int temp = low;
	sum1 = sum2 = 0;

	while (low > 0)
	{
		sum1 += c[low];
		low -= lowbit(low);
	}
	while (high > 0)
	{
		sum2 += c[high];
		high -= lowbit(high);
	}
	return sum2 - sum1 + prime[temp];
}
int main()
{
	int n;
	count  = 1;
	prime[count ++] = 2;
	
	for (int i = 3; i <= prime_num; i += 2)
	{
	
		bool isprime = true;
		for (int j = 1; j < count; ++ j)
		{
			if (i % prime[j] == 0)
			{
				isprime = false;
				break;
			}
		}
		if (isprime)
			prime[count ++] = i;
	}
	prime[0] = 0; 
	for (int i = 1; i < count; ++ i)
	{
		addnum(i, prime[i]);
	}
	while (cin >> n && n)
	{
		int ans = 0;
		for (int i = 1; prime[i] <= n; ++ i)
		{
			for (int j = i; prime[j] <= n; ++ j)
			{
				int temp = getsum(i, j);
				if (temp == n)
				{
					ans ++;
				}
				else if (temp > n)
				{
					break;
				}
			}
		}
	
		cout << ans << endl;
	
	
	}
	return 0;
}
