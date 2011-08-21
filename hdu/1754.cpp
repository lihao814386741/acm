#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct seg_tree{
	int left, right, data, max;
}t[600010];
inline int  LL(int n)
{
	return n << 1;
}
inline int  RR(int n)
{
	return (n << 1) | 1;
}
void  make_tree(int left, int right, int id)
{
	t[id].left = left;
	t[id].right = right;
	t[id].max = 0;
	if (left == right)
	{
		t[id].data = 0;
		return ;
	}
	int mid = (left + right) / 2;
	make_tree(left, mid, LL(id));
	make_tree(mid + 1, right, RR(id));
}
void insert(int pos, int data, int id)
{
	t[id].max = t[id].max > data ? t[id].max : data;
	if (t[id].left == t[id].right)
	{
		t[id].data = data;
		return ;
	}
	int mid = (t[id].left + t[id].right) / 2;

	if (pos <= mid)
		insert(pos, data, LL(id));
	else 
		insert(pos, data, RR(id));
}
int find(int left, int right, int id)
{
	if (t[id].left == left && t[id].right == right)
		return t[id].max;
	int mid = (t[id].left + t[id].right) / 2;
	if (right <= mid)
		return find(left, right, LL(id));
	if (left > mid)
		return find(left, right, RR(id));
	int a = find(left, mid, LL(id));
	int b = find(mid + 1, right, RR(id));
	return a > b ? a : b;

}

int main()
{
	int N, M;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		memset(t, 0,sizeof(t));
		make_tree(0, N, 1);
		for (int i = 0; i < N; ++ i)
		{
				int temp;
				scanf("%d", &temp);
				insert(i + 1, temp, 1);
		}
		for (int i = 0; i < M; ++ i)
		{
			char a[4];
			int temp1, temp2;

			scanf("%s %d %d", a, &temp1, &temp2);
			string str(a);
			if (str == "Q")
			{
				printf("%d\n", find(temp1, temp2, 1));
			}
			else if (str == "U")
			{
				insert(temp1, temp2, 1);
			}
		}



	}


	return 0;
}
