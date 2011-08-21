#include <iostream>
#include <cstring>
#include <bitset>
#include <cstdio>
using namespace std;

struct seg_tree{
	int left, right, data;
	bool iscover;
}t[300010];
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
	t[id].data = 1;
	t[id].iscover = true;
	if (left == right)return ;

	int  mid = (left + right) >> 1;
	make_tree(left, mid, LL(id));
	make_tree(mid + 1, right, RR(id));
}
void insert(int left, int right, int data, int id)
{
//	cout << t[id].left << " "  << t[id].right << endl;
	if (left <= t[id].left && right >= t[id].right)
	{
		t[id].iscover = true;
		t[id].data = data;
		return ;
	}
	if (t[id].iscover)
	{
		t[LL(id)].data = t[RR(id)].data = t[id].data;
		t[LL(id)].iscover = t[RR(id)].iscover = true;
		t[id].iscover = false;
	}
	int mid = (t[id].left + t[id].right) >> 1;

	if (left <= mid)	
		insert(left, right, data, LL(id));
	if (right > mid)
		insert(left, right, data, RR(id));
	t[id].data = t[LL(id)].data | t[RR(id)].data;
}
int find(int left, int right, int id)
{
	if (left == t[id].left && t[id].right == right)
		return t[id].data;
	if (t[id].iscover)
	{
		t[LL(id)].data = t[RR(id)].data = t[id].data;
		t[LL(id)].iscover = t[RR(id)].iscover = true;
		t[id].iscover = false;
	}
	int mid = (t[id].left + t[id].right) >> 1;
	if (right <= mid)
		return find(left, right, LL(id));
	if (left > mid)
		return find(left, right, RR(id));
	return find(left, mid, LL(id)) | find(mid + 1, right, RR(id));

}
int main()
{
	int L, T, O;
	
	while (scanf("%d %d %d", &L, &T, &O) != EOF)
	{
		char s[10];
		memset(t, 0, sizeof(t));
		make_tree(1, L, 1);
		for (int i = 0; i < O;  ++ i)
		{
			scanf("%s", s);
			if (s[0] == 'C')
			{
				int temp1, temp2, temp3;			
				int temp;
				scanf("%d %d %d", &temp1, &temp2, &temp3);
				if (temp2 < temp1)temp = temp1, temp1 = temp2, temp2 = temp;
				insert(temp1, temp2, 1 << (temp3 - 1), 1);
			}
			else if (s[0] == 'P')
			{
				int temp1, temp2;
				int temp;
				scanf("%d %d", &temp1, &temp2);
				if (temp2 < temp1)temp = temp1, temp1 = temp2, temp2 = temp;
				int data = find(temp1, temp2, 1);
				bitset<40> b(data);
				printf("%d\n", b.count());

			}

		
		
		
		}
	
	
	
	
	
	
	
	
	}

	return 0;

}
