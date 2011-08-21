#include <iostream>
using namespace std;
const int inf = 0x3fffffff;
template <int number>
struct Dij{
	int d[number][number];
	int shortpath[number];
	bool visit[number];

	struct Mi{
		int num;
		int id;
	}mi;
	void dijkstra(int size, int n)
	{
		for (int i = 1; i <= size; ++ i)
			shortpath[i] = inf, visit[i] = false;
		shortpath[n] = 0;
		int k = n;
		for (int i = 1; i <= size; ++ i)
		{
			mi.num = inf;
			visit[k] = true;
			for (int j = 1; j <= size; ++ j)
			{
				if (shortpath[j] > shortpath[k] + d[k][j])
					shortpath[j] = shortpath[k] + d[k][j];
				if (shortpath[j] < mi.num && !visit[j])
					mi.num = shortpath[j], mi.id = j;
			}
			k = mi.id;
		}
	}
};
Dij<1010> z;

int main()
{
	int t, n;
	while (cin >> t >> n)
	{
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				z.d[i][j] = inf;
		for (int i = 0; i < t; ++ i)
		{
			int temp1, temp2, temp3;
			cin >> temp1 >> temp2 >> temp3;
			if (z.d[temp1][temp2] > temp3)
				z.d[temp1][temp2] = z.d[temp2][temp1] = temp3;
		}
		z.dijkstra(n, 1);
		cout << z.shortpath[n] << endl;
	
	
	}



}
