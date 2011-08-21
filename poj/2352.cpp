#include <iostream>
#include <algorithm>
#include <cstdio>
#define NUM 32010
using namespace std;
int c[NUM];
int level[15010];
int lowbit(int pos);
int sum(int pos);
int addnum(int pos, int num);
int N;
int main()
{
	scanf("%d", &N);
	{
		for (int i = 0; i < N; i++)
		{
			int temp1, temp2;
			scanf("%d %d", &temp1, &temp2);
			temp1++;
			level[sum(temp1)] ++;
			addnum(temp1, 32010);
		}
		for (int i = 0; i < N; i ++)
		printf("%d\n", level[i]);



	}
	



	return 0;
}
int lowbit(int pos)
{
	return pos & (-pos);
}
int sum(int pos)
{
	int result = 0;
	while (pos > 0)
	{
		result += c[pos];
		pos -= lowbit(pos);
	}
	return result;
}
int addnum(int pos,  int num)
{
	while (pos < num)
	{
		++ c[pos];
		pos += lowbit(pos);
	}
	return 0;
}
