#include <iostream>
#include <cstring>
using namespace std;
inline int LL(int n)
{
	return n << 1;
}
inline int RR(int n)
{
	return (n << 1) | 1;
}
struct seg_tree{
	int left, right, data;
}t[150000];
void make_tree(int left, int right, int id)
{
	t[id].left = left;
	t[id].right = right;
	
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
	t[id].data += data;
	if (t[id].left == t[id].right)
		return ;
	int mid = (t[id].left + t[id].right) / 2;
	if (pos <= mid)
		insert(pos, data, LL(id));
	else 
		insert(pos, data, RR(id));
}
int find(int left, int right, int id)
{
	if (left == t[id].left && right == t[id].right)
	{
		return t[id].data;
	}
	int mid = (t[id].left + t[id].right) / 2;
	
	if (right <= mid)
	{
		return find(left, right, LL(id));
	}
	else if (left > mid)
	{
		return find(left, right, RR(id));
	}
	else 
	{
		return find(left, mid, LL(id)) + find(mid + 1, right, RR(id));
	}
}
int main()
{
	int o;
	cin >> o;
	for (int z = 0; z < o; ++ z)
	{
	memset(t, 0, sizeof(t));
		cout << "Case " << z + 1 << ":" << endl;

		int number;
		cin >> number;
		make_tree(0, number, 1);
		for (int i = 0; i < number;  ++ i)
		{
			int temp;
			cin >> temp;
			insert(i + 1, temp, 1);
		}
	
		string str;
		while (cin >> str)
		{
			if (str == "End")
				break;
			if (str == "Query")
			{
				int temp1, temp2;
				cin >> temp1 >> temp2;
				cout << find(temp1, temp2, 1) << endl;
			}
			if (str == "Add")
			{
				int temp1, temp2;
				cin >> temp1 >> temp2;
				insert(temp1, temp2, 1);
			}
			if (str == "Sub")
			{
				int temp1, temp2;
				cin >> temp1 >> temp2;
				insert(temp1, -temp2, 1);
			}
		}
	
	
	
	
	}




	return 0;
}

