#include <iostream>
#include <cstdio>
using namespace std;
const int max_size = 50010;
bool alreadyhavenumber[max_size];
struct u_set{
	struct tree{
		int father;
	}tr[max_size];
	
	void init(int size)
	{
		for (int i = 1; i <= size; ++ i)
			tr[i].father = i, alreadyhavenumber[i] = false;

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
			tr[a].father = b;
	}

}t;
int main()
{
	int n, m;
	int flag = 0;
	while (~scanf("%d %d", &n, &m))
	{
		++ flag;
		if (n == 0 && m == 0)
			break;
		t.init(n);
		for (int i = 0; i < m; ++ i)
		{
			int temp1, temp2;
			scanf("%d %d", &temp1, &temp2);
			t.merge(temp1, temp2);
		}
		int count = 0;
		for (int i = 1; i <= n; ++ i)
		{
			int temp;
			if (!alreadyhavenumber[temp = t.find(i)])
			{
				++ count;
				alreadyhavenumber[temp] = true;
			}
		}
		cout << "Case " << flag << ": " << count << endl;

	
	
	
	
	
	}
		





	return 0;
}

