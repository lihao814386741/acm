#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct seg_tree{
	int left, right, data;
}t[300010];
inline int LL(int n)
{
	return n << 1;
}
inline int RR(int n)
{
	return (n << 1) | 1;
}
void make_tree(int left, int right, int id)
{
	t[id].left = left;
	t[id].right = right;
	t[id].data = 1;
	if (t[id].left == t[id].right)
		return;
	int mid = (left + right) / 2;
	make_tree(left, mid, LL(id));
	make_tree(mid + 1, right, RR(id));
}
void insert(int left, int right, int data, int id)
{
	if (left <= t[id].left && right >= t[id].right)
	{
		t[id].data = data;
		return ;
	}
	if (t[id].data != -1)
	{
		t[LL(id)].data = t[RR(id)].data = t[id].data;
		t[id].data = -1;
	}
	int mid = (t[id].left + t[id].right) / 2;
	if (left <= mid)
		insert(left, right, data, LL(id));
	if (right > mid)
		insert(left, right, data, RR(id));
}
int find(int  left, int  right, int id)
{
	if (t[id].left == left && t[id].right == right)
	{
		if (t[id].data != -1)
		{
			return (right - left + 1) * t[id].data;
		}
		else 
		{
			int mid = (t[id].left + t[id].right) / 2;
			return find(left, mid, LL(id)) + find(mid + 1, right, RR(id));
		}
	}
	int mid2 = (t[id].left + t[id].right) / 2;
	if (right <= mid2)
		return find(left, right, LL(id));
	if (left > mid2)
		return find(left, right, RR(id));
	return find(left, mid2, LL(id)) + find(mid2 + 1, right, RR(id));
}
int main()
{
	int test_case;
	scanf("%d", &test_case);
	for (int o = 0; o < test_case; ++ o)
	{
		int N, Q;
		memset(t, 0, sizeof (t));
		scanf("%d %d", &N, &Q);
		make_tree(1, N, 1);
		for (int i = 0; i < Q; ++ i)
		{
			int temp1, temp2, temp3;
			scanf("%d %d %d", &temp1, &temp2, &temp3);
			insert(temp1, temp2, temp3, 1);
		}

		cout << "Case " << o + 1 << ": The total value of the hook is " << find(1, N, 1) << "." << endl;
	}
	return 0;

}
