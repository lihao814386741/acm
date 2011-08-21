#include <iostream>
#include <cstdio>
using namespace std;
template <int max_size>
struct u_set{
	struct tree{
		int father;
		int relation;
	}tr[max_size];
	void init(int size)
	{
		for (int i = 1; i <= size; ++ i)
			tr[i].father = i, tr[i].relation = 0;
	}
	int find(int x)
	{
		int temp = tr[x].father;
		if (x == tr[x].father)
			return x;

		tr[x].father = find(tr[x].father);
		tr[x].relation = (tr[x].relation + tr[temp].relation) % 2;
		
		return tr[x].father;
	}
	void merge(int temp1, int temp2) 
	{
		int a = find(temp1);
		int b = find(temp2);
		tr[a].father = b;
		tr[a].relation = (tr[temp1].relation + tr[temp2].relation + 1) % 2;
	}
};
u_set<100010> t;


int main()
{
	int test_case;
	cin >> test_case;
	while (test_case --)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		t.init(n);
		for (int i = 0; i < m; ++ i)
		{
			char s[10];
			int temp1, temp2;
			scanf("%s %d %d", s, &temp1, &temp2);
			if (s[0] == 'A')
			{
				int a = t.find(temp1), b = t.find(temp2);
				if (a != b)
				{
					printf("Not sure yet.\n");
				}
				else
				{
					if ((t.tr[temp1].relation + t.tr[temp2].relation) % 2 != 0 )
					{
						printf("In different gangs.\n");
					}
					else 
					{
						printf("In the same gang.\n");
					}
				}
			}
			else if (s[0] == 'D') 
			{
				t.merge(temp1, temp2);
			}
		}
	
	
	
	
	
	}
	









	return 0;
}
