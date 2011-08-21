#include <iostream>
#include <cstdio>
using namespace std;

const int max_size = 30010;

struct u_set{
	struct tree{
		int father; }tr[max_size * 2];
	int size;
	void init()
	{
		int len = size * 2 + 2;
		for (int i = 0; i < len; ++ i)
			tr[i].father = i;
	}
	int find(int x)
	{
		if (x == tr[x].father)return x;
		tr[x].father = find(tr[x].father);
		return tr[x].father;
	}
	void merge(int temp1, int temp2)
	{
		int a = find(temp1);
		int b = find(temp2);
		if (a != b)
		{
			tr[a].father = b;
		}	
	}
	
}t;
int  main()
{
	int n, m;
	while (~scanf("%d %d", &n, &m))
	{
		if (!n && !m)break;
		t.size = n;
		t.init();
		
		for (int i = 0; i < m; ++ i)
		{
			int temp;
			scanf("%d", &temp);
			for (int j = 0; j < temp; ++ j)
			{
				int temp1;
				scanf("%d", &temp1);
				t.merge(temp1, n  + i + 1);
			}
		}
		int x = t.find(0);
		int  count = 0;
		for (int i = 0; i < n; ++ i)
		{
			if (x == t.find(i))
				++ count;
		}
		cout << count << endl;
	
	}




}
