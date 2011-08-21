#include <iostream>
#include <cstdio>
using namespace std;
struct seg_tree{
	int left, right;
	long long data;
	long long add;
	bool iscover;
}t[400010];
inline int LL(int n)
{
	return  n << 1;
}
inline int RR(int n)
{
	return n << 1 | 1;
}
void make_tree(int left, int right, int id)
{
	t[id].left = left;
	t[id].right = right;
	t[id].data = 0;
	t[id].add = 0;
	t[id].iscover = true;
	if (left == right)return ;
	int mid = (left + right) >> 1;
	make_tree(left, mid, LL(id));
	make_tree(mid + 1, right, RR(id));
}
void insert(int left, int right, long long data, int id)
{
	if (left <= t[id].left && right >= t[id].right)
	{
		t[id].data += data * (t[id].right - t[id].left + 1);
		t[id].add += data;
		t[id].iscover = true;
		return ;
	}
	if (t[id].iscover)
	{
		t[LL(id)].data += t[id].add * (t[LL(id)].right - t[LL(id)].left + 1);
		t[RR(id)].data += t[id].add * (t[RR(id)].right - t[RR(id)].left + 1);
		t[LL(id)].iscover = t[RR(id)].iscover = true;
		t[LL(id)].add +=t[id].add;
		t[RR(id)].add += t[id].add;
		t[id].iscover = false;
		t[id].add = 0;
	}
	int mid = (t[id].left + t[id].right) >> 1;
	if (left <= mid)
		insert(left, right, data, LL(id));
	if (right > mid)
		insert(left, right, data, RR(id));
	t[id].data = t[LL(id)].data + t[RR(id)].data;
}
long long find(int left, int right, int id)
{
	if (left == t[id].left && right == t[id].right)
	{
		return t[id].data;
	}
	if (t[id].iscover)
	{
		t[LL(id)].data += t[id].add * (t[LL(id)].right - t[LL(id)].left + 1);
		t[RR(id)].data += t[id].add * (t[RR(id)].right - t[RR(id)].left + 1);
		t[LL(id)].iscover = t[RR(id)].iscover = true;
		t[id].iscover = false;
		t[LL(id)].add += t[id].add;
		t[RR(id)].add += t[id].add;
		t[id].add = 0;
	}
	int mid = (t[id].left + t[id].right) >> 1;
	if (right <= mid)
		return find(left, right, LL(id));
	if (left > mid)
		return find(left, right, RR(id));
	return find(left, mid, LL(id)) + find(mid + 1, right, RR(id));
}

int main()
{
	int N, Q;
	while (scanf("%d %d", &N, &Q) != EOF)
	{
		make_tree(1, N, 1);
		for (int i = 0; i < N; ++ i)
		{
			int temp;
			scanf("%d", &temp);
			insert(i + 1, i + 1, temp, 1);
		}
		while (Q--)
		{
			char s[10];
			scanf("%s", s);
	
			if (s[0] == 'Q')	
			{
				int temp1, temp2;
				scanf("%d %d", &temp1, &temp2);
				printf("%lld\n", find(temp1,temp2, 1));
			}
			else if (s[0] == 'C')
			{
				int temp1, temp2, temp3;
				scanf("%d %d %d", &temp1, &temp2, &temp3);
				insert(temp1, temp2, temp3, 1);
			
			
			}
		
		}
	
	}

	return 0;
}
