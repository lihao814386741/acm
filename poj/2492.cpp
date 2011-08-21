#include <iostream>
#include <cstdio>
using namespace std;
const int max_size = 2010;
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
	void merge(int  temp1, int temp2)
	{
		int a = find(temp1);
		int b = find(temp2);
		tr[a].father = b;
		tr[a].relation = (tr[temp1].relation + tr[temp2].relation + 1) % 2;
	}
}t;
int main()
{
	int test_case;
	cin >> test_case;
	for (int z = 0; z < test_case; ++ z)
	{
		printf("Scenario #%d:\n", z + 1);
		bool iswrong = false;
		int n, m;
		scanf("%d %d", &n, &m);
		t.init(n);
		for (int i = 0; i < m; ++ i)
		{
			int temp1, temp2;
			scanf("%d %d", &temp1, &temp2);
			if (!iswrong)
			{
			int a = t.find(temp1), b = t.find(temp2);
			if (a != b)
			{
				t.merge(temp1, temp2);			
			}
			else
			{
				if ((t.tr[temp1].relation + t.tr[temp2].relation) % 2 == 0)
				{
					iswrong = true;
				}
			}
			}
		}
		if (iswrong)
		{
			printf("Suspicious bugs found!\n");
		}
		else
		{
			printf("No suspicious bugs found!\n");
		}
	
	
		printf("\n");	
	
	
	
	
	
	
	
	}








	return 0;
}


