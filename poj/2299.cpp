#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
int c[500010];
inline int lowbit(int n)
{
	return n & (-n);
}

void insert(int pos, int max)
{
	while (pos < max)
	{
		++ c[pos];
		pos += lowbit(pos);
	}

}
int find(int pos)
{
	int sum = 0;
	while (pos > 0)
	{
		sum += c[pos];
		pos -= lowbit(pos);
	}
	return sum;
}
struct digit{
	int num;
	int id;
}t[500010];
bool cmp(digit a, digit b)
{
	return a.num < b.num;
}
int num[500010];
int main()
{
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i <= n; ++ i)
			c[i] = 0;
		long long count = 0;
		for (int i = 0; i < n; ++ i)
		{
			scanf("%d", &t[i].num);
			t[i].id = i;
		//	count += i - find(temp + 1);
		//	insert(temp + 1, n);
		}
		sort(t, t + n, cmp);

		for (int i = 0; i < n; ++ i)
		{ 
			num[t[i].id] = i + 1;
		}

		for (int i = 0; i < n; ++ i)
		{
			count += i - find(num[i]);
			insert(num[i], n + 1);
		}
	
	
		printf("%lld\n", count);
	
	
	}




}

