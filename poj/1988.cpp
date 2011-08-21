#include <iostream>
#include <cstdio>
using namespace std;

template <int max_size>
struct u_set{
	struct tree{
		int father;
		int data;
		int dis;
	}tr[max_size];
	int size;	
	void init(int n)
	{
		size = n;
		for (int i = 1; i <= n; ++ i)
			tr[i].father = i, tr[i].data = 1, tr[i].dis = 0;
	}
	int find(int x)
	{
		int temp = tr[x].father;
		if (x == tr[x].father) 
		{
			return x;
		}
		tr[x].father = find(tr[x].father);
		tr[x].dis += tr[temp].dis;
		return find(tr[x].father);
	}
	void merge(int temp1, int temp2)
	{
		int a = find(temp1);
		int b = find(temp2);
		
		tr[b].father = a;
		tr[b].dis = tr[a].data;
		tr[a].data += tr[b].data;

	}

	int ask(int x)
	{
		return tr[find(x)].data - 1 - tr[x].dis;
	}
};
u_set<30010> t;
int main()
{
	int o;
	while (scanf("%d", &o) != EOF)
	{
		t.init(30010);
		while (o--)
		{
			char s[10];
			scanf("%s", s);
			if (s[0] == 'M')
			{
				int temp1, temp2;
				scanf("%d %d", &temp1, &temp2);
				t.merge(temp1, temp2);
			}
			if (s[0] == 'C')
			{
				int temp1;
				scanf("%d", &temp1);
				printf("%d\n", t.ask(temp1));
//				cout << t.tr[t.find(temp1)].data << endl;
//				cout << "dis" << t.tr[temp1].dis << endl;
			}

		}
	
	
	
	
	}






	return 0;
}
