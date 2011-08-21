#include <iostream>
#include <cstdio>
using namespace std;
template <int max_size>
struct u_set{
	struct tree{
		int father;
	}tr[max_size];
	void init(int size)
	{
		for (int i = 1; i <= size; ++ i)
			tr[i].father = i;
	}
	int find(int x)
	{
		if (x == tr[x].father)
			return x;
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
};
u_set<1010> t;
struct point{
	int x;
	int y;
	bool isrepaired;
}pos[1010];
int main()
{
	int n, d;
	scanf("%d %d", &n, &d);
	{
	t.init(n);
		for (int i = 1; i <= n; ++ i)
		{
			scanf("%d %d", &pos[i].x, &pos[i].y);
		}
		char s[10];
		while (~scanf("%s", s))
		{
			if (s[0] == 'O')
			{
				int temp1;
				scanf("%d", &temp1);
//				cout << temp1 << endl;
				pos[temp1].isrepaired = true;
				
				for (int i = 1; i <= n; ++ i)
				{
					if (pos[i].isrepaired  && (pos[i].x - pos[temp1].x) * (pos[i].x - pos[temp1].x) + (pos[i].y - pos[temp1].y) * (pos[i].y - pos[temp1].y) <= d * d)
					{
//						cout << i << endl;
						t.merge(i, temp1);
					}
				}
//				cout << endl;
			}
			else if (s[0] == 'S') 
			{
				int temp1, temp2;
				scanf("%d %d", &temp1, &temp2);
				int a = t.find(temp1);
				int b = t.find(temp2);
//				cout << " a";
//				cout << a << endl;
//				cout << b << endl;
				if (a == b)
				{
					printf("SUCCESS\n");
				}
				else
				{
					printf("FAIL\n");
				}
			}
		}

	
	}



	return 0;
}
