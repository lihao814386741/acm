#include <iostream>
using namespace std;
struct seg_tree{
	int left, right, data;
}t[5005 * 3];

inline int LL(int n)
{
	return n << 1;
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
	if (left == right)
		return ;
	int mid = (left + right) / 2;
	make_tree(left, mid, LL(id));
	make_tree(mid + 1, right, RR(id));
}
void insert(int pos, int id)
{
	t[id].data ++;
	int mid = (t[id].left + t[id].right) / 2;
	if (t[id].left == t[id].right)
		return;
	if (pos <= mid)
		insert(pos, LL(id));
	else 
		insert(pos, RR(id));
}
int find(int left, int  right, int id)
{
	if (t[id].left == left && t[id].right == right)
	{
		return t[id].data;
	}
	int mid = (t[id].left + t[id].right) / 2;
	if (right <= mid)
		return find(left, right, LL(id));
	if (left > mid)
		return find(left, right, RR(id));
	return find(left, mid, LL(id)) + find(mid + 1, right, RR(id));
}

int main()
{
	int n;
	int val[5005];
	while (cin >> n)
	{
		int sum = 0;
		make_tree(0, n - 1, 1);
		for (int i = 0; i < n; ++ i)
		{
			cin >> val[i];
			sum += find(val[i], n - 1, 1);
			insert(val[i], 1);
		}
		int min = 214748364;
		for (int i = 0; i < n; ++ i)
		{
			sum = sum - val[i] + (n - val[i] - 1);
			min = min > sum ? sum : min;
		}
		cout << min << endl;
	
	
	}





	return 0;
}

