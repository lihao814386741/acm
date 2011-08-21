#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

template <int N>
struct pointtree{
	int a[2 * N];
	int size;
	void clear(){memset(this, 0, sizeof(*this));}
	void add(int n)
	{
		int i = N + n;
		++ size;
		for ( ++a[i]; i > 1; i >>= 1)
		{
			if (~i & 1)
			{
				++ a[i / 2];
			}
		}
	}
	int cntls(int n)
	{
		int i = N + n;
		int c = 0;
		for ( ;i > 1; i >>= 1)
		{
			if (i & 1)
			{
				c += a[i / 2];
			}
		}
		return c;
	}
	int cntgt(int n)
	{
		return size - a[N + n] - cntls(n);
	}
	void del(int n)
	{
		if (!a[N + n])return ;
		 -- size;
		 for (--a[n]; n > 1; n >>= 1)
		 {
		 	if (~n & 1)
			{
				--a[n / 2];
			}
		 }
	
	
	}
	int operator[](int n)
	{
		int i =  1;
		while (i < N)
		{
			if (n < a[i])i *= 2;
			else n -= a[i], i = i * 2 + 1;
		}
		return  i - N;
	}
};
pointtree<8192> t;
int main()
{
	int n;
	int num[5010];
	while (scanf("%d",  &n) != EOF)
	{
		for (int i = 0; i < n; ++ i)
		{
			scanf("%d", num + i);
		}
		int min = 214748364;
		int count = 0;
		for (int i = 0; i < n; ++ i)
		{
			t.add(num[i]);
			count += t.cntgt(num[i]);
		}
		for (int i = 0; i < n; ++ i)
		{
			count -= t.cntls(num[i]);
			count += t.cntgt(num[i]);
			min = min < count ? min : count;
		}
		cout << min << endl;
		t.clear();
	
	}




	return 0;
}
